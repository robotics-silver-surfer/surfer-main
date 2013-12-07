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

		# Thruster 1 2 - rotate CC
		# Thruster 3 4 - rotate CCW
		self.thruster.thruster1 = 0.0
		self.thruster.thruster2 = 0.0
		self.thruster.thruster3 = 0.0
		self.thruster.thruster4 = 0.0

		self.thruster.lift = data.translation.z

		mag = 0.0
		mag = sqrt( pow(data.translation.y,2) ) * SCALE
		# Check to make sure mag is positive 
		if data.translation.y > 0.0: 
			# Set All thrusters too the mag 
			self.thruster.thruster1 = mag
			self.thruster.thruster2 = 0.0
			self.thruster.thruster3 = 0.0
			self.thruster.thruster4 = mag
		else:
			# going backward
			self.thruster.thruster1 = 0.0
			self.thruster.thruster2 = mag
			self.thruster.thruster3 = mag
			self.thruster.thruster4 = 0.0
			
		# Check to see if maximum spin has been reached
		if not self.rateTooFast and self.thruster.lift > 0.0:

			# True if max spin has not been reached
			# In the direction of spin
			if data.rotation.w < 0.0:
				self.thruster.thruster1 += -SCALE*data.rotation.w
				self.thruster.thruster2 += 0.0
				self.thruster.thruster3 += -SCALE*data.rotation.w
				self.thruster.thruster4 += 0.0

			else:
				self.thruster.thruster1 += 0.0
				self.thruster.thruster2 += SCALE*data.rotation.w				
				self.thruster.thruster3 += 0.0
				self.thruster.thruster4 += SCALE*data.rotation.w	
				
		
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
		if not self.rateTooFast:

			# Spin Rate is to fast, kill thruster motors
			self.thruster.thruster6 = 0.0
			self.thruster.thruster5 = 0.0
			
		self.Thrustpub.publish( self.thruster )
		






if __name__ == '__main__':
	try:
		rospy.init_node('thrusterMapper')
		m = ThrusterMapper()
		rospy.spin()
	except rospy.ROSInterruptException:
		pass
