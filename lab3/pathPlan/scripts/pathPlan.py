#!/usr/bin/env python 
import roslib; roslib.load_manifest('pathPlan')
import rospy
from geometry_msgs.msg import Transform
from hovercraft.msg import Gryo



if __name__ == '__main__':

    global.startFlag=False
    global.goal = Transform()
    global.goal.translation.z = 0.5
    rospy.init_node('thrusterMapper')
    rospy.Subscriber("hovercraft/Gyro", Gyro, gyroCallback)
    Thrustpub = rospy.Publisher('pathPlan/Command', Transform)
    
    rospy.sleep(5)

    while is not rospy.shutdown():
        Trustpub.publish(global.goal)
        rospy.sleep(0.1)
	
    global.goal.translation.z = 0.0
    Trustpub.publish(global.goal)

def gyroCallback(data):
    if global.startFlag is False:
        global.goal.rotation.w = data.angle+90
        global.startFlag = True
    
