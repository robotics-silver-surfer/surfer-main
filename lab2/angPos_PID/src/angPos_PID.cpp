#include <ros/ros.h>
#include <hovercraft/Gyro.h>
#include <std_msgs/Float64.h>
#include <arbitrator/ArbAngle.h>
#include <math.h>

//It's implemented a PD controller.
//The value for Kp is 0.002
//The value for Kd is 0.043
//This node receives a message from the arbitrator
//The message is a Float64.
//It sends the same message type to the thrusterMapping

class anglePID
{
public:
  anglePID();
private:
  
  ros::NodeHandle nh_;
  //Subscriber for the arbitrator (The message is Float64)
  ros::Subscriber arbi_sub_;
  //Subscriber for the gyroscope
  ros::Subscriber gyro_sub_;
  //Publisher for the node 
  ros::Publisher angle_pub_;
  //Messages(Float64)
  std_msgs::Float64 pidOutput;
  
  void gyroCallback(const hovercraft::Gyro::ConstPtr& gyro);
  void angleCallback(const std_msgs::Float64::ConstPtr& wannaBeAngle);
  void PID_controller(void);
  
  double Kp;
  double Kd;
  double newAngle;
  double oldAngle;
  double desiredAngle;
  
};

anglePID::anglePID()
{
  arbi_sub_ = nh_.subscribe("arbitrator/ArbAngle", 10, &anglePID::angleCallback, this);
  gyro_sub_ = nh_.subscribe("hovercraft/Gyro", 10, &anglePID::gyroCallback, this);
  angle_pub_ = nh_.advertise<std_msgs::Float64>("pidOutput", 1);
  
  newAngle = 0;
  oldAngle = 0;
  Kp = 0.002;
  nh_.param("angCtrl/P", Kp,Kp);
  Kd = 0.043;
  nh_.param("angCtrl/D", Kd,Kd);
}


//Function that  checks the
void anglePID::gyroCallback( const hovercraft::Gyro::ConstPtr& gyro)
{
  //THis part corrects the value of the angle.
  oldAngle = newAngle;
  newAngle = gyro->angle;
  anglePID::PID_controller();
}

//This function receives the desired angle from the arbitrator
void anglePID::angleCallback (const std_msgs::Float64::ConstPtr& wannaBeAngle)
{
   desiredAngle = wannaBeAngle->data; 
}


//Function that implements the PD controller
void anglePID::PID_controller(void)	
{
  double P,D,e1,e2;

  e1 = (desiredAngle - newAngle);
  P = Kp*e1;
  e2 = (desiredAngle - oldAngle);
  D =  Kd*(e1-e2);

  pidOutput.data = P + D;

  angle_pub_.publish(pidOutput);

}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "PIDi");
  anglePID PIDi;
  
  ros::spin();
  
  return 0;
  
}


