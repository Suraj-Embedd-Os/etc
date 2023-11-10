
#include<stdio.h>
#include<unistd.h>


int main()
{
	
	system("mkdir temp && cd temp");
	system("cat>temp.txt echo helllo");
	system("exit");
}



#include<pcl/io/pcdio.h>
#include<pcl/point_types.h>

int read_pcl();
void write_pcl();

int main()
{
	write_pcl();
	read_pcl();
	return 0;
}
void write_pcl()
{
	pcl::PointCloud<pcl::PointXYZ> cloud;
	
	cloud.width=50;
	cloud.height=1;
	cloud.is_dense=false;
	cloud.points.resize(cloud.width*cloud.height);
	
	for(size_t i=0;i<cloud.points.size();i++)
	{
		cloud .points[i].x  =  1024* rand() ;
		cloud .points[i].y  =  1024* rand() ;
		cloud .points[i].z  =  1024* rand() ;
	}
	pcl::io::savePCDFileASCII("test_pcd.pcd",cloud);
	return;
}

int read_pcl()
{
	pcl::PointCloud<pcl::PointXYZ> ::ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
	if(pcl::io::loadPCDFile<pcl::PointXYZ>("test_pcd.pcd",*cloud)==-1)
	{
		PCL_ERROR("could not read test_pcd\n");
		return -1;
		
	}
	return 0;
}