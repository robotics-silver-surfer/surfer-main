#!/usr/bin/env python 
import roslib; roslib.load_manifest('pathPlan')
import rospy
from geometry_msgs.msg import Transform
from hovercraft.msg import Gyro
from Ref.msg import BotStatus
from math import atan2, cos, pi, sqrt


def isPostionActive( data, secondsTimeout=1.0 ):
	"""
		If we don't get any new postion data after a second, 
		Turn to false
	"""
	global previousPose
	global previousTime

	# Just checking X value
	if abs( previousPose.currentPosition.x - data.currentPosition.x ) > 0.0002:
		# Got new pose, set to previous
		previousPose = data
		previousTime = rospy.get_time()
		#rospy.loginfo("New Tag")
		return True
	else:
		# Didn't get a new number
		if ( previousTime + secondsTimeout ) < rospy.get_time():
			rospy.loginfo("COULD NOT FIND TAG FOR " + str(rospy.get_time() - previousTime) + " Seconds")			
			return False 	
		else:
			return True

def isStuck( data, canRun, secondsBeforeStuck=5.0, stuckArea=12.0 ):
	"""
		If we get stuck and don't move for 
		secondsBeforeStuck, returns True
	"""
	global stuckPose
	global stuckTime

	if canRun: 
		# If true we are not stuck
		if ( abs( stuckPose.currentPosition.x - data.currentPosition.x ) > stuckArea ) and ( abs( stuckPose.currentPosition.y - data.currentPosition.y ) > stuckArea ):
			# Got new pose, set to previous
			stuckPose = data
			stuckTime = rospy.get_time()
			#rospy.loginfo("New Tag")
			return True
		else:
			# Didn't get a new number
			if ( stuckTime + secondsBeforeStuck ) < rospy.get_time():
				#rospy.loginfo("WE GOT STUCK! Stuck time: " + str(rospy.get_time() - stuckTime) + " Seconds")			
				return False 	
			else:
				return True


'''
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
'''

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
	global previouseE
	goalRotation = data.nextCheckpoint.rot
	goalPoseX = data.nextCheckpoint.x
	goalPoseY = data.nextCheckpoint.y


	if data.canRun is True:
		goal.translation.z = 0.65
	else:
		goal.translation.z = 0.0
	

	# Check to see if it is active 
	if( isPostionActive( data ) and data.canRun ): 

		if( not isStuck( data, data.canRun ) ):
			# Check to see if we are stuck 
			rospy.loginfo("We are stuck! Setting goal to middle" )
			goalRotation = 0.0
			goalPoseX = 0.0
			goalPoseY = 0.0
			
		
		currentAngle = -90 + data.currentPosition.rot
		#rospy.loginfo("Current Angle: " + str( currentAngle ) )
	

		goalAngle = atan2( goalPoseY-data.currentPosition.y, goalPoseX-data.currentPosition.x )*180/pi
		#rospy.loginfo("Goal Anlge " + str(goalAngle) ) 
		error= cos((goalAngle-currentAngle)*pi/180)
		distance = sqrt(pow(goalPoseY-data.currentPosition.y,2) + pow(goalPoseX-data.currentPosition.x,2))
		Kp = .004
		Ki = 0
		Kd = .04
		if gyroFlag is True:
			goal.rotation.w = gyro - (goalAngle-currentAngle)

		goal.translation.y = error*distance*Kp + (error*distance-previouseE)*Kd

		rospy.loginfo('P= ' + str(error*distance*Kp) + '   D= ' +str((error*distance-previouseE)*Kd))
		previouseE = error*distance


		'''
		controlPoints(data.currentCheckpoint, data.currentPosistion)
		i=0;
		while i<1:
			xt[i] = pow((1-i),3)*data.currentCheckpoint.x+3*i*pow((1-i),2)*ctrlP1x + 3*pow(i,2)*(1-i)ctrlP2x + pow(i,3)*data.currentCheckpoint.x 
			yt[i] = pow((1-i),3)*data.currentCheckpoint.y+3*i*pow((1-i),2)*ctrlP1y + 3*pow(i,2)*(1-i)ctrlP2y + pow(i,3)*data.currentCheckpoint.
			i = i + 0.02

		goalangle = atan2(xt[1]-data.currentPosition.x , yt[1]-data.currentPosition.y)

		if data.currentposition
		'''
		if( not isStuck( data, data.canRun, secondsBeforeStuck=12.0 ) ): 
			rospy.loginfo("WE ARE SERIOUSLY STUCK! Setting Y to Full Reverse" )
			goal.translation.y = -2.0
			goal.translation.z = ( goal.translation.z * 1.3 ) # Setting thrust to higher   

	else:
		# Didn't get new tag info, shut down 
		goal.translation.y = 0.0


	

	

if __name__ == '__main__':
	global previouseE
	global gyroFlag
	global startFlag	
	global goal 
	global P
	global I
	global D
	global previousPose
	global previousTime
	global stuckPose
	global stuckTime

	previouseE = 0
	startFlag = False
	gyroFlag = False
	goal = Transform()
	rospy.init_node('pathPlan')
	rospy.Subscriber("hovercraft/Gyro", Gyro, gyroCallback)
	rospy.Subscriber("ToTeam", BotStatus, refCallback)
	goalPub = rospy.Publisher('pathPlan/Command', Transform)
	previousPose = BotStatus()
	previousTime = rospy.get_time()	
	stuckTime = rospy.get_time()
	stuckPose = BotStatus()
	#rospy.loginfo(rospy.get_param("/Referee/x"))

	#rospy.sleep(5)

	while not rospy.is_shutdown():
		goalPub.publish(goal)
		rospy.sleep(0.1)

    
