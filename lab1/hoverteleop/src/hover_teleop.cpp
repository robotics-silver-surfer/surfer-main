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
//TODO: RECHECK THIS - IMB  9/19 - Probably shouldn't do it this way, but I like it
#define XBOX_LS_X_AXIS 	float( joy->axes[0] )
#define XBOX_LS_Y_AXIS 	float( joy->axes[1] )
#define XBOX_R_TRIGGER	float( joy->axes[5] )
#define XBOX_L_TRIGGER	float( joy->axes[2] )
#define XBOX_RS_X_AXIS 	float( joy->axes[3] )
#define XBOX_RS_Y_AXIS 	float( joy->axes[4] )

#define XBOX_A_BTN	float( joy->buttons[0] )
#define XBOX_B_BTN	float( joy->buttons[1] )
#define XBOX_X_BTN	float( joy->buttons[2] )
#define XBOX_Y_BTN	float( joy->buttons[3] )
#define XBOX_L_BUMPER	float( joy->buttons[4] )
#define XBOX_R_BUMPER	float( joy->buttons[5] )
#define XBOX_BACK_BTN	float( joy->buttons[6] )
#define XBOX_START_BTN	float( joy->buttons[7] )
#define XBOX_XBOX_BTN	float( joy->buttons[8] )

#define TURN_SCALAR   0.3     /* Scalar for the turning motors power 0 to 1 */
#define THRUST_SCALAR 0.9     /* Scalar for the thruster motors power 0 to 1 */

#define DEGREES_120 2.094395102  /* 120 degrees in radians */
#define DEGREES_60  1.047197551  /* 60 degrees in radians */
#define T1_ANGLE    0.0          /* Angle of axis offset for thruster 1 (in radians)*/
#define T2_ANGLE    2.094395102  /* Angle of axis offset for thruster 2 (in radians)*/
#define T4_ANGLE   -2.094395102  /* Angle of axis offset for thruster 4 (in radians)*/

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
  led_on.led33_red = XBOX_B_BTN;
  led_on.led33_green = XBOX_A_BTN;
 
  /**
  Thrust Control 
  Values of axes go from -1 to 1 
  LS = Left Stick, RS = Right Stick 
  axes: [ LS X, LS Y, L Trigger, RS X, RS Y, R Trigger] 
  buttons: [ A, B, X, Y, LB, RB, Back, Start, XBOX, D pad L, D pad R, D pad Up, D pad Down ]
  **/  

  /* 

	thruster1 = back thruster
	thruster2 = Left front thruster
	thruster3 = Not attached
	thruster4 = right front thruster
	thruster5 = Rotate Counter Clockwise
	thruster6 = Rotate Clockwise
  */ 

  /* Emergency Kill logic */ 
  if( XBOX_XBOX_BTN == 1 )
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
  if( XBOX_START_BTN == 1 )
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

  /* Translational logic */
  setThrusters(joy);

  /* Turning Logic */ 
  if( XBOX_LS_X_AXIS > 0 )
  {
	  thrust.thruster5 = 1.0 * (TURN_SCALAR * XBOX_LS_X_AXIS );
	  thrust.thruster6 = 0;
  }
  else
  {
	  thrust.thruster6 = -1.0 * (TURN_SCALAR * XBOX_LS_X_AXIS );  /* The Joy value is inverted */
	  thrust.thruster5 = 0;
  }
  /* End Turning Logic*/

  
  
  /* Publish the thrust message */ 
  thruster_pub_.publish(thrust);
  led_pub_.publish(led_on);
  
  
}

//--------------------------------------------------------------------------------

/* setThrusters
 * Function used to set translational thruster magnitudes
 * according to the controller's right analog stick position.
 */
void TeleopHover::setThrusters(const sensor_msgs::Joy::ConstPtr& joy)
{
  double x1, y1; //Thruster 1 axis
  double x2, y2; //Thruster 2 axis
  double x4, y4; //Thruster 4 axis

  rotateAxis(x1, y1, T1_ANGLE, joy);
  rotateAxis(x2, y2, T2_ANGLE, joy);
  rotateAxis(x4, y4, T4_ANGLE, joy);

  thrust.thruster1 = setMagnitude(x1, y1);
  thrust.thruster2 = setMagnitude(x2, y2);
  thrust.thruster4 = setMagnitude(x4, y4);
}

//--------------------------------------------------------------------------------

/* rotateAxis
 * Function used to rotate the hovercraft axis to the
 * axis from the thruster's view point.
 */
void TeleopHover::rotateAxis(double &x_new, double &y_new, double theta, const sensor_msgs::Joy::ConstPtr& joy)
{
  x_new = XBOX_RS_X_AXIS * cos( theta ) + XBOX_RS_Y_AXIS * sin( theta );
  y_new = XBOX_RS_X_AXIS * (-1) * sin( theta ) + XBOX_RS_Y_AXIS * cos( theta );
}

//--------------------------------------------------------------------------------

/* setMagnitude
 * Function used set the magnitude of the thruster according to
 * the analog sticks position on its axis.
 */
double TeleopHover::setMagnitude(double x, double y)
{
  double theta = atan( x / y );
  if ( x < 0 ) 
  {
    if ( atan( x / y ) < DEGREES_120 )
    {
      return sqrt( pow(x,2) + pow(y,2) ) * ( DEGREES_120 - atan( x / y ) );
    }
  }
  else
  {
    if ( theta > DEGREES_60 )
    {
      return sqrt( pow(x,2) + pow(y,2) ) * ( atan( x / ( -1 * y ) ) - DEGREES_60 );
    }
  }
  return 0.0;
}

//--------------------------------------------------------------------------------

int main(int argc, char** argv)
{
  ros::init(argc, argv, "teleop_hover");
  TeleopHover teleop_Hover;

  ros::spin();
}
