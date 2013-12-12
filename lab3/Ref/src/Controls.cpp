#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <math.h>
#include <vector>
#include <Ref/controls.h>
#include <Ref/BotToRef.h>

//axes indices
#define JS_LEFT_X 0
#define JS_LEFT_Y 1
#define L_TRIGGER 2
#define JS_RIGHT_X 3
#define JS_RIGHT_Y 4
#define R_TRIGGER 5

//buttons indices
#define A_BUTTON 0
#define B_BUTTON 1
#define X_BUTTON 2
#define Y_BUTTON 3
#define L_BUMPER 4
#define R_BUMPER 5
#define BACK_BUTTON 6
#define START_BUTTON 7
#define SYNC_BUTTON 8
#define JS_LEFT_BUTTON 9
#define JS_RIGHT_BUTTON 10
#define D_PAD_LEFT 11
#define D_PAD_RIGHT 12
#define D_PAD_UP 13
#define D_PAD_DOWN 14


class Controls {
public:
	Controls();
private:
	ros::NodeHandle nh;

	ros::Subscriber joy_sub;
	void joyCallback(const sensor_msgs::Joy::ConstPtr& data);

	ros::Publisher ref_pub;
	ros::Publisher test_pub[3];
};

Controls::Controls(void){
	joy_sub = nh.subscribe("joy",1,&Controls::joyCallback,this);

	ref_pub = nh.advertise<Ref::controls>("control",1);

	test_pub[0] = nh.advertise<Ref::BotToRef>("/Team1/FromTeam",1);
	test_pub[1] = nh.advertise<Ref::BotToRef>("/Team2/FromTeam",1);
	test_pub[2] = nh.advertise<Ref::BotToRef>("/Team3/FromTeam",1);
}

bool started = false;
bool team1 = false;
bool team2 = false;
bool team3 = false;

void Controls::joyCallback(const sensor_msgs::Joy::ConstPtr& data){
	Ref::controls controls;
	controls.header = data->header;
	std::vector<uint8_t> test;
	int start = data->buttons[START_BUTTON];
	//int a = data->buttons[A_BUTTON];
	int b = data->buttons[B_BUTTON];
	int x = data->buttons[X_BUTTON];
	int y = data->buttons[Y_BUTTON];

	int l = data->buttons[D_PAD_LEFT];
	int r = data->buttons[D_PAD_RIGHT];
	int u = data->buttons[D_PAD_UP];
	
	Ref::BotToRef btr;
	btr.header = data->header;
	if(l == 1){
		btr.botID=0;
		test_pub[0].publish(btr);
	}else if(u == 1){
		btr.botID=1;
		test_pub[1].publish(btr);
	}else if(r == 1){
		btr.botID=2;
		test_pub[2].publish(btr);
	}

	if(!started){
		if(start == 1){
			started = true;
			team1 = true; team2 = true; team3 = true;

		}
	}else{
		team1 = (x == 1);
		team2 = (y == 1);
		team3 = (b == 1);
/*		if(x == 1){
			team1 = !team1;
		}
		if(y == 1){
			team2 = !team2;
		}
		if(b == 1){
			team3 = !team3;
		}*/
	}
	test.push_back(team1);
	test.push_back(team2);
	test.push_back(team3);
	controls.liftchanges = test; 
//	controls.lifts[0] = team1;
//	controls.lifts[1] = team2;
//	controls.lifts[2] = team3;
	ref_pub.publish(controls);
}

int main(int argc, char **argv){
	ros::init(argc, argv, "Controls");
	Controls cont;
  ros::spin();
  return 0;
}






