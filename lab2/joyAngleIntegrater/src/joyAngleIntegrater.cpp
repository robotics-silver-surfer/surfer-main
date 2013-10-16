/* Hiya!
 *
 */

//Libraries and Packages
#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <std_msgs/Float64.h>
#include <hovercraft/Gyro.h>
#include <geometry_msgs/Quaternion.h>

//Xbox Joystick Constants
#define XBOX_LS_X_AXIS  0

//Class Declaration
class JoyAngleIntegrater
{
public:
  JoyAngleIntegrater();

private:
  //Node subscribers and publishers
  ros::NodeHandle nh_;

  ros::Publisher itgrData_pub_;

  ros::Subscriber joy_sub_;
  ros::Subscriber gyro_sub_;

  //Published messages
  geometry_msgs::Quaternion itgr_data;

  //Class functions
  void joyCallback( const sensor_msgs::Joy::ConstPtr& joy );
  void gyroUpdate( const hovercraft::GyroConstPtr& gyro );
  void integrate( const ros::TimerEvent& event );

  //Class variables
  ros::Timer timer;
  float previous_ang_rate;
  float current_ang_rate;
  float previous_angle;
  float current_angle;
  float target_angle;

}; /* end class declaration */

//---------------------------------------------------------------------

//Class Constructor
JoyAngleIntegrater::JoyAngleIntegrater()
{

  //Set subscribers and publishers
  joy_sub_ = nh_.subscribe("joy", 10, &JoyAngleIntegrater::joyCallback, this);
  gyro_sub_ = nh_.subscribe("hovercraft/Gyro", 10, &JoyAngleIntegrater::gyroUpdate, this);
  itgrData_pub_ = nh_.advertise<geometry_msgs::Quaternion>("joyAngleIntegrater/Data", 1);

  //Set class variables
  timer = nh_.createTimer(ros::Duration(0.1), &JoyAngleIntegrater::integrate, this);
  previous_ang_rate = 0.0;
  current_ang_rate = 0.0;
  previous_angle = 0.0;
  current_angle = 0.0;
  target_angle = 0.0;

} /* end class constructor */

//---------------------------------------------------------------------

/* JoyAngleIntegrater::joyCallback
 *   Sets class variables according to changes on the controller.
 */
void JoyAngleIntegrater::joyCallback( const sensor_msgs::Joy::ConstPtr& joy )
{

  previous_ang_rate = current_ang_rate;
  current_ang_rate = (float) joy->axes[XBOX_LS_X_AXIS];

} /* end method JoyAngleIntegrater::joyCallback() */

//---------------------------------------------------------------------

/* JoyAngleIntegrater::gyroUpdate
 *   <description>
 */
void JoyAngleIntegrater::gyroUpdate( const hovercraft::Gyro::ConstPtr& gyro )
{

//  previous_angle = current_angle;
  current_angle = (float) gyro->angle;

} /* end method JoyAngleIntegrater::gyroUpdate() */

//---------------------------------------------------------------------

/* JoyAngleIntegrater::integrate
 *   <description>
 */
void JoyAngleIntegrater::integrate( const ros::TimerEvent& event )
{

//  if( current_angle != previous_angle )
//  {
    target_angle = current_angle + ( current_ang_rate - previous_ang_rate );
    itgr_data.w = target_angle;
//  }
  itgrData_pub_.publish( itgr_data );

} /* end method JoyAngleIntegrater::integrate) */

//---------------------------------------------------------------------


//Main Function
int main(int argc, char** argv)
{

  ros::init(argc, argv, "joyAngleIntegrater");
  JoyAngleIntegrater joyAngItgr;
  ros::spin();

  return 0;

} /* end main function */
