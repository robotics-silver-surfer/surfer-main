#!/usr/bin/env python
import roslib; roslib.load_manifest('nerfgun')
import rospy
from hoverboard.msg import PWMRaw
from sensor_msgs.msg import Joy

class ballCollector: 
	"""
		Class that controls ball Collector Parameters 

	"""

	def __init__( self ): 
		"""
			Intialize the nodes and class variables
		"""
		
		self.servo = rospy.Publisher( 'hoverboard/PWMRaw', PWMRaw, latch=True )

		# Opening up nodes and such
		rospy.init_node('ballcollector')    

		self.servoControl = PWMRaw() 
		self.joy = Joy()

		rospy.Subscriber( "joy", Joy, self.__joy )

		self.shooterServoNumber = rospy.get_param("nerfgun/ShooterServoNumber") 
		self.triggerThresh = rospy.get_param("nerfgun/TriggerThresh") 
		

	def __joy( self, data ): 
		"""
			Tell to shoot if Right Trigger is past threshhold 
		"""

		if( data.axes[5] < self.triggerThresh ): 
			self.__fire_gun( True )
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
		if up_or_down: 
			servoPWM.pwm = rospy.get_param("nerfgun/ServoFireValue")
		else: 
			servoPWM.pwm = rospy.get_param("nerfgun/ServoReloadValue")
		
		#rospy.loginfo("Setting Servo at: " + str( servoPWM.pwm ) )	
		self.servo.publish( servoPWM ) 

		
if __name__ == '__main__':
	
	try:
		x = ballCollector()
		rospy.spin()

	except rospy.ROSInterruptException:
		pass



