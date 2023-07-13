#include<string.h>
#include<stdint.h>

#include "setup_menu.h"
/* global and extern variable */
TH_Setup_menu_st g_th_setup_menu = {
        HEAT_PUMP_WITH_AUXILIARY_HEAT, //HEAT PUMP WITH AUXILIARY HEAT,HEAT PUMP WITH GAS HEAT,STRAIGHT COOL WITH ELECTRIC HEAT,STRAIGHT COOL WITH GAS HEAT
        SETUP_YES,
        SETUP_NO,
        SETUP_NO,
        SETUP_NO,

        SETUP_ONE,
        SETUP_ONE,
        45,
        35,
        SETUP_NO,
        SETUP_MIN_OFF_CYCLE_2_MIN,
        SETUP_NO,
       SETUP_NO

};

extern Status_reg_bank_st status_reg_bank;

/*
    Discrtiptions:
    Param@:

*/

int setup_initialised_menu()
{
    load_default_setup_menu();
    return OK;
}


/*
    Discrtiptions: function used to load default value
    Param@:
    
*/
int load_default_setup_menu()
{
    /* basic setup intializations*/
    

    g_th_setup_menu.basic_setup_menu.system_type    =               (int8_t)HEAT_PUMP_WITH_AUXILIARY_HEAT;        // Forced Air, Heat Pump or Dual Fuel  //0,1
    g_th_setup_menu.basic_setup_menu.fan            =               (int8_t)SETUP_YES;                       // Thermostat Controls Fan, Yes/No (Default is Yes) // 0,1 -1,
    g_th_setup_menu.basic_setup_menu.humidity       =               (int8_t)SETUP_NO;                        //   Optional Humidifier Installed? Yes/No. (Default is No). 
    g_th_setup_menu.basic_setup_menu.dehumidify     =               (int8_t)SETUP_NO;                        // Yes/No (Default is No). Not available for dual fuel system type. 
    g_th_setup_menu.basic_setup_menu.Wi_Fi_Setup    =               (int8_t)SETUP_NO;                        // Enable Wi-Fi? Yes/No. (Default is No).
                 

    /*advanced setup intializations*/



    g_th_setup_menu.advanced_setup_menu.no_of_heat_pump                 =           (int8_t)SETUP_ONE;  //Select; Number of compressor heating stages. 1 or 2 (Default is 1).
    g_th_setup_menu.advanced_setup_menu.no_of_compressure               =           (int8_t)SETUP_ONE;   // Select; Number of compressor cooling stages. 1 or 2 (Default is 1).
    g_th_setup_menu.advanced_setup_menu.alarm_event                     =           (int8_t)SETUP_NO;       //(Show alarm events) Clear Alarm Events? Yes/No Send alerts to owner email? Yes/No (Note; If Yes is selected enter email or SMS text information.)
    g_th_setup_menu.advanced_setup_menu.minimum_off_cycle_tim           =           (int8_t)SETUP_MIN_OFF_CYCLE_2_MIN; // Select number of minutes to delay after compressor cycles off before it can be energized again. 1-5 minutes (Default is 2 min) 
    g_th_setup_menu.advanced_setup_menu.cruise_control                  =           (int8_t)SETUP_YES;        //Allow Cruise Control setting, Yes/No (Default is Yes). Note; This allows the system to automatically switch from heating to cooling as well as all humidity functions and CO/CO2   

    g_th_setup_menu.advanced_setup_menu.reset_factory                   =           (int8_t)SETUP_YES;          //Reset Factory Default Settings? Yes or No
    g_th_setup_menu.advanced_setup_menu.temperature                     =           (int8_t)45;      //Note; Default settings for Temperature are 45deg F minimum and 90deg F maximum. 
    g_th_setup_menu.advanced_setup_menu.humidity                        =           (int8_t)35; //Humidity is 35% minimum and 75% maximum. /ppm

    return OK;

}

/*
    Discrtiptions:
    Param@:
    
*/

int read_setup_menu()
{
    return OK;
} 

/*
    Discrtiptions:
    Param@:
    
*/
int write_setup_menu()
{
  return OK;
}
/*
    Discrirption : Read mode and set  the mode of operations
*/

int mode_of_operations()
{
        // This will update while chmage the mode of operation for the user
        status_reg_bank.operation_mode_reg = (uint32_t)FAN_ON_SYSTEM_OFF_STATUS_BIT;
        return 0;
}