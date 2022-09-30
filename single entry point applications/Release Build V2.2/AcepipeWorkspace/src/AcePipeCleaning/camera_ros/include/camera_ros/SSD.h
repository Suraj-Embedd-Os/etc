/******************************************************************************\
*@file : SSD.h
*
*@brief : File description for SSD.h file
* 
*@detail : This file consist of the methods used for mounting
* or unmounting the SSD drive.
*
*@remark : 
*	Change History:
*	  1. Initial Creation
\******************************************************************************/

#ifndef _SSD_H_
#define _SSD_H_

/******************************************************************************\
 *                  Include header files from standard path                   *
\******************************************************************************/

#include <iostream>
#include <string>
#include <sys/mount.h>
#include <unistd.h>
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <mntent.h>

using namespace std;

/******************************************************************************\
 *                  Macro Definitions                                         *
\******************************************************************************/

#define MEDIA_DIR "/home/toad/Desktop/"
#define MOUNT_DIR "/AcePipe_data"


/******************************************************************************\
 *                  Extern functions prototype declaration                     *
\******************************************************************************/
string getDirectoryPath();
void createMountPoint(string dir);
void mountDrive(string dir);
void unmountDrive(string dir);
void deleteMountPoint(string dir);
int is_mounted (char * dev_path); 
#endif //_SSD_H_
