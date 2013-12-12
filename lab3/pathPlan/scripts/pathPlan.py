#!/usr/bin/env python 
import roslib; roslib.load_manifest('pathPlan')
import rospy
from geometry_msgs.msg import Transform
from hovercraft.msg import Gyro




def gyroCallback(data):

	global startFlag 
	global goal
	if startFlag is False:
		goal.rotation.w = data.angle+90
		startFlag = True

if __name__ == '__main__':

	global startFlag	
	global goal 

	startFlag = False
	goal = Transform()
	goal.translation.z = 0.5
	rospy.init_node('pathPlan')
	rospy.Subscriber("hovercraft/Gyro", Gyro, gyroCallback)
	goalPub = rospy.Publisher('pathPlan/Command', Transform)

	rospy.sleep(5)

	while not rospy.is_shutdown():
		goalPub.publish(goal)
		rospy.sleep(0.1)
	
	goal.translation.z = 0.0
	goalPub.publish(goal)


    
