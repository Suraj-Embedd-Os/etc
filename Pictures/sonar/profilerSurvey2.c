#include "command.h"


int main(int argc,char* argv[])
{
	while(1)
	{
		get_sensor_data();
		perform_sweep();
	}
	return 0;
}


