#!/usr/bin/env python
import roslib; roslib.load_manifest('thrusterMapping')
import rospy
from std_msgs.msg import Float64
from hovercraft.msg import *



class ThrusterMapper:
	def __init__(self):
		self.Thrustpub = rospy.Publisher('hovercraft/Thruster', Thruster)
		rospy.Subscriber("pidOutput", Float64, self.pidCallback)
		rospy.Subscriber("hovercraft/Gyro", Gyro, self.gyroCallback)
	        rospy.Subscriber("arbitrator/thrust",Float64,self.thrustCallback)
                self.rateTooFast = False;
		self.thruster = Thruster()
    
        def thrustCallback(self,data):
                if data.data == 1.0:
			if self.thruster.lift is 0.5:
				self.thruster.lift = 0.0;
			else:
				self.thruster.lift = 0.5;
		self.Thrustpub.publish(self.thruster)
				
   
	def pidCallback(self, data):
		if not self.rateTooFast and self.thruster.lift > 0.0:
			if data.data<0.0:
				self.thruster.thruster6 = -1.0*data.data
				self.thruster.thruster5 = 0.0
			else:
				self.thruster.thruster5 = data.data
				self.thruster.thruster6 = 0.0
	                self.Thrustpub.publish(self.thruster)
		else:
			self.thruster.thruster6 = 0.0
			self.thruster.thruster5 = 0.0
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
