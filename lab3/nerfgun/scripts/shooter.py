#!/usr/bin/env python
import roslib; roslib.load_manifest('nerfgun')
import rospy
from hoverboard.msg import PWMRaw
from sensor_msgs.msg import Joy
from Ref.msg import BotToRef, BotStatus

class shooter: 
	"""
		Class that controls ball Collector Parameters 

	"""

	def __init__( self ): 
		"""
			Intialize the nodes and class variables
		"""
		
		self.servo = rospy.Publisher( 'hoverboard/PWMRaw', PWMRaw, latch=True )
		self.firePub = rospy.Publisher( 'FromTeam', BotToRef )

		# Opening up nodes and such
		rospy.init_node('shooter')    

		self.servoControl = PWMRaw() 
		self.joy = Joy()

		rospy.Subscriber( "joy", Joy, self.__joy )
		rospy.Subscriber( "ToTeam", BotStatus, self.__refCallback )

		self.shooterServoNumber = rospy.get_param("nerfgun/ShooterServoNumber") 
		self.triggerThresh = rospy.get_param("nerfgun/TriggerThresh") 
		
		self.canFire = True #rospy.get_param("nerfgun/TestingGun")
		self.botID = 0
		self.shotCount = 0
		self.isShooting = False
		self.toRef = BotToRef()

	def __refCallback( self, data ):
		"""
			Obtain shot count
		"""
		self.shotCount = data.shotCount
		self.botID = data.botID

	def __joy( self, data ): 
		"""
			Tell to shoot if Right Trigger is past threshhold 
		"""

		if( data.axes[5] < self.triggerThresh ): 
			self.__fire_gun( True )
			self.toRef.botID = self.botID
			self.firePub.publish( self.toRef )

		else:
			self.__fire_gun( False ) 

	
	def __fire_gun( self, up_or_down ):
		"""
			Set the Servo value
		 		False - Neutral
				True - Fire	
		""" 
		
		servoPWM = PWMRaw()
		servoPWM.channel = self.shooterServoNumber
		if ( up_or_down or ( self.shotCount > 0 ) ): 
			servoPWM.pwm = rospy.get_param("nerfgun/ServoFireValue")
		else: 
			servoPWM.pwm = rospy.get_param("nerfgun/ServoReloadValue")
		
		#rospy.loginfo("Setting Servo at: " + str( servoPWM.pwm ) )
		self.__has_fired( up_or_down )
		self.servo.publish( servoPWM )


	def __has_fired( self, trigger_down ):
		"""
			Track number of shots and inform Ref node
		"""

		if( trigger_down ):
			#trying to shoot - not yet successful
			self.isShooting = True
		else:
			
			if( self.isShooting ):
				#trigger has been released - shot successful
				self.isShooting = False
				self.shotCount -= 1
			
				rospy.loginfo("WE FIRED")
				self.toRef.botID = self.botID
				self.firePub.publish( self.toRef )

if __name__ == '__main__':
	
	try:
		x = shooter()
		rospy.spin()

	except rospy.ROSInterruptException:
		pass



