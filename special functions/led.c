[ CAUTION: External email. Do not click on links or open attachments unless you recognize the sender and know the content is safe ] 
/*

 

Project: Water Heater

 

Components:
                Temperature Sensor
                
                RED LED
                BLUE LED
                GREEN LED
                
                Heater
                Cooler

 


  Based on the temperature of the water heater,
  Status leds should be turned on as per the rules below,
  
    1.When temperature is Too Hot, Turn on RED LED, Turn on Cooler, Turn off the rest.
    2.When temperature is Too cold, Turn on BLUE LED, Turn on Heater, Turn off the rest.
    3.Other wise, Turn on GREEN LED, Turn off the rest.

 


***Important Rules***
1. Use only one variable other than "temp".
2. Function call should happen only if there is a change in state of LED/Heater/Cooler.
    
*/

 


#define TOO_COLD 10
#define TOO_HOT     75

 

int get_temperature(void);
void blue_led_on(void);
void blue_led_off(void);
void red_led_on(void);
void red_led_off(void);
void green_led_on(void);
void green_led_off(void);

 

void Turn_on_heater(void);
void Turn_off_heater(void);

 

void Turn_on_cooler(void);
void Turn_off_cooler(void);

 

/*1.When temperature is Too Hot, Turn on RED LED, Turn on Cooler, Turn off the rest.
    2.When temperature is Too cold, Turn on BLUE LED, Turn on Heater, Turn off the rest.
    3.Other wise, Turn on GREEN LED, Turn off the rest.

#define TOO_COLD 10
#define TOO_HOT     75
RED LED
                BLUE LED
                GREEN LED
                
                Heater
                Cooler

*/
#define RED_LED (1<<0)
#define BLUE_LED (1<<1)
#define GREEN_LED (1<<2)
#define HEATER (1<<3)
#define COOLER (1<<4)

int status_reg=4;
int main()
{    
  temp = get_temperature();

if(temp>=TOO_HOT && (status_reg!=(RED_LED|COOLER))
{
red_led_on();
Turn_on_cooler();


green_led_off();
blue_led_off();
Turn_off_heater();
green_led_off();


status_reg|=(RED_LED|COOLER);
status_reg&=~(BLUE_LED|GREEN_LED|HEATER);

}
else if(temp<=TOO_COLD && (status_reg!=(BLUE_LED|HEATER))
{
blue_led_on();
red_led_off();
green_led_off();
Turn_off_cooler();
Turn_on_heater();

status_reg|=(BLUE_LED|HEATER);
status_reg&=~(BLUE_LED|GREEN_LED|COOLER);

}
else if((status_reg!=(GREEN_LED))
{

green_led_on();
blue_led_off();
red_led_off();

Turn_off_cooler();
Turn_off_heater();

status_reg|=GREEN_LED;
status_reg&=~(BLUE_LED|GREEN_LED|COOLER|HEATER);

}





}
