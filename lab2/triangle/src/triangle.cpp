#include <ros/ros.h>
#include <hovercraft/Gyro.h>
#include <geometry_msgs/Transform.h>
#include <math.h>

//Go little one, go!
class triangle
{
public:
  triangle();
private:
  ros::NodeHandle nh_;
  ros::Publisher arbi_pub_;
  ros::Timer timer;
  ros::Subscriber gyro_sub_;
  geometry_msgs::Transform hereComesTheSun;

  void timerCallback(const ros::TimerEvent&);
  void gyroCallback(const hovercraft::Gyro::ConstPtr& gyro);

  int side;
  int save;
  double actualAngle;
  double startAngle;

};

triangle::triangle()
{
  //The timer is going to publish the message every second
  timer = nh_.createTimer(ros::Duration(3.0), &triangle::timerCallback,this);
  arbi_pub_ = nh_.advertise<geometry_msgs::Transform>("triangle/Data", 1);
  gyro_sub_ = nh_.subscribe("hovercraft/Gyro",10, &triangle::gyroCallback,this);

  side = 0;
  save = 0;
  actualAngle = 0;
  startAngle = 0;

}

void triangle::gyroCallback( const hovercraft::Gyro::ConstPtr& gyro)
{
  actualAngle = gyro->angle;
  if(save == 0)
  {
    startAngle = actualAngle;
    save = 1;
  }
}

void triangle::timerCallback(const ros::TimerEvent&)
{
  switch(side)
  {
    case 0:
      hereComesTheSun.translation.y = 0.5;
      hereComesTheSun.rotation.w = startAngle;
      break;
    case 1:
      hereComesTheSun.translation.y = -0.3;
      hereComesTheSun.rotation.w = startAngle;
      break;
    case 2:
      hereComesTheSun.translation.y = 0.0;
      startAngle = startAngle + 60;
      hereComesTheSun.rotation.w = startAngle;
      break;
    case 3:
      hereComesTheSun.translation.y = 0.0;
      startAngle = startAngle + 60;
      hereComesTheSun.rotation.w = startAngle;
      break;
    default:
      hereComesTheSun.translation.y = 0.0;
      hereComesTheSun.rotation.w = actualAngle;
      break;
  }

  arbi_pub_.publish(hereComesTheSun);

  side++;
  if(side > 3)
    side = 0;
}

int main (int argc, char** argv)
{
  ros::init(argc, argv, "triangle");
  triangle triangleMode;
  ros::spin();

  return 0;
}
