

#ifndef OPERATION_H
#define OPERATION_H

#include "common_def.h"
#include<stdint.h>


typedef enum
{
    FAN_COUNTER,
    FIRST_STAGE_HEAT_COUNTER,
    SECOND_STAGE_HEAT_COUNTER,
    FIRST_STAGE_COOL_COUNTER,
    SECOND_STAGE_COOL,
    REV_VALVE_COUNTER,
    HUMIDITY_COUNTER,
    DEHUMIDIFIER_COUNTER,
    AUX_1_OUT_COUNTER,
    AUX_2_OUT_COUNTER,

    TL_NO_COUNTER

}Counter_et;

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
    TEMP_MIN,
    TEMP_MAX,
    HUMIDITY_MIN,
    HUMIDITY_MAX,
    CO2_MAX,
    CO_MAX,

    TL_PARA_SETUP_DATA
}Environment_setup_data_et;

typedef struct  
{
    /* data */
    uint32_t monitor_data[TL_PARA_MONITOR_DATA];
    uint32_t setup_data[TL_PARA_SETUP_DATA];
}FightCoach_data_st;


/*system type*/
int heat_pump_with_auxiliary_heat_system_type();
int heat_pump_with_gas_heat_system_type();
int straight_cool_with_electric_heat_system_type();
int straight_cool_with_gas_heat_system_type();


int system_type();

void read_operation_mode();





#endif
