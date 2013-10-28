/* arbitrator.cpp
 *   Manages the state of the hovercraft based on
 *   commands from the controller.
 */

//Libraries and Packages
#include <ros/ros.h>
#include <ros/console.h>
#include <sensor_msgs/Joy.h>
#include <hovercraft/LED.h> 
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Transform.h>
#include <reactivecontrol/Control.h>

//Class Constants
#define LED_ON		1
#define LED_OFF		0
#define LIFT_ON		0.5
#define LIFT_OFF	0.0
#define MANUAL_STATE	0
#define AUTO_STATE	1
#define TRIANGLE_STATE	2
#define TURN_R_STATE	3
#define TURN_L_STATE	4
#define TURN_OFFSET	5.0

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
  ros::Subscriber joyAngleItgr_sub_;
  ros::Subscriber triangle_sub_;
  ros::Subscriber reactivectrl_sub_;

  ros::Publisher arb_pub_;
  ros::Publisher led_pub_;
  ros::Publisher ctrl_pub_;

  //Published messages
  geometry_msgs::Transform arb_data;
  reactivecontrol::Control ctrl_state;
  hovercraft::LED led_on;

  //Class functions
  void joyCallback( const sensor_msgs::Joy::ConstPtr& joy );
  void joyAngleItgrCallback( const geometry_msgs::Quaternion& itgr );
  void triangleCallback( const geometry_msgs::Transform& triangle );
  void reactiveCtrlCallback( const geometry_msgs::Transform& reactiveCtrl ); 
  void publishControlState( int state );
  void signalLED( hovercraft::LED& led, bool green, int blink );
  void stateChange( int state );

  //Class variables
  bool lift_on;
  int state;
  int previous_state;

}; /* end class declaration */

//---------------------------------------------------------------------

//Class Constructor
Arbitrator::Arbitrator()
{
  //Set subscribers and publishers
  joy_sub_ = nh_.subscribe("joy", 10, &Arbitrator::joyCallback, this);
  joyAngleItgr_sub_ = nh_.subscribe("joyAngleIntegrater/Data", 10, &Arbitrator::joyAngleItgrCallback, this);
  triangle_sub_ = nh_.subscribe("triangle/Data", 10, &Arbitrator::triangleCallback, this);
  reactivectrl_sub_ = nh_.subscribe("reactivecontrol/Control", 10, &Arbitrator::reactiveCtrlCallback, this);

  arb_pub_ = nh_.advertise<geometry_msgs::Transform>("arbitrator/Data", 1);
  ctrl_pub_ = nh_.advertise<reactivecontrol::Control>("arbitrator/Control", 1);
  led_pub_ = nh_.advertise<hovercraft::LED>("hovercraft/LED", 1);

  //Set class variables
  lift_on = false;
  state = MANUAL_STATE;
  previous_state = MANUAL_STATE;

} /* end class constructor */

//---------------------------------------------------------------------

/* Arbitrator::joyCallback()
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
      previous_state = state;
      state = AUTO_STATE;
      stateChange( state );
    }
    else
    {
      previous_state = state;
      state = MANUAL_STATE;
      stateChange( state );
    }

  }

  //Automatic right rotation
  if( float( joy->buttons[XBOX_R_BUMPER] ) == 1 &&
      state != TRIANGLE_STATE )
  {
    previous_state = state;
    state = TURN_R_STATE;
    stateChange( state );
  }

  //Automatic left rotation
  if( float( joy->buttons[XBOX_L_BUMPER] ) == 1 &&
      state != TRIANGLE_STATE )
  {
    previous_state = state;
    state = TURN_L_STATE;
    stateChange( state );
  }

  //Automatic triangle execution (only allowed in auto mode)
  if( float( joy->buttons[XBOX_Y_BTN] ) == 1 )
  {
    //return to previous state
    if( state == TRIANGLE_STATE )
    {
      state = previous_state;
      stateChange( state );
    }
    //begin triangle execution
    else
    {
      previous_state = state;
      state = TRIANGLE_STATE;
      stateChange( state );
    }

  }

  //Update current translational motion
  arb_data.translation.x = joy->axes[XBOX_RS_X_AXIS];
  if( state != TRIANGLE_STATE )
  {
    arb_data.translation.y = joy->axes[XBOX_RS_Y_AXIS];
  }

  //Turn on/off LEDs according to controller buttons
  led_on.led33_green = float( joy->buttons[XBOX_A_BTN] );
  led_on.led33_red = float( joy->buttons[XBOX_B_BTN] );

  arb_pub_.publish( arb_data );
  led_pub_.publish( led_on );

} /* end method Arbitrator::joyCallback() */

