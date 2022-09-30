/******************************************************************************\
*@file : camera.h
*
*@brief : File description for camera.h file
* 
*@detail : This file consist of the callback method for the ROS.
*
*@remark : 
*	Change History:
*	  1. Initial Creation
\******************************************************************************/

#ifndef _CAMERA_H_
#define _CAMERA_H_

/******************************************************************************\
 *                  Include header files from standard path                   *
\******************************************************************************/

#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <cv_bridge/cv_bridge.h>
#include <iostream>

/******************************************************************************\
 *                  Include header files from project path                   *
\******************************************************************************/

#include "camera_ros/SSD.h"

using namespace cv;
using namespace std;

/******************************************************************************\
 *                  Macro Definitions                                         *
\******************************************************************************/

#define VIDEO_FILE_NAME "/Video.avi"



/******************************************************************************\
 *                  Extern functions prototype declaration                     *
\******************************************************************************/

Mat src;
VideoWriter writer;

void imageCallback(const sensor_msgs::ImageConstPtr& msg);

#endif  //_CAMERA_H_
