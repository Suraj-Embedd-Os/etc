

#ifndef _SETUP_MENU_H
#define _SETUP_MENU_H
#include "common_def.h"

typedef enum
{
    SETUP_NO=0,
    SETUP_YES=1,

    SETUP_ONE=1,
    SETUP_TWO=2,


    SETUP_MIN_OFF_CYCLE_1_MIN=1,
    SETUP_MIN_OFF_CYCLE_2_MIN=2,
    SETUP_MIN_OFF_CYCLE_3_MIN=3,
    SETUP_MIN_OFF_CYCLE_4_MIN=4,
    SETUP_MIN_OFF_CYCLE_5_MIN=5,

    HEAT_PUMP_WITH_AUXILIARY_HEAT=0,
    HEAT_PUMP_WITH_GAS_HEAT,
    STRAIGHT_COOL_WITH_ELECTRIC_HEAT,
    STRAIGHT_COOL_WITH_GAS_HEAT


}Setup_defaut_et;

typedef enum
{
    HIGH_TEMP_ALERT,
    LOW_TEMP_ALERT,
    HIGH_HUMIDITY_ALERT,
    LOW_HUMIDITY_ALERT,
    UV_LAMP_REPLACEMENT_REMINDER,
    SYSTEM_MAINTENANCE_REMINDER,
    HIGH_CO_ALERT,
    AIR_FILTER_CHANGE_REMINDER,
    HUMIDIFER_PAD_REMINDER,
    LOW_BATTERY,

    TL_ALARM_PARAM

}Alarm_event_et;


;

typedef struct 
{
    /* data */
    //char language[16];  //english ,Español 
   // char location[16];  //(Default name is “Thermostat”). 
    int8_t system_type; //HEAT PUMP WITH AUXILIARY HEAT,HEAT PUMP WITH GAS HEAT,STRAIGHT COOL WITH ELECTRIC HEAT,STRAIGHT COOL WITH GAS HEAT
    int8_t fan; // Thermostat Controls Fan, Yes/No (Default is Yes) // 0,1 -1,
    //char date_time[32]; //Note; If Wi-Fi is enabled, time is set from internet clock.  //
    int8_t dehumidify;    // Yes/No (Default is No). Not available for dual fuel system type. 
    int8_t humidity;  //   Optional Humidifier Installed? Yes/No. (Default is No). 
    int8_t Wi_Fi_Setup; // Enable Wi-Fi? Yes/No. (Default is No).  

}Basic_setup_menu_st;


typedef struct  
{
    /* data */
    char  name[16]; //Dealer Name
    char phone[16]; //Dealer Phone Number
    char email[20]; //Dealer service email
    int8_t alert;  //Send alerts to dealer email? Yes/No

}Dealar_info_st;


typedef struct 
{
    /* data */
  int8_t  no_of_heat_pump; //Select; Number of compressor heating stages. 1 or 2 (Default is 1).
  int8_t no_of_compressure; // Select; Number of compressor cooling stages. 1 or 2 (Default is 1).
  //int8_t fah_cel;   // Select; Fahrenheit or Celsius. (Default is Fahrenheit). 
  //int8_t day_light_saving; //  Enable Daylight Savings Time? Yes/No. (Default is No). 
  //int8_t clock_format; //   Select; 12 Hour or 24 Hour (Default is 12 Hour)

  int8_t temperature;  //Note; Default settings for Temperature are 45deg F minimum and 90deg F maximum. 
  int8_t humidity;   //Humidity is 35% minimum and 75% maximum. /ppm
  //int8_t backlight_display_level; //   Select; Backlight Display level 1-10 (Default is 7).  
 
  //Dealar_info_st dealar_info; //Enter dealer information with Key pad 
  int8_t alarm_event;    //(Show alarm events) Clear Alarm Events? Yes/No Send alerts to owner email? Yes/No (Note; If Yes is selected enter email or SMS text information.)
  int8_t minimum_off_cycle_tim ;// Select number of minutes to delay after compressor cycles off before it can be energized again. 1-5 minutes (Default is 2 min) 
  int8_t cruise_control ; //Allow Cruise Control setting, Yes/No (Default is Yes). Note; This allows the system to automatically switch from heating to cooling as well as all humidity functions and CO/CO2
  
  int8_t reset_factory; //Reset Factory Default Settings? Yes or No 

}Advanced_setup_menu_st;

typedef struct 
{
    /* data */
    Basic_setup_menu_st basic_setup_menu;
    Advanced_setup_menu_st advanced_setup_menu;

}TH_Setup_menu_st;


extern TH_Setup_menu_st g_th_setup_menu ;

/* function declaration start here*/
int setup_initialised_menu();
int load_default_setup_menu();
int read_setup_menu();
int write_setup_menu();

int mode_of_operations();



#endif