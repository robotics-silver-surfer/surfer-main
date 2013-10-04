#include <ros/ros.h>
#include <hovercraft/Thruster.h>
#include <hovercraft/Gyro.h>
#include <std_msgs/Float64.h>

class anglePID
{
public:
  anglePID();
private:
  Float64 gyroCallback(const hovercraft::Gyro::ConstPtr& gyro);
  Float64 angleCallback(const arbitrator::ArbAngle::ConstPtr& wannaBeAngle);
  void PID_controller(float actualAngle, float desiredAngle);
  
  ros::NodeHandle nh_;
  //Suscriber for the arbitrator
  ros::Suscriber arbi_sub_;
  ros::Suscriber gyro_sub_;
  //Publisher for the node 
  ros::Publisher angle_pub_;
  //Messages
  Float64::PID_output;
};

anglePID::anglePID():
{
  arbi_sub = nh_.suscribe("arbitrator/ArbAngle", 10, &Arbitrator::angleCallback, this);
  gyro_sub_ = nh_.suscribe("hovercraft/Gyro", 10, &TeleopHover::gyroCallback, this);
  angle_pub_ = nh.advertise("PID_output", 1);
}

float anglePID::gyroCallback( const hovercraft::Gyro::ConstPtr& gyro)
{
  //THis part corrects the value of the angle.
  if(gyro->angle > 360)
  {
    gyro->angle = 0;
  }
  if(gyro->angle < 0)
  {
    gyro->angle = 360;
  }
  
  return gyro->angle;
}

float anglePID::angleCallback (const arbitrator::ArbAngle::ConstPtr& newAngle)
{
   if(wannaBeAngle->angle > 360)
   {
     wannaBeAngle->angle = 0;
   }
   if(wannaBeAngle->angle < 0)
   {
     wannaBeAngle->angle = 360;
   }
   
   return wannaBeAngle->angle;
  
}

void anglePID::PID_controller(float actualAngle, float desiredAngle)
{
  
  Float64 Kp = 0.5;
  Float64 Kd = 0.75;
  Float64 P,D,r,e1,e2;
  Float64 *newAng;
  
  e1 = desiredAngle - actualAngle;
  
  P = Kp*e1;
  
  e2 = desiredAngle - anglePID::gyroCallback(newAng);
  
  D =  Kd*(e1-e2);
  
  PID_output.r = P + D;
  
  angle_pub_.publish(PID_output);
  
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "angPos_PID");
  anglePID angle_PID;
  
  ros::spin();
  
}


