
#include <iostream>
#include "print/print_result.h"
#include "var/var.h"


void validate_output(float data)
{
	std::cout<<"data  validation start "<<data<<std::endl;
	print_result("validate_output",data);
	std::cout<<"data validation end "<<data<<std::endl;
	
}

