#include <Nextion.h>
#include <NexButton.h>

//declear nextion objects, pageid, component id, component name
NexButton b0 = NexButton (0,1,"b0");
NexButton b1 = NexButton (0,2,"b1");
NexButton b2 = NexButton (0,3,"b2");
NexButton b3 = NexButton (0,4,"b3");
NexButton b4 = NexButton (0,5,"b4");
NexButton b5 = NexButton (0,6,"b5");
NexButton b6 = NexButton (0,7,"b6");
NexButton b7 = NexButton (0,8,"b7");
NexButton b8 = NexButton (0,9,"b8");
NexButton b9 = NexButton (0,10,"b9");
NexButton b10 = NexButton (0,11,"b10");
NexButton b11 = NexButton (0,12,"b11");
NexButton b12 = NexButton (0,13,"b12");
NexButton b13 = NexButton (0,14,"b13");
NexButton b14 = NexButton (0,15,"b14");

//register a button object to touch event list
NexTouch* nex_listen_list [] = {&b0,&b1,&b2,&b3,&b4,&b5,&b6,&b7,&b8,&b9,&b10,&b11,&b12,&b13,&b14,NULL};

//button b0 component popcallback function
//when off button is released then system modes should be off
void b0Popcallback(void*ptr)
{
  
}

//button b1 component popcallback function
//when cool button is released then system modes should to do cool
void b1Popcallback(void*ptr)
{

}

//button b2 component popcallback function
//when 
void b2Popcallback(void*ptr)
{

}

//button b3 component popcallback function
//when l
void b3Popcallback(void*ptr)
{

}

//button b4 component popcallback function
//when 
void b4Popcallback(void*ptr)
{

}

//button b5 component popcallback function
//when 
void b5Popcallback(void*ptr)
{

}

//button b6 component popcallback function
//when 
void b6Popcallback(void*ptr)
{

}

//button b7 component popcallback function
//when 
void b7Popcallback(void*ptr)
{

}

//button b8 component popcallback function
//when 
void b8Popcallback(void*ptr)
{

}

//button b9 component popcallback function
//when 
void b9Popcallback(void*ptr)
{

}

//button b10 component popcallback function
//when 
void b10Popcallback(void*ptr)
{

}

//button b11 component popcallback function
//when 
void b11Popcallback(void*ptr)
{

}

//button b12 component popcallback function
//when 
void b12Popcallback(void*ptr)
{

}

//button b13 component popcallback function
//when 
void b13Popcallback(void*ptr)
{

}

//button b14 component popcallback function
//when 
void b14Popcallback(void*ptr)
{

}
void setup() {
  // register the pop event callback function of the component
  b0.attachPop(b0Popcallback, &b0);
  b1.attachPop(b1Popcallback, &b1);

}

void loop() {
  // put your main code here, to run repeatedly:

}
