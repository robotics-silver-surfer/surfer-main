#!/usr/bin/env python
import roslib; roslib.load_manifest('thrusterMapping')
import rospy
from geometry_msgs.msg import Transform
from hovercraft.msg import *


pi = 3.14159
T1_ANGLE = 0.0
T2_ANGLE = 2/3*pi
T3_ANGLE = 4/3*pi

class ThrusterMapper:
	def __init__(self):
		self.Thrustpub = rospy.Publisher('hovercraft/Thruster', Thruster)
		rospy.Subscriber("pidOutput", Transform, self.pidCallback)
		rospy.Subscriber("hovercraft/Gyro", Gyro, self.gyroCallback)
                self.rateTooFast = False;
		self.thruster = Thruster()
    
        def thrustCallback(self,data):
                if data.data == 1.0:
			if self.thruster.lift is 0.5:
				self.thruster.lift = 0.0;
				self.thruster.thruster6 = 0.0;
				self.thruster.thruster5 = 0.0;
			else:
				self.thruster.lift = 0.5;
		self.Thrustpub.publish(self.thruster)
				
   
	def pidCallback(self, data):
		if data.Translation.z == 1.0
			if self.thruster.lift is 0.5:
				self.thruster.lift = 0.0;
				self.thruster.thruster6 = 0.0;
				self.thruster.thruster5 = 0.0;
			else:
				self.thruster.lift = 0.5;

		if not self.rateTooFast and self.thruster.lift > 0.0:
			if data.rotation.w<0.0:
				self.thruster.thruster6 = -1.0*data.rotation.w
				self.thruster.thruster5 = 0.0
			else:
				self.thruster.thruster5 = data.rotation.w
				self.thruster.thruster6 = 0.0

		mag = sqrt(pow(data.translation.x,2)+pow(data.translation.y,2))
		angle = atan2(data.translation.x,data.translation.y)
		if angle<0:
			angle = angle+2*pi

		if angle>=0 and angle<(2/3*pi):
 			T1_offset_ratio = (angle-T1_ANGLE)/(2/3*pi)
	 		T2_offset_ratio = (T2_ANGLE-angle)/(2/3*pi)
	 
	 		self.thrust.thruster1 = mag*T2_offset_ratio
	 		self.thrust.thruster2 = mag*T1_offset_ratio
		elif angle>=(2/3*pi) and angle<(4/3*pi):
 			T2_offset_ratio = (angle-T2_ANGLE)/(2/3*pi)
	 		T4_offset_ratio = (T4_ANGLE-angle)/(2/3*pi)
	 
	 		self.thrust.thruster2 = mag*T4_offset_ratio
	 		self.thrust.thruster4 = mag*T2_offset_ratio
		else:
 			T4_offset_ratio = (angle-T4_ANGLE)/(2/3*pi)
	 		T1_offset_ratio = (T1_ANGLE-angle)/(2/3*pi)
	 
	 		self.thrust.thruster4 = mag*T1_offset_ratio
	 		self.thrust.thruster1 = mag*T4_offset_ratio	

		self.Thrustpub.publish(self.thruster)
 			


	def gyroCallback(self, data):
		if data.rate>528 or data.rate<-215:
			self.rateTooFast = True
			self.thruster.thruster5 = 0.0
			self.thruster.thruster5 = 0.0
			self.Thrustpub.publish(self.thruster)
		else:
			self.rateTooFast = False





			
			



if __name__ == '__main__':
	try:
		rospy.init_node('thrusterMapper')
		m = ThrusterMapper()
		rospy.spin()
	except rospy.ROSInterruptException:
		pass
