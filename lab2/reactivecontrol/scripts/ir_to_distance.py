#!/usr/bin/env python
import roslib; roslib.load_manifest('reactivecontrol')
import rospy
from hoverboard.msg import ADCRaw
from reactivecontrol.msg import IRdistance

def adc_to_cm_ir2( adc_raw ):
	"""
		Converts ADC to a cm value
		based on expermimental values
		non-measured values are found by linear interpolation

		Expermental Values for IR2 

		Outside of bounds (15cm to 150cm) returns a 0
	"""
	
	#Measured values for IR2 -  cm equivelent, ADC measure
	measured_values = ( ( 15, 2630 ), ( 16, 2602 ), ( 17, 2573 ), 
						( 18, 2519 ), ( 19, 2446 ), ( 20, 2397 ), 
						( 22, 2304 ), ( 24, 2187 ), ( 26, 2094 ),  
						( 28, 1972 ), ( 30, 1860 ), ( 35, 1621 ), 
						( 40, 1410 ), ( 45, 1259 ), ( 50, 1127 ), 
						( 60, 932 ),  ( 70, 800 ), 	( 80, 717 ),  
						( 90, 634 ),  ( 100, 561 ), ( 110, 502 ), 
						( 120, 463 ), ( 130, 444 ), ( 140, 415 ), 
						( 150, 400 ) ) 
	
	#Setting the max and min values to find the two nearest points
	max_value = ( 0, 5000 )
	min_value = ( 0, 0 )
	measure_cm = 0.0
	
	#if the measured value is outside of the maximum and minimum outputs	
	if adc_raw > 2630 or adc_raw < 400:
		measure_cm = 0.0
	else:
	
		#Finding the two nearest points  
		for measured_data_point in measured_values: 
			if adc_raw <= measured_data_point[1] and adc_raw > min_value[1]:
				max_value = measured_data_point
			if adc_raw >= measured_data_point[1] and adc_raw < max_value[1]:
				if not min_value[1] > measured_data_point[1]:
					min_value = measured_data_point	
	
		#Interpolating The value
		scalar = ( max_value[1] - min_value[1] )			
		offset = ( adc_raw - min_value[1] )
		proportion = float( offset ) / scalar	
		measure_cm = ( ( max_value[0] - min_value[0] ) * proportion ) + min_value[0]

	#return the CM distance value	
	return measure_cm 


def adc_to_cm_ir1( adc_raw ):
	"""
		Converts ADC to a cm value
		based on expermimental values
		non-measured values are found by linear interpolation

		Optimized for IR sensors 1
		Outside of bounds (15cm to 150cm) returns a 0
	"""
	
	#Measured values -  cm equivelent, ADC measure
	measured_values = ( ( 15, 2543 ), ( 16, 2529 ), ( 17, 2495 ), 
						( 18, 2480 ), ( 19, 2407 ), ( 20, 2348 ), 
						( 22, 2226 ), ( 24, 2138 ), ( 26, 2045 ),  
						( 28, 1992 ), ( 30, 1870 ), ( 35, 1640 ), 
						( 40, 1410 ), ( 45, 1259 ), ( 50, 1127 ), 
						( 60, 932 ),  ( 70, 800 ), 	( 80, 717 ),  
						( 90, 634 ),  ( 100, 561 ), ( 110, 502 ), 
						( 120, 463 ), ( 130, 444 ), ( 140, 415 ), 
						( 150, 400 ) ) 
	
	#Setting the max and min values to find the two nearest points
	max_value = ( 0, 5000 )
	min_value = ( 0, 0 )
	measure_cm = 0.0
	
	#if the measured value is outside of the maximum and minimum outputs	
	if adc_raw > 2630 or adc_raw < 400:
		measure_cm = 0.0
	else:
	
		#Finding the two nearest points  
		for measured_data_point in measured_values: 
			if adc_raw <= measured_data_point[1] and adc_raw > min_value[1]:
				max_value = measured_data_point
			if adc_raw >= measured_data_point[1] and adc_raw < max_value[1]:
				if not min_value[1] > measured_data_point[1]:
					min_value = measured_data_point	
	
		#Interpolating The value
		scalar = ( max_value[1] - min_value[1] )			
		offset = ( adc_raw - min_value[1] )
		proportion = float( offset ) / scalar	
		measure_cm = ( ( max_value[0] - min_value[0] ) * proportion ) + min_value[0]

	#return the CM distance value	
	return measure_cm 

def input_callback(ADCRaw):
	"""
		Publish the IR CM data
	""" 
	
	pub = rospy.Publisher('IRoutput', IRdistance)	
	ir_output = IRdistance()	
	ir_output.IR1 = adc_to_cm_ir1( ADCRaw.adc5_0 )
	ir_output.IR2 = adc_to_cm_ir2( ADCRaw.adc5_1 )	
	pub.publish( ir_output )
     
   	

def rawtocm():
	"""
		Setup IR CM node and subscribe to the correct node
	"""
	rospy.init_node('IRcm')    
	rospy.Subscriber("hoverboard/ADCRaw", ADCRaw, input_callback)
	rospy.spin()	



if __name__ == '__main__':
    try:
        rawtocm()
    except rospy.ROSInterruptException:
        pass
