#include <ros/ros.h>
#include <geometry_msgs/Transform.h>
#include <math.h>

//Go little one 
class triangle
{
public:
  triangle();
private:
  ros::NodeHandle nh_;
  ros::Publisher arbi_pub_;
  ros::Timer timer;
  geometry_msgs::Transform hereComesTheSun;
  
  void timerCallback(const ros::TimerEvent&);
  
  int side;
  
};

triangle::triangle()
{ 
  //The timer is going to publish the message every 3 seconds
  timer = nh_.createTimer(ros::Duration(3.0), &triangle::timerCallback,this);
  arbi_pub_ = nh_.advertise<geometry_msgs::Transform>("triangle/Data", 1);
  
  side = 0;
  
}

void triangle::timerCallback(const ros::TimerEvent&)
{
  switch(side)
  {
    case 0:
      hereComesTheSun.translation.x = 0.0;
      hereComesTheSun.translation.y = 0.0;
      hereComesTheSun.translation.z = 0.5;
      hereComesTheSun.rotation.x = 120.0;
      break;
    case 1:
      hereComesTheSun.translation.x = 0.0;
      hereComesTheSun.translation.y = 0.4;
      hereComesTheSun.translation.z = 0.5;
      hereComesTheSun.rotation.x = 0.0;
      break;
    case 2:
      hereComesTheSun.translation.x = 0.0;
      hereComesTheSun.translation.y = 0.0;
      hereComesTheSun.translation.z = 0.0;
      hereComesTheSun.rotation.x = 0.0;
      break;
    case 3:
      hereComesTheSun.translation.x = 0.0;
      hereComesTheSun.translation.y = 0.0;
      hereComesTheSun.translation.z = 0.5;
      hereComesTheSun.rotation.x = 120.0;
      break;
    case 4:
      hereComesTheSun.translation.x = 0.0;
      hereComesTheSun.translation.y = 0.4;
      hereComesTheSun.translation.z = 0.5;
      hereComesTheSun.rotation.x = 0.0;
      break;
    case 5:
      hereComesTheSun.translation.x = 0.0;
      hereComesTheSun.translation.y = 0.0;
      hereComesTheSun.translation.z = 0.0;
      hereComesTheSun.rotation.x = 0.0;
      break;
    case 6:
      hereComesTheSun.translation.x = 0.0;
      hereComesTheSun.translation.y = 0.0;
      hereComesTheSun.translation.z = 0.5;
      hereComesTheSun.rotation.x = 120.0;
      break;
    case 7:
      hereComesTheSun.translation.x = 0.0;
      hereComesTheSun.translation.y = 0.4;
      hereComesTheSun.translation.z = 0.5;
      hereComesTheSun.rotation.x = 0.0;
      break;
    default:
      hereComesTheSun.translation.x = 0.0;
      hereComesTheSun.translation.y = 0.0;
      hereComesTheSun.translation.z = 0.0;
      hereComesTheSun.rotation.x = 0.0;
      break;
  }

  arbi_pub_.publish(hereComesTheSun);
  
  side++;
  if(side > 8)
    side = 0;
}

int main (int argc, char** argv)
{
  int cont = 0;
  ros::init(argc, argv, "triangleMode");
  triangle triangleMode;
  
  ros::spin();
  
  return 0;
}
