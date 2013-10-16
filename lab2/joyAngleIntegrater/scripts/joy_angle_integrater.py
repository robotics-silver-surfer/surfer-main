#!/usr/bin/env python
import roslib; roslib.load_manifest('joyAngleIntegrater')
import rospy
from Joy.msg import axes

timer = 

def integrate( joy_data ):
	"""
		Integrates the angle
	"""

def input_callback( joy_data ):

	pub = rospy.Publisher('', 


def setup():
	"""
		Hiya!
	"""

	rospy.init_node('angleIntegrater')
	rospy.Subscriber("sensor_msgs/Joy", joy_data , integrate)
	rospy.spin()

if __name__ == '__main__':
    try:
        setup()
    except rospy.ROSInterruptException:
        pass

