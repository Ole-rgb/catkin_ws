#include <ros/ros.h>
#include <std_msgs/String.h>

void callback(std_msgs::String msg){
    ROS_INFO("The message is: [%s]", msg.data);
}


int main(int argc, char **argv){
    ros::init(argc, argv, "my_sub");
    ros::NodeHandle nh;

    ros::Subscriber sub =  nh.subscribe("/my_text", 10, callback);

    ros::spin();

}