#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <hovercraft/Thruster.h>
#include <hovercraft/Gyro.h>
#include <hovercraft/LED.h>
#include <math.h>

/* Defines for the XBOX 360 Joy Stick */
/**
Thrust Control
axes go from -1 to 1
LS = Left Stick, RS = Right Stick
axes: [ LS X, LS Y, L Trigger, RS X, RS Y, R Trigger]
buttons: [ A, B, X, Y, LB, RB, Back, Start, XBOX, D pad L, D pad R, D pad Up, D pad Down ]
**/

#define XBOX_LS_X_AXIS 	0
#define XBOX_LS_Y_AXIS 	1 
#define XBOX_R_TRIGGER	5
#define XBOX_L_TRIGGER	2
#define XBOX_RS_X_AXIS 	3
#define XBOX_RS_Y_AXIS 	4

#define XBOX_A_BTN		0
#define XBOX_B_BTN		1
#define XBOX_X_BTN		2
#define XBOX_Y_BTN		3
#define XBOX_L_BUMPER	4
#define XBOX_R_BUMPER	5
#define XBOX_BACK_BTN	6
#define XBOX_START_BTN	7
#define XBOX_XBOX_BTN	8

#define TURN_SCALAR   0.2     /* Scalar for the turning motors power 0 to 1 */
#define THRUST_SCALAR 0.5     /* Scalar for the thruster motors power 0 to 1 */
#define PI 3.141592           /* PI */

#define DEGREES_240 4.188790205  /* 240 degrees in radians */
#define DEGREES_120 2.094395102  /* 120 degrees in radians */
#define DEGREES_60  1.047197551  /* 60 degrees in radians */
#define T1_ANGLE    0.0          /* Angle of axis offset for thruster 1 (in radians)*/
#define T2_ANGLE    2.094395102  /* Angle of axis offset for thruster 2 (in radians)*/
#define T4_ANGLE    4.188790205  /* Angle of axis offset for thruster 4 (in radians)*/

class TeleopHover
{
public:
  TeleopHover();

private:
  void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);
  void setThrusters(const sensor_msgs::Joy::ConstPtr& joy);
  void rotateAxis(double &x_new, double &y_new, double theta, const sensor_msgs::Joy::ConstPtr& joy);
  double setMagnitude(double x, double y);
  
  ros::NodeHandle nh_;

  int linear_, angular_;
  double l_scale_, a_scale_;
  bool lift_on;
  ros::Publisher thruster_pub_;
  ros::Subscriber joy_sub_;
  ros::Publisher led_pub_;

  hovercraft::Thruster thrust;
  hovercraft::LED led_on;
};


TeleopHover::TeleopHover():
  linear_(1),
  angular_(2)
{

  nh_.param("axis_linear", linear_, linear_);
  nh_.param("axis_angular", angular_, angular_);
  nh_.param("scale_angular", a_scale_, a_scale_);
  nh_.param("scale_linear", l_scale_, l_scale_);

  lift_on;

  thruster_pub_ = nh_.advertise<hovercraft::Thruster>("hovercraft/Thruster", 1);
  led_pub_ = nh_.advertise<hovercraft::LED>("hovercraft/LED",1);

  joy_sub_ = nh_.subscribe<sensor_msgs::Joy>("joy", 10, &TeleopHover::joyCallback, this);

}

