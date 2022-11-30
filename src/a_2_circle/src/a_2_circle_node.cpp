#include <ros/ros.h>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "my_circle_thing");
    
    tf2_ros::TransformBroadcaster br;

    /*Creates a transform object*/
    geometry_msgs::TransformStamped out_tf;

    /*Initialising the rotation*/
    int rot = 0;

    /*Create Vector3 with default values*/
    geometry_msgs::Vector3 v3;
    v3.x = 1;
    v3.y = 0;
    v3.z = 0;

    /*Create Quaternion*/
    geometry_msgs::Quaternion q4;
    /*0,0,0,0 is not valid, because its length has to equal 1 */
    q4.x = 0;
    q4.y = 0;
    q4.z = 0;
    q4.w = 1;

    /*Frequency of publish*/
    ros::Rate rate(4);

    while(ros::ok())
    {
        v3.x = cos(rot);
        v3.y = sin(rot);

        out_tf.header.stamp = ros::Time::now();
        out_tf.header.frame_id = "/world";
        
        out_tf.child_frame_id = "/base_link";

        /*Where is the child? (vektor3)*/
        out_tf.transform.translation =  v3;
        /*Where is the childs head? (quaternion)*/ 
        out_tf.transform.rotation = q4;  

        rot++;

        /*Sents to /tf*/
        br.sendTransform(out_tf);

        ros::spinOnce();
        rate.sleep();
    }

}