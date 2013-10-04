#include <ros/ros.h>
#include <hovercraft/Gyro.h>
#include <std_msgs/Float64.h>
#include <arbitrator/ArbAngle.h>
#include <math.h>

           
    
   //This is working now, nice 
class anglePID
{
public:
  anglePID();
private:
  
  ros::NodeHandle nh_;
  //Suscriber for the arbitrator
  ros::Subscriber arbi_sub_;
  ros::Subscriber gyro_sub_;
  //Publisher for the node 
  ros::Publisher angle_pub_;
  //Messages
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
  Kp = 0.5;
  nh_.param("angCtrl/P", Kp,Kp);
  Kd = 0.75;
  nh_.param("angCtrl/D", Kd,Kd);
}

void anglePID::gyroCallback( const hovercraft::Gyro::ConstPtr& gyro)
{
  //THis part corrects the value of the angle.
  oldAngle = newAngle;
  newAngle = gyro->angle;
  anglePID::PID_controller();
}

void anglePID::angleCallback (const std_msgs::Float64::ConstPtr& wannaBeAngle)
{
   desiredAngle = wannaBeAngle->data; 
}

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


