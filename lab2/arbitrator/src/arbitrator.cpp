/* Hiya!
 *
 */

//Libraries and Packages
#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <hovercraft/Gyro.h>
#include <hovercraft/LED.h> 
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Transform.h>
#include <reactivecontrol/Control.h>
//#include <std_msgs/UInt8.msg>

//Class Constants
#define LED_ON		1
#define LED_OFF		0
#define LIFT_ON		0.5
#define LIFT_OFF	0.0
#define MANUAL_STATE	0
#define AUTO_STATE	1
#define TRIANGLE_STATE	2

//Xbox Button Constants
#define XBOX_A_BTN	0
#define XBOX_B_BTN	1
#define XBOX_X_BTN	2
#define XBOX_Y_BTN	3
#define XBOX_L_BUMPER	4
#define XBOX_R_BUMPER	5
#define XBOX_BACK_BTN	6
#define XBOX_START_BTN  7
#define XBOX_XBOX_BTN	8

//Xbox Joystick Constants
#define XBOX_LS_X_AXIS	0
#define XBOX_LS_Y_AXIS	1
#define XBOX_L_TRIGGER	2
#define XBOX_RS_X_AXIS  3
#define XBOX_RS_Y_AXIS  4
#define XBOX_R_TRIGGER  5

//Class Declaration
class Arbitrator
{
public:
  Arbitrator();

private:
  //Node subscribers and publishers
  ros::NodeHandle nh_;

  ros::Subscriber joy_sub_;
  ros::Subscriber gyro_sub_;
  ros::Subscriber joyAngleItgr_sub_;
  ros::Subscriber triangle_sub_;
  //ros::Subscriber reactivectrl_sub_;

  ros::Publisher arb_pub_;
  ros::Publisher led_pub_;
  ros::Publisher ctrl_pub_;

  //Published messages
  geometry_msgs::Transform arb_data;
  reactivecontrol::Control ctrl_state;
  hovercraft::LED led_on;

  //Class functions
  void joyCallback( const sensor_msgs::Joy::ConstPtr& joy );
  void gyroCalibration( const hovercraft::GyroConstPtr& gyro );
  void joyAngleItgrCallback( const geometry_msgs::Quaternion& itgr );
  void triangleCallback( const geometry_msgs::Transform& triangle );
  void setControlState( int state );//const reactivecontrol::Control& rctrl );
  void signalLED( hovercraft::LED& led, bool green );

  //Class variables
  bool lift_on;
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
  joyAngleItgr_sub_ = nh_.subscribe("joyAngleIntegrater/Data", 10, &Arbitrator::joyAngleItgrCallback, this);
  triangle_sub_ = nh_.subscribe("triangle/Data", 10, &Arbitrator::triangleCallback, this);
  //reactivectrl_sub_ = nh_.subscribe("reactivecontrol/Control", 10, &Arbitrator::setControlState, this);

  arb_pub_ = nh_.advertise<geometry_msgs::Quaternion>("arbitrator/Data", 1);
  ctrl_pub_ = nh_.advertise<reactivecontrol::Control>("arbitrator/Control", 1);
  led_pub_ = nh_.advertise<hovercraft::LED>("hovercraft/LED", 1);

  //Set class variables
  lift_on = false;
  calibrate = true;
  add_90 = false;
  sub_90 = false;
  state = MANUAL_STATE;

} /* end class constructor */

//---------------------------------------------------------------------

/* Arbitrator::joyCallback
 *   Sets class variables according to changes on the controller.
 */