void TeleopHover::joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
{
  led_on.led33_red = float( joy->buttons[XBOX_B_BTN] );
  led_on.led33_green = float( joy->buttons[XBOX_A_BTN] );
 
  /* 

	thruster1 = back thruster
	thruster2 = Left front thruster
	thruster3 = Not attached
	thruster4 = right front thruster
	thruster5 = Rotate Counter Clockwise
	thruster6 = Rotate Clockwise
  */ 

  /* Emergency Kill logic */ 
  if( float( joy->buttons[XBOX_XBOX_BTN] ) == 1 )
  {
    thrust.lift = 0;
    thrust.thruster1 = 0;
    thrust.thruster2 = 0;
    thrust.thruster3 = 0;
    thrust.thruster4 = 0;
    thrust.thruster5 = 0; 
    thrust.thruster6 = 0;

    thruster_pub_.publish(thrust);

  }
  
  /*  Power Button Logic */ 
  if( float( joy->buttons[XBOX_START_BTN] ) == 1 )
  {
    if( lift_on )
    {
     thrust.lift = 0.0;
     lift_on = false; 
    }else
    {  
      thrust.lift = 0.5;
      lift_on = true;
    }
 
  }
  else
  {
    if( lift_on )
    {
      thrust.lift = 0.5;
    }else
    {
      thrust.lift = 0.0;
    }
  }
  /* End Power Button Logic */
  
  
  /* Translational logic */
  
 double angle, mag;
 mag = THRUST_SCALAR * (sqrt( pow(float(joy->axes[XBOX_RS_X_AXIS]),2) + pow(float(joy->axes[XBOX_RS_Y_AXIS]),2) ));
 angle = atan(float(joy->axes[XBOX_RS_X_AXIS])/float(joy->axes[XBOX_RS_Y_AXIS])); /* Angle 0 is forward */ 
 
 /* Adjusting Angle */
 if (float(joy->axes[XBOX_RS_Y_AXIS]) > 0 && float(joy->axes[XBOX_RS_X_AXIS]) >= 0)
 {
	 angle = 2*PI-angle; /* Quadrant 1 */
 } else if (float(joy->axes[XBOX_RS_Y_AXIS]) <= 0 && float(joy->axes[XBOX_RS_X_AXIS]) >= 0)
 {
	 angle = PI - angle; /* Quadrant 2 */
 } else if (float(joy->axes[XBOX_RS_Y_AXIS]) <= 0 && float(joy->axes[XBOX_RS_X_AXIS]) < 0)
 {
	 angle = PI - angle; /* Quadrant 3 */
 } else if (float(joy->axes[XBOX_RS_Y_AXIS]) > 0 && float(joy->axes[XBOX_RS_X_AXIS]) < 0) 
 {
	 angle = -1*angle; 	/* Quadrant 4 */
 }
 
 /* If Angle Not A Number */
 if(angle != angle) 
 {
	 angle = 0;
 }
 
 double T1_offset_ratio, T2_offset_ratio, T4_offset_ratio;
 thrust.thruster1 = 0.0;
 thrust.thruster2 = 0.0;
 thrust.thruster4 = 0.0;
 
 /*  Setting the Ratio of the Thrusters */ 
 if(angle>=0 && angle < DEGREES_120)
 {
	 T1_offset_ratio = (angle-T1_ANGLE)/(DEGREES_120);
	 T2_offset_ratio = (T2_ANGLE-angle)/(DEGREES_120);
	 
	 thrust.thruster1 = mag*T2_offset_ratio;
	 thrust.thruster2 = mag*T1_offset_ratio;
	 
 } else if(angle>=DEGREES_120 && angle < DEGREES_240)
 {
	 T2_offset_ratio = (angle-T2_ANGLE)/(DEGREES_120);
	 T4_offset_ratio = (T4_ANGLE-angle)/(DEGREES_120);
	 
	 thrust.thruster2 = mag*T4_offset_ratio;
	 thrust.thruster4 = mag*T2_offset_ratio;
	 
 } else
 {
	 T4_offset_ratio = (angle-T4_ANGLE)/(DEGREES_120);
	 T1_offset_ratio = (2*PI-angle)/(DEGREES_120);
	 
	 thrust.thruster4 = mag*T1_offset_ratio;
	 thrust.thruster1 = mag*T4_offset_ratio;
	 
 }
 /* End Translation Logic */
 
  /* Turning Logic */ 
  if( float( joy->axes[XBOX_LS_X_AXIS] ) > 0 )
  {
	  thrust.thruster5 = 1.0 * (TURN_SCALAR * float( joy->axes[XBOX_LS_X_AXIS] ) );
	  thrust.thruster6 = 0;
  }
  else
  {
	  thrust.thruster6 = -1.0 * (TURN_SCALAR * float( joy->axes[XBOX_LS_X_AXIS] ) );  /* The Joy value is inverted */
	  thrust.thruster5 = 0;
  }
  /* End Turning Logic*/

  
  
  /* Publish the thrust message */ 
  thruster_pub_.publish(thrust);
  led_pub_.publish(led_on);
  
  
}



int main(int argc, char** argv)
{
  ros::init(argc, argv, "teleop_hover");
  TeleopHover teleop_Hover;

  ros::spin();
}
