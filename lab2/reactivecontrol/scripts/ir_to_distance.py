#!/usr/bin/env python
import roslib; roslib.load_manifest('reactivecontrol')
import rospy
from hoverboard.msg import ADCRaw
from reactivecontrol.msg import IRdistance


def adc_to_cm( adc_raw ):
	"""
		Converts ADC to a cm value
		based on expermimental values
		non-measured values are found by linear interpolation
	"""
	
	#Measured values -  cm equivelent, ADC measure


	measured_values = ( ( 15, 2622 ), ( 16, 2602 ), ( 17, 2573 ), 
						( 18, 2519 ), ( 19, 2446 ), ( 20, 2397 ), 
						( 22, 2304 ), ( 24, 2187 ), ( 26, 2094 ),  
						( 28, 1972 ), ( 30, 1860 ), ( 35, 1621 ), 
						( 40, 1410 ), ( 45, 1259 ), ( 50, 1127 ), 
						( 60, 932 ),  ( 70, 800 ), 	( 80, 717 ),  
						( 90, 634 ),  ( 100, 561 ), ( 110, 502 ), 
						( 120, 463 ), ( 130, 444 ), ( 140, 415 ), 
						( 150, 400 ) ) 
	return 0 

def input_callback(ADCRaw):
	"""
		Blah
	""" 
	
	pub = rospy.Publisher('IRoutput', IRdistance)	
	ir_output = IRdistance()	
	ir_output.IR1 = adc_to_cm( ADCRaw.adc5_0 )
	ir_output.IR2 = adc_to_cm( ADCRaw.adc5_1 )	
	pub.publish( ir_output )
     
   	

def rawtocm():
	"""
		Blah
	"""
	rospy.init_node('IRcm')    
	rospy.Subscriber("hoverboard/ADCRaw", ADCRaw, input_callback)
	rospy.spin()	



if __name__ == '__main__':
    try:
        rawtocm()
    except rospy.ROSInterruptException:
        pass
