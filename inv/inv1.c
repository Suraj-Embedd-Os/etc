#include<stdio.h>

int main()
{
	int ret;
	ret = truncate ("./pirate.txt", 45);
	if (ret == −1)
	 {
		 perror ("truncate");
		 return −1;
	 }
	 return 0;
}

 https://docs.bluerobotics.com/ping-viewer/
 IF(D2<0,IF(AND(D2<=0,D2>=-2),1,IF(AND(D2<-2,D2>=-3),2,IF(AND(D2<-3,D2>=-4),3,IF(AND(D2<-4,D2>=-5),4,IF(D2<-5,5,10))))),IF(AND(D2>0,D2<=2),-1,IF(AND(D2>2,D2<=3),-2,IF(AND(D2>3,D2<=4),-3,IF(AND(D2>4,D2<=5),-2,IF(D2>5,-1,-1))))))*
 