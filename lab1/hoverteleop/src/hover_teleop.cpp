#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <hovercraft/Thruster.h>
#include <hovercraft/Gyro.h>

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

#define XBOX_A_BTN		float( joy->buttons[0] )
#define XBOX_B_BTN		float( joy->buttons[1] )
#define XBOX_X_BTN		float( joy->buttons[2] )
#define XBOX_Y_BTN		float( joy->buttons[3] )
#define XBOX_L_BUMPER	float( joy->buttons[4] )
#define XBOX_R_BUMPER	float( joy->buttons[5] )
#define XBOX_BACK_BTN	float( joy->buttons[6] )
#define XBOX_START_BTN	float( joy->buttons[7] )
#define XBOX_XBOX_BTN	float( joy->buttons[8] )

#define TURN_SCALAR		0.3   /* Scalar for the turning motors power 0 to 1 */
#define THRUST_SCALAR	0.3   /* Scalar for the thruster motors power 0 to 1 */


class TeleopHover
{
public:
  TeleopHover();

private:
  void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);
  
  ros::NodeHandle nh_;

  int linear_, angular_;
  double l_scale_, a_scale_;
  bool lift_on;
  ros::Publisher thruster_pub_;
  ros::Subscriber joy_sub_;

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


  joy_sub_ = nh_.subscribe<sensor_msgs::Joy>("joy", 10, &TeleopHover::joyCallback, this);

}

void TeleopHover::joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
{
 
  hovercraft::Thruster thrust;
 
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
 
  }else
  {
    if( lift_on )
    {
      thrust.lift = 0.5;
    }else
    {
      thrust.lift = 0.0;
    }
  }
  
  float magnitude;

  /* Translational logic */
  
  //North
  if( XBOX_RS_Y_AXIS > 0 && XBOX_RS_X_AXIS == 0 )
  {
	magnitude = XBOX_RS_Y_AXIS;

	if( magnitude > 0.7 )
	  magnitude = 0.75;
	else
	  magnitude = XBOX_RS_Y_AXIS;

	thrust.thruster1 = magnitude;
  }

  //South
  else if( XBOX_RS_Y_AXIS < 0 && XBOX_RS_X_AXIS == 0)
  {
  	magnitude = XBOX_RS_Y_AXIS * -1;

	if( magnitude > 0.7 )
          magnitude = 0.75;
        else
          magnitude = XBOX_RS_Y_AXIS * -1;

        thrust.thruster2 = magnitude;
	thrust.thruster4 = magnitude;

  }

  //East
  else if( XBOX_RS_X_AXIS > 0 && XBOX_RS_Y_AXIS == 0)
  {
	magnitude = XBOX_RS_X_AXIS;

  	if( magnitude > 0.7 )
	  magnitude = 0.75;
	else
	  magnitude = XBOX_RS_X_AXIS;

	thrust.thruster2 = magnitude;
	thrust.thruster1 = magnitude * 0.5;
  }

  //West
  else if ( XBOX_RS_X_AXIS < 0  && XBOX_RS_Y_AXIS == 0)
  {
  	magnitude = XBOX_RS_X_AXIS * -1;

	if( magnitude > 0.7 )
	  magnitude = 0.75;
	else
	  magnitude = XBOX_RS_X_AXIS * -1;

	thrust.thruster4 = magnitude;
	thrust.thruster1 = 0.5*magnitude;
  }



  /* End Translation logic */

  /* Turning Logic */ 
  if( XBOX_LS_X_AXIS > 0 )
  {
	  thrust.thruster5 = 1.0 * (TURN_SCALAR * XBOX_LS_X_AXIS );
	  thrust.thruster6 = 0;
  }else
  {
	  thrust.thruster6 = -1.0 * (TURN_SCALAR * XBOX_LS_X_AXIS );  /* The Joy value is inverted */
	  thrust.thruster5 = 0;
  }
  /* End Turning Logic*/

  
  /* Publish the thrust message */ 
  thruster_pub_.publish(thrust);
  
  
}


int main(int argc, char** argv)
{
  ros::init(argc, argv, "teleop_hover");
  TeleopHover teleop_Hover;

  ros::spin();
}
