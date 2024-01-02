#include<iostream>
#include<stdio.h>
#include<math.h>
#include"TutorialConfig.h"
#include<stdlib.h>

#ifdef USE_MYMATH
#include"MathFunctions.h"
#endif

using namespace std;


int main(int argc,char *argv[])
{
	if(argc<2)
	{
		cout<<argv[0]<<" Version "<<Tutorial_VERSION_MAJOR<<"."<<Tutorial_VERSION_MINOR<<endl;
		cout<<"Usage: "<<argv[0]<<" number "<<endl;
		return 1;
	}

#ifdef 	USE_MYMATH
	printf("mysqrt %f\n",mysqrt(atoi(argv[1])));
#else	
	printf("sqrt %f\n",sqrt(atoi(argv[1])));
#endif

}

