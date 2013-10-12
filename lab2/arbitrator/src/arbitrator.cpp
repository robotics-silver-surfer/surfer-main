/* Hiya!
 *
 */

//Libraries and Packages
#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <hovercraft/Gyro.h>
#include <hovercraft/LED.h> 
#include <std_msgs/Float64.h>
#include <arbitrator/ArbAngle.h>

//Class Constants
#define XBOX_L_BUMPER	4
#define XBOX_R_BUMPER	5
#define XBOX_BACK_BTN	6
#define XBOX_START_BTN  7
#define ON		1.0
#define OFF		0.0
#define JOY_STATE	0
#define JOY_AI_STATE	1
#define TRIANGLE_STATE	2

//Class Declaration
class Arbitrator
{
public:
  Arbitrator();

private:
  //Node subscribers and publishers
  ros::NodeHandle nh_;

  ros::Publisher angle_pub_;
  
  ros::Subscriber joy_sub_;
  ros::Subscriber gyro_sub_;
  ros::Subscriber reactive_ctrl_sub_;
  ros::Publisher led_pub_;
  ros::Publisher thrust_pub_;

  //Published messages
  hovercraft::LED led_on;
  std_msgs::Float64 arb_angle;
  std_msgs::Float64 thrust;

  //Class functions
  void joyCallback( const sensor_msgs::Joy::ConstPtr& joy );
  void gyroCalibration( const hovercraft::GyroConstPtr& gyro );
//  void setControlState( const reactivecontrol::Control& rctrl );

  //Class variables
  bool manual_on;
  bool calibrate;
  bool add_90;
  bool sub_90;
  int state; 

}; /* end class declaration */

//---------------------------------------------------------------------

//Class Constructor
Arbitrator::Arbitrator()
{
  //Set subscribers and publishers
  joy_sub_ = nh_.subscribe("joy", 10, &Arbitrator::joyCallback, this);
  gyro_sub_ = nh_.subscribe("hovercraft/Gyro", 10, &Arbitrator::gyroCalibration, this);
//  reactive_ctrl_sub_ = nh_.subscribe("reactivecontrol/Control", 10, &Arbitrator::setControlState, this);
  led_pub_ = nh_.advertise<hovercraft::LED>("hovercraft/LED", 1);
  angle_pub_ = nh_.advertise<std_msgs::Float64>("arbitrator/ArbAngle", 1);
  thrust_pub_ = nh_.advertise<std_msgs::Float64>("arbitrator/thrust", 1 );

  //Set class variables
  manual_on = false;
  calibrate = true;
  add_90 = false;
  sub_90 = false;
  state = JOY_STATE;

} /* end class constructor */

//---------------------------------------------------------------------

/* Arbitrator::joyCallback
 *   Sets class variables according to changes on the controller.
 */
void Arbitrator::joyCallback( const sensor_msgs::Joy::ConstPtr& joy )
{

  //Set manual vs. autonomous control
  if( float( joy->buttons[XBOX_BACK_BTN] == 1) )
  {
    if( manual_on )
    {
      calibrate = true;
      manual_on = false;
      led_on.led33_green = OFF;
    }
    else
    {
      manual_on = true;
      led_on.led33_green = ON;
    }

  }

  //Automatic right rotation
  if( float( joy->buttons[XBOX_R_BUMPER] ) == 1 )
  {
    calibrate = true;
    add_90 = true;
  }

  //Automatic left rotation
  if( float( joy->buttons[XBOX_L_BUMPER] ) == 1 )
  {
    calibrate = true;
    sub_90 = true;
  }
  
  //Set lift
  thrust.data = 0.0;
  if( float(joy->buttons[XBOX_START_BTN]) )
  {
     thrust.data = 1.0;
  }

  led_pub_.publish( led_on );
  thrust_pub_.publish( thrust);

} /* end method Arbitrator::joyCallback() */

//---------------------------------------------------------------------

/* Arbitrator::gyroCalibration
 *   Sends a target angle to the PID.  
 *
 *   When in manual control, contiuously forwards the current angle.  
 *
 *   When in autonomous control, calibrates to the current angle, then
 *   holds at that angle (ignores all gyro changes). 
 *
 *   When specified by the controller in autonomous-mode, the target 
 *   angle is adjusted 90 degrees accordingly.
 */
void Arbitrator::gyroCalibration( const hovercraft::Gyro::ConstPtr& gyro )
{

  if( manual_on )
  {
    arb_angle.data = gyro->angle;
    angle_pub_.publish( arb_angle );
    return;
  }

  if( calibrate )
  {
    arb_angle.data = gyro->angle;

    if( add_90 )
    {
      arb_angle.data += 90.0;
      add_90 = false;
    }
    else if( sub_90 )
    {
      arb_angle.data -= 90.0;
      sub_90 = false;
    }

    angle_pub_.publish( arb_angle );
    calibrate = false;
  }

} /* end method Arbitrator::gyroCalibration() */

//---------------------------------------------------------------------

/* Arbitrator::setControlState
 *   <description>
 *
 */
//void setControlState( const reactivecontrol::Control& rctrl )
//{
//  state = rctrl->state;
//
//} /* end method Arbitrator::controlState() */


//---------------------------------------------------------------------

//Main Function
int main(int argc, char** argv)
{

  ros::init(argc, argv, "arbitrator");
  Arbitrator arbi;
  ros::spin();

  return 0;

} /* end main function */

