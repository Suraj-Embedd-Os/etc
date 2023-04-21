

#ifndef OPERATION_H
#define OPERATION_H

#include "common_def.h"
#include<stdint.h>


typedef enum
{
    LIMIT_TEMP_MIN=45,  // in F
    LIMIT_TEMP_MAX=90,  // in F
    
    LIMIT_HUMIDITY_MIN=35,  // in %
    LIMIT_HUMIDITY_MAX=75,  // in %
 
    LIMIT_CO2_MIN=500, // 500 ppm
    LIMIT_CO2_MAX=600, // 600 ppm
 
    LIMIT_CO_MIN=40,   // 40 ppm parts per million (ppm)
    LIMIT_CO_MAX=70   // 70 ppm parts per million (ppm)


}Limit_et;

/* Data to be read from sensor*/
typedef enum
{
    TEMP_DATA,
    HUMIDITY_DATA,
    CO2_DATA,
    //CO_DATA,

    TL_PARA_MONITOR_DATA
}Environment_monitor_data_et;

/* Data to be read from sensor*/
typedef enum
{
    TEMP_DATA_MIN,
    TEMP_DATA_MAX,
    HUMIDITY_DATA_MIN,
    HUMIDITY_DATA_MAX,
    CO2_DATA_MAX,
    CO_DATA_MAX,

    TL_PARA_SETUP_DATA
}Environment_setup_data_et;

typedef struct  
{
    /* data */
    uint32_t monitor_data[TL_PARA_MONITOR_DATA];
    uint32_t setup_data[TL_PARA_SETUP_DATA];
}FightCoach_data_st;




/* hardware control function definitons*/
int fan(uint8_t status);
int first_stage_heat(uint8_t status);
int second_stage_heat(uint8_t status);

int first_stage_cool(uint8_t status);
int second_stage_cool(uint8_t status); 
int rev_valve(uint8_t status);
int humidity_control(uint8_t status);
int dehumidity_control(uint8_t status);

int aux_1_out(uint8_t status);
int aux_2_out(uint8_t status);

/*int co_control(int status);
int co2_control(int status);
int heating_with_heat_pump();
int heating_with_gas_furnace();*/


/** monitoring data ***/
int temp_monitor(int32_t temperature);
int co_monitor();
int co2_monitor();
int humidity_monitor();

/*mode of operation */
int fan_on_system_off_mode();
int fan_on_system_cooling_mode();
int fan_on_system_heating_mode();
int fan_on_system_em_heating_mode();
int fan_on_system_dehumidiyfy_mode();
int fan_on_system_cruise_control_mode();

int fan_auto_system_off_mode();
int fan_auto_system_cooling_mode();
int fan_auto_system_heating_mode(); 
int fan_auto_system_em_heating_mode();
int fan_auto_system_dehumidiyfy_mode();
int fan_auto_system_cruise_control_mode();


int heat_pump_with_auxiliary_heat_system_type();
int heat_pump_with_gas_heat_system_type();
int straight_cool_with_electric_heat_system_type();
int straight_cool_with_gas_heat_system_type();


/***************** */
int thermostate_system_monitor();
int thermostate_system_control();
int system_type();







#endif