void Arbitrator::joyCallback( const sensor_msgs::Joy::ConstPtr& joy )
{
  //Emergency kill
  if( float(joy->buttons[XBOX_XBOX_BTN]) == 1.0 )
  {
    arb_data.translation.z = LIFT_OFF;
    lift_on = false;

    arb_pub_.publish( arb_data );
    return;
  }

  //Set lift
  if( float(joy->buttons[XBOX_START_BTN]) )
  {
    if( lift_on )
    {
      arb_data.translation.z = LIFT_OFF;
      lift_on = false;
    }
    else
    {
     arb_data.translation.z = LIFT_ON;
     lift_on = true;
    }
  }

  //Set manual vs. auto control
  if( float( joy->buttons[XBOX_BACK_BTN] == 1) )
  {
    if( state == MANUAL_STATE )
    {
      calibrate = true;
      state = AUTO_STATE;
      signalLED( led_on, false );
    }
    else
    {
      state = MANUAL_STATE;
      signalLED( led_on, true );
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

  //Automatic triangle execution (only allowed in auto mode)
  if( float( joy->buttons[XBOX_Y_BTN] ) == 1 && 
      state == AUTO_STATE )
  {
    //return to auto state
    if( state == TRIANGLE_STATE )
    {
      state = AUTO_STATE;
    }
    //begin triangle execution
    else
    {
      state = TRIANGLE_STATE;
    }

  }

  //Update current translational motion
  arb_data.translation.x = joy->axes[0];
  if( state != TRIANGLE_STATE )
  {
    arb_data.translation.y = joy->axes[1];
  }

  //Turn on/off LEDs according to controller buttons
  led_on.led33_green = float( joy->buttons[XBOX_A_BTN] );
  led_on.led33_red = float( joy->buttons[XBOX_B_BTN] );

  arb_pub_.publish( arb_data );
  led_pub_.publish( led_on );

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
  if( state == MANUAL_STATE )
  {
    arb_data.rotation.w = gyro->angle;
    arb_pub_.publish( arb_data );
    return;
  }

  if( calibrate )
  {
    arb_data.rotation.w = gyro->angle;

    if( add_90 )
    {
      arb_data.rotation.w += 90.0;
      add_90 = false;
    }
    else if( sub_90 )
    {
      arb_data.rotation.w -= 90.0;
      sub_90 = false;
    }

    arb_pub_.publish( arb_data );
    calibrate = false;
  }

} /* end method Arbitrator::gyroCalibration() */

//---------------------------------------------------------------------

/* Arbitrator::joyAngleItgrCallback
 *   <description>
 *
 */
void Arbitrator::joyAngleItgrCallback( const geometry_msgs::Quaternion& itgr )
{
  if( state == AUTO_STATE )
  {
    arb_data.rotation.w = itgr.w;
    arb_pub_.publish( arb_data );
  }

} /* end method Arbitrator::joyAngleItgrCallback() */

//---------------------------------------------------------------------

/* Arbitrator::triangleCallback
 *   <description>
 *
 */
void Arbitrator::triangleCallback( const geometry_msgs::Transform& triangle )
{
  if( state == TRIANGLE_STATE )
  {
    arb_data.translation.y = triangle.translation.y;
    arb_data.rotation.w = triangle.rotation.w;
    arb_pub_.publish( arb_data );
  }

} /* end method Arbitrator::triangleCallback() */

//---------------------------------------------------------------------

/* Arbitrator::setControlState
 *   <description>
 *
 */
void Arbitrator::setControlState( int state )//const reactivecontrol::Control& rctrl )
{

  ctrl_state.state = state;
  ctrl_pub_.publish( ctrl_state );

} /* end method Arbitrator::controlState() */

//---------------------------------------------------------------------
 
/* Arbitrator::signalGreenLED
 *   Blink the green led quickly 3 times
 */
void Arbitrator::signalLED( hovercraft::LED& led, bool green )
{
  int i;
  for( i = 0; i < 3; i++ )
  {
    //blink 3 times
    ros::Duration(0.2).sleep(); //sleep for 20ms
    if( green )
    {
      led.led33_green = LED_ON;
    }
    else
    {
      led.led33_red = LED_ON;
    }
    
    led_pub_.publish( led_on );

    ros::Duration(0.4).sleep(); //sleep for 40ms
    if( green )
    {
      led.led33_green = LED_OFF;
    }
    else
    {
      led.led33_red = LED_OFF;
    }
    
    led_pub_.publish( led_on );
  }

} /* end method Arbitrator::signalGreenLED() */

//---------------------------------------------------------------------

//Main Function
int main(int argc, char** argv)
{

  ros::init(argc, argv, "arbitrator");
  Arbitrator arbi;
  ros::spin();

  return 0;

} /* end main function */

