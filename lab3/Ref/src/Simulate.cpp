#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <math.h>
#include <vector>
#include <pthread.h>
#include <Ref/controls.h>
#include <Ref/Position.h>
#include <Ref/HoverBot.h>
#include <Ref/image.h>
#include <Ref/BotStatus.h>
#include <Ref/BotToRef.h>
#include <hoverTracker/Tag.h>
#include <hoverTracker/TagArray.h>

ros::Publisher tag_pub;

void callback(const ros::TimerEvent& e){
	hoverTracker::TagArray tagarray;
	std::vector<hoverTracker::Tag> tags;
	int i;	
	for(i=0; i<10; i++){
		hoverTracker::Tag tag;
		tag.id = i;
		tag.x = rand() % 1200;
		tag.y = rand() % 800;
		tag.angle = rand() % 360;
		tags.push_back(tag);
	}
	tagarray.size = 10;
	tagarray.tag = tags;
	tag_pub.publish(tagarray);
	
}

int main(int argc, char **argv){
	ros::init(argc, argv, "Simulate");
	ros::NodeHandle nh;
	tag_pub = nh.advertise<hoverTracker::TagArray>("Simulate/hoverLocation",1);
	ros::Timer timer2 = nh.createTimer(ros::Duration(1.0), callback);
	ros::spin();
	return 0;
}
