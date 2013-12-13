#!/usr/bin/env python 
import roslib; roslib.load_manifest('pathPlan')
import rospy
from geometry_msgs.msg import Transform
from hovercraft.msg import Gyro
from Ref.msg import BotStatus


def controlPoints(goal, current)
	global ctrlP1x
	global ctrlP1y
	global ctrlP2x
	global ctrlP2y

	xc = (goal.x + current.x)/2 +1
	yc = (goal.y + current.y)/2
    ax = goal.x - xc
	bx = current.x - xc
	ay = goal.y - yc
	by = current.y -yc

	q1 = ax*ax+ay*ay
	q2 = q1+ax*bx+ay*by 
	k2 = 4/3*(sqrt(2*q1*q2)-q2)/(ax*by-ay*bx)

	ctrlP1x = xc + current.x- k2*current.y
	ctrlP1y = yc + current.y + k2*current.x
	ctrlP1x = xc + goal.x- k2*goal.y
	ctrlP1y = yc + goal.y + k2*goal.x

def refCallback(data):

	global startFlag
	global goal
	global gyroFlag 
	global gyro
    global currentPosition
	global currentGoal
	

	controlPoints(data.currentCheckpoint, data.currentPosistion)
	i=0;
	while i<1:
		xt[i] = pow((1-i),3)*data.currentCheckpoint.x+3*i*pow((1-i),2)*ctrlP1x + 3*pow(i,2)*(1-i)ctrlP2x + pow(i,3)*data.currentCheckpoint.x 
		yt[i] = pow((1-i),3)*data.currentCheckpoint.y+3*i*pow((1-i),2)*ctrlP1y + 3*pow(i,2)*(1-i)ctrlP2y + pow(i,3)*data.currentCheckpoint.y

		


if __name__ == '__main__':

	global gyroFlag
	global startFlag	
	global goal 
	global x
	global y

	startFlag = False
	gyroFlag = False
	goal = Transform()
	rospy.init_node('smoothPath')
	rospy.Subscriber("ToTeam", BotStatus, refCallback)
	goalPub = rospy.Publisher('pathPlan/Command', Transform)

	x = rospy.get_param("/Referee/x")
    y = rospy.get_param("/Referee/y")



	


    
