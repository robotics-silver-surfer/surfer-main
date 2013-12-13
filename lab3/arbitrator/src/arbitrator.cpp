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
#define TURN_R_STATE	2
#define TURN_L_STATE	3
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
#define XBOX_DPAD_LEFT	11
#define XBOX_DPAD_RIGHT	12
#define XBOX_DPAD_UP	13
#define XBOX_DPAD_DOWN	14

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
  ros::Subscriber pathPlan_sub_;

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
  void pathPlanCallback( const geometry_msgs::Transform& path );
  void publishControlState( int state_change );
  void signalLED( hovercraft::LED& led, bool green, bool red, int blink );
  void stateChange( int state_change );

  //Class variables
  bool lift_on;
  int state;
  int auto_state;

}; /* end class declaration */

//---------------------------------------------------------------------

//Class Constructor
Arbitrator::Arbitrator()
{
  //Set subscribers and publishers
  joy_sub_ = nh_.subscribe("joy", 10, &Arbitrator::joyCallback, this);
  joyAngleItgr_sub_ = nh_.subscribe("joyAngleIntegrater/Data", 10, &Arbitrator::joyAngleItgrCallback, this);
  pathPlan_sub_ = nh_.subscribe("pathPlan/Command", 10, &Arbitrator::pathPlanCallback, this);
  

  arb_pub_ = nh_.advertise<geometry_msgs::Transform>("arbitrator/Data", 1);
  ctrl_pub_ = nh_.advertise<reactivecontrol::Control>("arbitrator/Control", 1);
  led_pub_ = nh_.advertise<hovercraft::LED>("hovercraft/LED", 1);

  //Set class variables
  lift_on = false;
  state = MANUAL_STATE;

} /* end class constructor */

//---------------------------------------------------------------------

/* Arbitrator::pathPlanCallback()
 *   Sets class variables according to magical path plan
 */
void Arbitrator::pathPlanCallback( const geometry_msgs::Transform& path  )
{
	if( state == AUTO_STATE )
	  {
		arb_data.translation.z = path.translation.z;
		arb_data.translation.x = path.translation.x;
		arb_data.translation.y = path.translation.y;
		arb_data.rotation.w = path.rotation.w;
		arb_pub_.publish( arb_data );
	  }
}
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
  if( float( joy->buttons[XBOX_X_BTN] == 1) )
  {
	state = AUTO_STATE;
    stateChange( state );

/*
    if( state == MANUAL_STATE )
    {
      state = AUTO_STATE;
      stateChange( state );
    }
    else
    {
      state = MANUAL_STATE;
      stateChange( state );
    } */

  }
  if( float( joy->buttons[XBOX_BACK_BTN] == 1) )
  {
	state = MANUAL_STATE;
    stateChange( state );
  }

  //Automatic right rotation
  if( float( joy->buttons[XBOX_R_BUMPER] ) == 1 )
  {
    state = TURN_R_STATE;
    stateChange( state );
  }

  //Automatic left rotation
  if( float( joy->buttons[XBOX_L_BUMPER] ) == 1 )
  {
    state = TURN_L_STATE;
    stateChange( state );
  }

  //Update current translational motion
  if( state != AUTO_STATE )
  {
    arb_data.translation.x = joy->axes[XBOX_RS_X_AXIS];
    arb_data.translation.y = joy->axes[XBOX_RS_Y_AXIS];
  }

  //Turn on/off LEDs according to controller buttons
  if( state != AUTO_STATE )
  {
    led_on.led33_green = float( joy->buttons[XBOX_A_BTN] );
    led_on.led33_red = float( joy->buttons[XBOX_B_BTN] );
  }

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
  if( state == MANUAL_STATE )
  {
    arb_data.rotation.w = itgr.w;
    arb_pub_.publish( arb_data );
  }

} /* end method Arbitrator::joyAngleItgrCallback() */

//---------------------------------------------------------------------

/* Arbitrator::publishControlState()
 *   Publishes the current states of the arbitrator.
 */
void Arbitrator::publishControlState( int state_change )
{
  if( state_change >= 0 )
  {
    ctrl_state.state = state;
  }
  ctrl_pub_.publish( ctrl_state );

} /* end method Arbitrator::publishControlState() */

//---------------------------------------------------------------------
 
/* Arbitrator::signalLED()
 *   Flashes an LED on the hovercraft.
 */
void Arbitrator::signalLED( hovercraft::LED& led, bool green, bool red, int blink )
{
  //start with LEDs off
  led.led33_green = LED_OFF;
  led.led33_red = LED_OFF;
  led_pub_.publish( led_on );

  int i;
  if( blink > 0 )
  {
    for( i = 0; i < blink; i++ )
    {
      ros::Duration(0.2).sleep(); //sleep for 20ms
      if( green )
      {
        led.led33_green = LED_ON;
      }
      if( red )
      {
        led.led33_red = LED_ON;
      }
    
      led_pub_.publish( led_on );

      ros::Duration(0.2).sleep(); //sleep for 20ms
      if( green )
      {
        led.led33_green = LED_OFF;
      }
      if( red )
      {
        led.led33_red = LED_OFF;
      }
    
      led_pub_.publish( led_on );
    }
  }
  //Negative blinks = hold LED on
  else if( blink < 0 )
  {
      if( green )
      {
        led.led33_green = LED_ON;
      }
      if( red )
      {
        led.led33_red = LED_ON;
      }

      led_pub_.publish( led_on );
  }

} /* end method Arbitrator::signalLED() */

//---------------------------------------------------------------------

/* Arbitrator::stateChange()
 *   Displays a message on the console output and with the
 *   hovercraft LEDs to signal the current control state.
 */
void Arbitrator::stateChange( int state_change )
{
  publishControlState( state_change );
  switch( state_change )
  {
    case MANUAL_STATE:
      ROS_INFO("State = Manual");
      ROS_INFO("  --> Press X button to return to Auto");
      signalLED( led_on, true, false, 3 ); //flash green led 3 times
      break;
    case AUTO_STATE:
      ROS_INFO("State = Auto: Path Planning");
      ROS_INFO("  --> Press Back button to return to Manual");
      signalLED( led_on, false, true, 3 ); //flash red led 3 times
  } //end switch state_change

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

