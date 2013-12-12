#!/usr/bin/env python 
import roslib; roslib.load_manifest('pathPlan')
import rospy
from geometry_msgs.msg import Transform
from hovercraft.msg import Gyro
from Ref.msg import BotStatus



def gyroCallback(data):

	global gyroFlag 
	global gyro
        gyro = data.angle
	if gyroFlag is False:
		gyroFlag = True

def refCallback(data):

	global startFlag
	global goal
	global gyroFlag 
	global gyro

	if gyroFlag is True and startFlag is False:
		goal.rotation.w = gyro - data.currentPosition.rot

if __name__ == '__main__':

	global gyroFlag
	global startFlag	
	global goal 

	startFlag = False
        gyroFlag = False
	goal = Transform()
	goal.translation.z = 0.5
	rospy.init_node('pathPlan')
	rospy.Subscriber("hovercraft/Gyro", Gyro, gyroCallback)
        rospy.Subscriber("hovercraft/Gyro", BotStatus, refCallback)
	goalPub = rospy.Publisher('pathPlan/Command', Transform)

	rospy.sleep(5)

	while not rospy.is_shutdown():
		goalPub.publish(goal)
		rospy.sleep(0.1)
	
	goal.translation.z = 0.0
	goalPub.publish(goal)


    
