/******************************************************************************\
*@file : SSD.cpp
*
*@brief : File description for SSD.cpp file
* 
*@detail : This file consist of the methods used for mounting
* or unmounting the SSD drive.
*
*@remark : 
*	Change History:
*	  1. Initial Creation
\******************************************************************************/


/******************************************************************************\
 *                  Include header files from project path                    *
\******************************************************************************/

#include "camera_ros/SSD.h"


/******************************************************************************\
 *               Extern function definition in alphabetical order             * 
\******************************************************************************/


/******************************************************************************\
 *@brief : This method creates a new mount point for the SSD.
 *
 *@param : 
 *	1. dir, string containing the path for the new directory
 *
 *@return : 
 *	1. Void
 *
 *@remark :
 *	Change History:
 *	  1. Initial Creation
 *
\******************************************************************************/
void createMountPoint(string dir)
{
	if(mkdir(dir.c_str(), 0777) == -1)
	{
#ifdef DEBUG
	    cout << "Directory not created" << endl;
	    cerr << "Error : " << strerror(errno) << endl;
#endif
	}
	else
	{
#ifdef DEBUG
	    cout << "Directory Created" << endl;
#endif
	}
}


/******************************************************************************\
 *@brief : This method delete mount point for the SSD.
 *
 *@param : 
 *	1. dir, string containing the path for the new directory
 *
 *@return : 
 *	1. Void
 *
 *@remark :
 *	Change History:
 *	  1. Initial Creation
 *
\******************************************************************************/
void deleteMountPoint(string dir)
{
	if(rmdir(dir.c_str()) == -1)
	{
#ifdef DEBUG
	    cout << "Remove directory failed." << endl;
	    cerr << "Error : " << strerror(errno) << endl;
#endif
	}
	else
	{
#ifdef DEBUG
	    cout << "Directory Removed" << endl;
#endif
	}
}


/******************************************************************************\
 *@brief : This method returns directory path.
 *
 *@param : 
 *	1. void
 *
 *@return : 
 *	1. string, path to the directory to be created for mounting
 *	 SSD
 *
 *@remark :
 *	Change History:
 *	  1. Initial Creation
 *
\******************************************************************************/
string getDirectoryPath()
{
	string str = MEDIA_DIR;
	char *buf;
	
	buf = (char*)malloc(50*sizeof(char));
	//buf = getlogin();

	std::cout<<"getlogin : "<<buf<<endl;
		
	string temp_str(buf);
	
	//str.append(temp_str).append(MOUNT_DIR);	
	str.append(MOUNT_DIR);	
	std::cout<<"getDirectory :"<<str<<endl;
	
	return str;
}



/******************************************************************************\
 *@brief : This method returns if a device is mounted or not.
 *
 *@param : 
 *	1. dev_path, device name
 *
 *@return : 
 *	1. int, 1 if mounted else 0.
 *
 *@remark :
 *	Change History:
 *	  1. Initial Creation
 *
\******************************************************************************/
int is_mounted (char * dev_path) 
{
	FILE * mtab = NULL;
 	struct mntent * part = NULL;
 	int is_mounted = 0;

 	if ( ( mtab = setmntent ("/etc/mtab", "r") ) != NULL) 
	{
  		while ( ( part = getmntent ( mtab) ) != NULL) 
		{
   			if ( ( part->mnt_fsname != NULL ) && ( strcmp ( part->mnt_fsname, dev_path ) ) == 0 ) 
			{
    				is_mounted = 1;
   			}
  		}

  		endmntent ( mtab);
 	}

 	return is_mounted;
}

/******************************************************************************\
 *@brief : This mounts the drive to mount point created using
 * 	   createmountPoint().
 *
 *@param : 
 *	1. dir, string containing the path for the mount point
 *
 *@return : 
 *	1. Void
 *
 *@remark :
 *	Change History:
 *	  1. Initial Creation
 *
\******************************************************************************/
void mountDrive(string dir)
{
	if(mount("/dev/sda", dir.c_str(), "vfat", MS_NOATIME, NULL))
	{
#ifdef DEBUG
	    cout << "Device not Mounted" << endl;
	    cerr << "Error : " << strerror(errno) << endl;
#endif
	}
	else
	{
#ifdef DEBUG
	    cout << "Mount Successful" << endl;
#endif
	}
}


/******************************************************************************\
 *@brief : This unmounts the drive from mount point created using
 * 	   createmountPoint().
 *
 *@param : 
 *	1. dir, string containing the path for the mount point
 *
 *@return : 
 *	1. Void
 *
 *@remark :
 *	Change History:
 *	  1. Initial Creation
 *
\******************************************************************************/
void unmountDrive(string dir)
{
	if(umount(dir.c_str()) == -1)
	{
#ifdef DEBUG
	    cout << "Unmount failed." << endl;
	    cerr << "Error : " << strerror(errno) << endl;
#endif
	}
	else
	{
#ifdef DEBUG
	    cout << "Unmount Successful" << endl;
#endif
	}
}




