/******************************************************************************\
*@file : camera.cpp
*
*@brief : File description for camera.cpp file
* 
*@detail : This file consist of callback methods.
*
*@remark : 
*	Change History:
*	  1. Initial Creation
\******************************************************************************/


/******************************************************************************\
 *                  Include header files from project path                    *
\******************************************************************************/
#include "camera_ros/camera.h"	

/******************************************************************************\
 *               Extern function definition in alphabetical order             * 
\******************************************************************************/

/******************************************************************************\
 *@brief : Callback function for image subscriber node in ROS.
 *
 *@param : 
 *	1. msg, reference to the subscribed content.
 *
 *@return : 
 *	1. Void
 *
 *@remark :
 *	Change History:
 *	  1. Initial Creation
 *
\******************************************************************************/
extern std::string pathname;
void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
	static int once = 0;
 
	if(!once)
	{
		src = cv_bridge::toCvShare(msg, "bgr8")->image;
	    	bool isColor = (src.type() == CV_8UC3);
	   
	 	ROS_INFO("value of isColor %d",isColor);
	    
		/***INITIALIZE VIDEOWRITER***/
	    
	    	int codec = VideoWriter::fourcc('M', 'J', 'P', 'G');  	// select desired codec (must be available at runtime)
	    	double fps = 25.0;                          		// framerate of the created video stream
	 
	    	//string filename = getDirectoryPath();            	// name of the output video file
		//string filename = pathname;            	// name of the output video file
		
			//string filename = nh.param("pathname", std::string{});
			//std::cout<<"pathname"<<pathname<<std::endl;
    		//filename.append(VIDEO_FILE_NAME); 
            pathname.append(VIDEO_FILE_NAME); 
			
			writer.open(pathname.c_str(), codec, fps, src.size(), isColor);

		if (!writer.isOpened()) {
			ROS_INFO("cannot open file at %s",pathname.c_str());
		}
		
	   	once =1;
	}

    	try   								// If the conversion fails, jump to the catch statement
    	{
		src=cv_bridge::toCvShare(msg, "bgr8")->image;
		writer.write(src);

		cv::imshow("camera", src);   				// Convert the image to openCV format and output to the window
		cv::waitKey(5); 					// Must have wiatKey(), otherwise it is a black frame or no window     
	 }
    	 catch(cv_bridge::Exception& e)
    	 {
        	ROS_ERROR("Could not convert for '%s' to 'bgr8'.", msg->encoding.c_str());
    	 }
    
}





