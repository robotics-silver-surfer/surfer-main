surfer-main
===========


Attention Fellow Classmates! 

There is an issue when copying files to a different directory from when they were made.  
In order to solve this problem, you can either run "rosmake --pre-clean"  any time you checkout someones new files, or, the better solution, we all create the same directory to our packages.  

My projects are now currently stored in /projects/ros/

___To Checkout the files intially
__Run the following:
 
sudo mkdir /projects

sudo chmod 775 /projects

sudo chown YourUSERNAMEHERE /projects

mkdir /projects/ros

__Add to your .bashrc file at the bottom (If you have already downloaded lab1 you may have to delete it) 

export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:/projects/ros 

__RESTART your terminal 

__Then run the following commands: 

sudo apt-get install ros-groovy-joy

cd /projects/ros

git clone https://github.com/robotics-silver-surfer/surfer-main.git

__After the files have been checked out GOTO: 

cd /projects/ros/surfer-main/lab1/hoverteleop

__And run 

rosmake --pre-clean

__And it should build


"git checkout" to checkout files
and 
"git commit 'FIles to commit'" and then "get push origin HEAD" to checkin files to the Git Repo 

Additional Notes: 

Make sure to set the joystick param for your computer

in hoverteleop.launch  "/dev/input/jsX"