//---------------------------------------------------------------------

/* Arbitrator::joyAngleItgrCallback()
 *   Updates the target angle for the PID according to
 *   changes from the joyAngleIntegrater node.
 */
void Arbitrator::joyAngleItgrCallback( const geometry_msgs::Quaternion& itgr )
{
  if( state != TRIANGLE_STATE)
  {
    arb_data.rotation.w = itgr.w;
    arb_pub_.publish( arb_data );
  }

} /* end method Arbitrator::joyAngleItgrCallback() */

//---------------------------------------------------------------------

/* Arbitrator::triangleCallback()
 *  Updates the target angle and forward momentum for the PID
 *  as directed by the triangle node.
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

/* Arbitrator::reactiveCtrlCallback()
 *   Updates the forward momentum for the PID as directed
 *   by the reactivecontrol node.
 */
void Arbitrator::reactiveCtrlCallback( const geometry_msgs::Transform& reactiveCtrl )
{

  if( state == AUTO_STATE )
  {
    arb_data.translation.y = reactiveCtrl.translation.y;
    arb_pub_.publish( arb_data );
  }

} /* end method Arbitrator::reactiveCtrlCallback() */

//---------------------------------------------------------------------

/* Arbitrator::publishControlState()
 *   Publishes the current control state of the arbitrator.
 */
void Arbitrator::publishControlState( int state )
{

  ctrl_state.state = state;
  ctrl_pub_.publish( ctrl_state );

} /* end method Arbitrator::publishControlState() */

//---------------------------------------------------------------------
 
/* Arbitrator::signalLED()
 *   Flashes an LED on the hovercraft.
 */
void Arbitrator::signalLED( hovercraft::LED& led, bool green, int blink )
{
  int i;
  for( i = 0; i < blink; i++ )
  {
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

    ros::Duration(0.2).sleep(); //sleep for 20ms
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

} /* end method Arbitrator::signalLED() */

//---------------------------------------------------------------------

/* Arbitrator::stateChange()
 *   Displays a message on the console output and with the
 *   hovercraft LEDs to signal the current control state.
 */
void Arbitrator::stateChange( int state )
{
  publishControlState( state );
  switch( state )
  {
    case MANUAL_STATE:
      ROS_INFO("State = Manual");
      ROS_INFO("  --> Press Back button to return to Auto");
      ROS_INFO("  --> Press Y button to begin Triangle");
      signalLED( led_on, true, 3 ); //flash green led 3 times
      break;
    case AUTO_STATE:
      ROS_INFO("State = Auto");
      ROS_INFO("  --> Press Back button to return to Manual");
      ROS_INFO("  --> Press Y button to begin Triangle");
      signalLED( led_on, false, 3 ); //flash red led 3 times
      break;
    case TRIANGLE_STATE:
      ROS_INFO("State = Triangle");
      ROS_INFO("  --> Press Y button to end Triangle");
      signalLED( led_on, true, 1 ); //flash led green, red, green pattern
      signalLED( led_on, false, 1 );
      signalLED( led_on, true, 1 );
      break;
    case TURN_R_STATE:
    case TURN_L_STATE:
      state = previous_state;
    default:
      break;
  }

} /* end method Arbitrator::stateChange() */

//---------------------------------------------------------------------

//Main Function
int main(int argc, char** argv)
{

  ros::init(argc, argv, "arbitrator");
  Arbitrator arbi;
  ros::spin();

  return 0;

} /* end main function */

