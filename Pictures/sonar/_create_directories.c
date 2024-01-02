#include<stdio.h>
#include<unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include<string.h>
#include<errno.h>

int dirExists(const char* const path)
{
  struct stat info;

        int statRC = stat( path, &info );
            if( statRC != 0 )
			{
				if (errno == ENOENT)  
				{ 
					return 0; 
				} // something along the path does not exist
                  if (errno == ENOTDIR)
					  {
						return 0; 
					  } // something in path prefix is not a dir
                       return -1;
             }
		return ( info.st_mode & S_IFDIR ) ? 1 : 0;
}
int main()
{

        char dir[20];
        //printf("enter directory name \n");
        //scanf("%s",dir);
        //char *locations="/home/";
        char dm[20];
        //strcpy(dm,locations);
        //strcat(dm,dir);
        //printf("%s",dm);
        if(!dirExists("1512E"))
        {
                int ret =mkdir("./1512E",660);
                printf("directories created\n");

                if(ret<0)
                {
                        perror("mkdir");
                        return -1;
                }
        }


        int cd=chdir("1512E");
        if(cd<0)
        {
                perror("chdir");
                return 1;
        }
        FILE *fp=fopen("data.txt","w");
        if(fp==0)
        {
                perror("fopen");
                return 1;
        }
        char *wr_data="change data write to/1512E/data.txt\n";

        fwrite(wr_data,strlen(wr_data)+1,1,fp);
        fclose(fp);
}