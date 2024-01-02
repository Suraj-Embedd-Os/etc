/******************************************************************************\
*@file : cam_image_sub.cpp
*
*@brief : File description for cam_image_sub.cpp file
* 
*@detail : This file consist of the main method for the subscriber node.
*
*@remark : 
*	Change History:
*	  1. Initial Creation
\******************************************************************************/

/******************************************************************************\
 *                  Include header files from standard path                    *
\******************************************************************************/
#include <ros/ros.h>
#include <image_transport/image_transport.h>

/******************************************************************************\
 *                  Include header files from project path                    *
\******************************************************************************/
#include "camera_ros/camera.h"


/******************************************************************************\
 *               Extern function definition in alphabetical order             * 
\******************************************************************************/

/******************************************************************************\
 *@brief : Main method for the subscriber node.
 *
 *@remark :
 *	Change History:
 *	  1. Initial Creation
 *
\******************************************************************************/
std::string pathname="";
int main(int argc, char** argv)
{
    ros::init(argc, argv, "imageSub_node");  	// Register node name 
    ros::NodeHandle nh("~"); 			// register handle
	
	pathname = nh.param("pathname", std::string{});
	ROS_INFO("Camera pathname %s", pathname.c_str());
	
    image_transport::ImageTransport it(nh); 	// register handle
    image_transport::Subscriber imageSub = it.subscribe("/camera", 100, imageCallback);  // Subscribe to the /cameraImage topic and add a callback function
    ros::spin();  // loop waiting for the callback function to trigger
}



