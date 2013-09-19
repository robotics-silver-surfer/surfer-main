#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <hovercraft/Thruster.h>
#include <hovercraft/Gyro.h>

#define LSXAXIS 0 
#define LSYAXIS 1



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


  thruster_pub_ = nh_.advertise<hovercraft::Thruster>("hovercraft/Thruster", 1);


  joy_sub_ = nh_.subscribe<sensor_msgs::Joy>("joy", 10, &TeleopHover::joyCallback, this);

}

void TeleopHover::joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
{
 
  hovercraft::Thruster thrust;
 
  /**
  Thrust Control 
  axes go from -1 to 1 
  LS = Left Stick, RS = Right Stick 
  axes: [ LS X, LS Y, L Trigger, RS X, RS Y, R Trigger] 
  buttons: [ A, B, X, Y, LB, RB, Back, Start, XBOX, D pad L, D pad R, D pad Up, D pad Down ]
  **/  

  /* 

	thruster1 = back thruster
	thruster2 = Left front thruster
	thruster3 = Not attached
	thruster4 = right fron thruster
	thruster5 = Rotate Counter Clockwise
	thruster6 = Rotate Clockwise
  */ 

  /* Emergency Kill logic */ 
  if( float(joy->buttons[8]) == 0 ) 
  {
    thrust.lift = 0;
    thrust.thruster1 = 0;
    thrust.thruster2 = 0;
    thrust.thruster3 = 0;
    thrust.thruster4 = 0;
    thrust.thruster5 = 0; 
    thrust.thruster6 = 0;
  }
  
  /*  Power Button Logic */ 
  if( joy->buttons[7] == 1 )
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
  
  /* Translational  logic */ 
  if( float(joy->axes[5]) > 0 )
  {
   thrust.thruster1 = .3 * float( joy->axes[4] ); 
  }

  /* Turning Logic */ 
  if( float(joy->axes[0]) > 0 )
  {
   thrust.thruster5 = 1.0 * (.2 * float( joy->axes[0] ) );
   thrust.thruster6 = 0; 
  }else
  {
   thrust.thruster6 = -1.0 * (.2 * float( joy->axes[0] ) );
   thrust.thruster5 = 0; 
  }
  
  /* Publish the thrust message */ 
  thruster_pub_.publish(thrust);
  
  
}


int main(int argc, char** argv)
{
  ros::init(argc, argv, "teleop_hover");
  TeleopHover teleop_Hover;

  ros::spin();
}
