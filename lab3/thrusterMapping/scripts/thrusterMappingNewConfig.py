#!/usr/bin/env python
import roslib; roslib.load_manifest('thrusterMapping')
import rospy
from math import sqrt, pow, atan2
from geometry_msgs.msg import Transform
from hovercraft.msg import *



SCALE = .5


class ThrusterMapper:
	def __init__(self):
		self.Thrustpub = rospy.Publisher('hovercraft/Thruster', Thruster)
		rospy.Subscriber("pidOutput", Transform, self.pidCallback)
		rospy.Subscriber("hovercraft/Gyro", Gyro, self.gyroCallback)
		self.rateTooFast = False;
		self.thruster = Thruster()
    
			
   
	def pidCallback(self, data):
		"""
			Used to control translational movement
		"""
		thruster = [0.0, 0.0, 0.0, 0.0, 0.0]

		# Thruster 1 3 - rotate CC
		# Thruster 2 4 - rotate CCW
		self.thruster.thruster1 = 0.0
		self.thruster.thruster2 = 0.0
		self.thruster.thruster3 = 0.0
		self.thruster.thruster4 = 0.0

		self.thruster.lift = data.translation.z

		mag = 0.0
		mag = sqrt( pow(data.translation.y,2) ) * SCALE
		# Check to make sure mag is positive 
		#if data.translation.y > 0.0: 
		#	thruster[1] = mag
		#	thruster[4] = mag
		#else:
			# going backward
		#	thruster[2] = mag
		#	thruster[3] = mag
			
		# Check to see if maximum spin has been reached
		if not self.rateTooFast:
			
			# If not moving forward or backward, just control turning thrusters
			if data.translation.y < 0.07 and data.translation.y > -0.07:

				# Turning CC
				if data.rotation.w < 0.0:
					thruster[2] += abs( -SCALE*data.rotation.w )
					thruster[4] += abs( -SCALE*data.rotation.w )
				else:
					thruster[1] += abs( SCALE*data.rotation.w )
					thruster[3] += abs( SCALE*data.rotation.w )

			# True if max spin has not been reached
			# In the direction of spin
			elif data.rotation.w < 0.0:

				#Turning CC and going forwad
				if data.translation.y > 0.0:
					#rospy.loginfo("CC and F: ") 
					thruster[1] += abs( -SCALE*data.rotation.w - mag )
					thruster[2] += 0.0
					thruster[3] += 0.0					
					thruster[4] += abs( -SCALE*data.rotation.w + mag )
				# Turning CC and going backward				
				else:
					#rospy.loginfo("CC and B: ")
					thruster[1] += 0.0
					thruster[2] += abs( -SCALE*data.rotation.w + mag ) 
					thruster[3] += abs( -SCALE*data.rotation.w - mag )	
					thruster[4] += 0.0
									
			else:
				# Turning CCW and going forward
				if data.translation.y > 0.0:
					#rospy.loginfo("CCW and F: ")
					thruster[1] += abs( SCALE*data.rotation.w + mag )
					thruster[2] += 0.0
					thruster[3] += 0.0
					thruster[4] += abs( SCALE*data.rotation.w - mag )
				# Turning CCW and going backward
				else:
					#rospy.loginfo("CCW and B: ")
					thruster[1] += 0.0
					thruster[2] += abs( SCALE*data.rotation.w - mag )
					thruster[3] += abs( SCALE*data.rotation.w + mag )					
					thruster[4] += 0.0

	
		# Remove any negative value 
		if thruster[1] < 0.0: 
			thruster[1] = 0.0
		if thruster[2] < 0.0: 
			thruster[2] = 0.0
		if thruster[3] < 0.0: 
			thruster[3] = 0.0
		if thruster[4] < 0.0: 
			thruster[4] = 0.0
		

		self.thruster.thruster1 = thruster[1]
		self.thruster.thruster2 = thruster[2]
		self.thruster.thruster3 = thruster[3]
		self.thruster.thruster4 = thruster[4]
			
		
		self.thruster.header.stamp = rospy.Time.now()
		self.Thrustpub.publish(self.thruster)
 			


	def gyroCallback(self, data):
		"""
			Limits Rotational spin of the Robot by implementing a 
			Hard cut off
		"""
		
		if data.rate>528 or data.rate<-215:
			self.rateTooFast = True
		else:
			self.rateTooFast = False

		# Check to see if maximum spin has been reached
		#if not self.rateTooFast:

			# Spin Rate is to fast, kill thruster motors
			# self.thruster.thruster6 = 0.0
			# self.thruster.thruster5 = 0.0
			
		# self.Thrustpub.publish( self.thruster )
		






if __name__ == '__main__':
	try:
		rospy.init_node('thrusterMapper')
		m = ThrusterMapper()
		rospy.spin()
	except rospy.ROSInterruptException:
		pass
