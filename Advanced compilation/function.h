#pragma once
#define FIRST_OPTION
#ifdef FIRST_OPTION
#define MULTIPLIER (3.0)
#else
#define MULTIPLIER (2.0)
#endif

float add_and_multiply(float x, float y);
int nCompletionStatus = 0;

float add(float x, float y)
{
	 float z = x + y;
	 return z;
}

float add_and_multiply(float x, float y)
{
	 float z = add(x,y);
	 z *= MULTIPLIER;
	 return z;
}