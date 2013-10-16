#!/usr/bin/env python
import roslib; roslib.load_manifest('reactivecontrol')
import rospy
from reactivecontrol.msg import IRdistance
from geometry_msgs.msg import Transform
from std_msgs.msg import Bool

class reactive_control: 
	"""
		Class that controls the reactive control

	"""
	def __init__( self ): 

		

		#publisher for control message
		self.control_pub = rospy.Publisher('reactivecontrol/Control', Transform)
		
		#Forcing take over of arbitrator to switch to reactive control 
		self.abitrator_takeover = rospy.Publisher('reactivecontrol/ArbitratorForceTakeover', Bool)
		
		
		# PID stuff 
		self.previous_error = 0.0
		self.setpoint = 25.0
		self.Kp = .01
		self.Kd = 0.0

	def start( self ): 
		"""
			Intializes reactive control
		"""

		# Opening up nodes and such
		rospy.init_node('Reactive_Control')    
		rospy.Subscriber("ircm/IRoutput", IRdistance, self.__input_callback)
		rospy.spin()

	def __input_callback( self, distance ):
		"""	
			Called back whenever new data is recieved from IR Output
		"""			
		
		# Calling the PD control function
		self.__pd_control( distance )

		# Calling the Averge distance following function
		#self.__avg_distance_following( distance )

	def __pd_control( self, distance ): 
		"""
			Control using a PD controller
			PD - Proportional Derivitive  

			NOTE:
				I term is not implemented 
				as reactive control is not always running
				and 'windup' could be a serious issue
		"""
		
		avg_distance = self.__avg_distance( distance )

		if avg_distance is not 0.0 and avg_distance < 80 and avg_distance > 15: 
			
			error = avg_distance - self.setpoint
		
			derivative = ( error - self.previous_error )
			output = self.Kp * error + self.Kd * derivative

		
			position = Transform()
		
			position.translation.x = 0.0;
			position.translation.z = .5;
			position.translation.y = output;
	
			#rospy.loginfo("Distance " + str( self.__avg_distance( distance ) ) + " Error: " + str(error) + " PD Output: " + str(position.translation.y) )
		
			self.__publish_position( position ) 		

			self.abitrator_takeover.publish(True)
		else:
			rospy.loginfo("No valid IR data infromation or IR data is out of range measured: " + str( avg_distance) )
		

	def __avg_distance( self, distance ):
		"""
			Calculates the distance based on the average of the 
			two IR sensors.  
		"""

		avg_distance = 0.0
		# Check to make sure the sensor is in range
		# 0 is out of bounds
		#both sensors are out of range				
		if ( distance.IR1 == 0.0 ) and ( distance.IR2 == 0.0 ):
 			rospy.loginfo("IR Sensors are out of range")
			return False
		#if not out of range check both sensors and take valid sensor	
		elif ( distance.IR1 == 0 ):
			# If one sensor is invalid, just set it to the other sensor
			# Works for simple averaging distances
			distance.IR1 = distance.IR2
		elif ( distance.IR2 == 0 ):
			distance.IR2 = distance.IR1
		#if the measured distance between the two IR sensors is greater than 5 cm or it is greater than 20 cm, invalidate data	
		elif ( abs( distance.IR1 - distance.IR2 ) > 5 and abs( distance.IR1 - distance.IR2 ) < 20 ):
			# IR sensors are to far off, something is most likely wrong
			avg_distance = 0.0 		
		#Averaging distance
		else:
			avg_distance = ( distance.IR1 + distance.IR2 ) / 2

		return avg_distance

	def __avg_distance_following( self, distance ):
		"""
			Function used to do avg distance following
			using a bang bang controller
		"""
		
		avg_distance = self.__avg_distance( distance )

		position = Transform()
		
		position.translation.x = 0.0;
		position.translation.z = .5;
		position.translation.y = 0.0;

		#If we are more than 35 cm away speed up		
		if avg_distance > 35: 
			position.translation.y = .3
		#If we are closer than 25 cm back away
		elif avg_distance < 25 and avg_distance != 0:
			position.translation.y = -.3


		
		rospy.loginfo("Distance: " + str(avg_distance) + " Bang Bang: " + str(position.translation.y) )
		
		self.__publish_position( position ) 		

		
		self.abitrator_takeover.publish(True)


	def __publish_position( self, transform_postion ):
		"""
			Used to publish the postion topic
		"""

		self.control_pub.publish( transform_postion )

if __name__ == '__main__':

	x = reactive_control()
	x.start()

