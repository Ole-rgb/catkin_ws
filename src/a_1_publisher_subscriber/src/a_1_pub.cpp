#include <ros/ros.h>
#include <std_msgs/String.h>

int main(int argc, char **argv){
    ros::init(argc, argv, "my_awsome_node");
    ros::NodeHandle nh;

    //create all sonts of pub/sub etc. here
    ros::Publisher pub = nh.advertise<std_msgs::String>("/my_text", 5);


    ros::Rate rate(2.0);

    while (ros::ok())
    {
        std_msgs::String msg;
        msg.data = "This is my message";

        pub.publish(msg);
        
        ros::spinOnce();
        rate.sleep();
    }
}