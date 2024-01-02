
#ifndef COMMON_DEF_H
#define COMMON_DEF_H

#include<stdint.h>

/* start enum and macro defitions*/

#define ON 1
#define OFF 0

typedef enum 
{
    NOT_OK      = -1,
    OK          = 0,
    
}Errno_et;


typedef enum
{
    FAN_STATUS =0,                            // show the fan status
    FIRST_STAGE_HEAT_STATUS,                 // show the first stage heat
    SECOND_STAGE_HEAT_STATUS,                // show the second stage heat
    FIRST_STAGE_COOL_STATUS,                 // show the first stage cool
    SECOND_STAGE_COOL_STATUS,                // show the second stage cool
    REV_VALVE_STATUS,                        // show the heat pump status
    HUMIDITY_STATUS,                         // To show Temp status
    DEHUMIDIFIER_STATUS,
    AUX_1_OUT_STATUS,
    AUX_2_OUT_STATUS,

    TL_PARAM_HARWARE_CONTROL
   
}Harware_clt_et;


typedef enum
{
    FAN_STATUS_BIT                              =(1<<FAN_STATUS),                            
    FIRST_STAGE_HEAT_STATUS_BIT                 =(1<<FIRST_STAGE_HEAT_STATUS),                 
    SECOND_STAGE_HEAT_STATUS_BIT                =(1<<SECOND_STAGE_HEAT_STATUS),                
    
    FIRST_STAGE_COOL_STATUS_BIT                 =(1<<FIRST_STAGE_COOL_STATUS),                 
    SECOND_STAGE_COOL_STATUS_BIT                =(1<<SECOND_STAGE_COOL_STATUS),    

    REV_VALVE_STATUS_BIT                        =(1<<REV_VALVE_STATUS), 

    HUMIDITY_STATUS_BIT                         =(1<<HUMIDITY_STATUS),                         
    DEHUMIDIFIER_STATUS_BIT                     =(1<<DEHUMIDIFIER_STATUS),

    AUX_1_OUT_STATUS_BIT                        =(1<<AUX_1_OUT_STATUS),
    AUX_2_OUT_STATUS_BIT                        =(1<<AUX_2_OUT_STATUS)
   
}Harware_clt_et_bit;


typedef enum
{
    FAN_ON_SYSTEM_OFF=0,                           // To show the operation mode 1 status, if operation mode is selected by the user
    FAN_ON_SYSTEM_COOLING,                           // To show the operation mode 2 status, if operation mode is selected by the user
    FAN_ON_SYSTEM_HEATING,                           // To show the operation mode 3 status, if operation mode is selected by the user
    FAN_ON_SYSTEM_EM_HEATING,                           // To show the operation mode 4 status, if operation mode is selected by the user
    FAN_ON_SYSTEM_CRUISE_CONTROL,
    FAN_ON_SYSTEM_DEHUMIDITYFY,                          
    FAN_ON_SYSTEM_HUMIDITYFY,

    FAN_AUTO_SYSTEM_OFF,                           // To show the operation mode 1 status, if operation mode is selected by the user
    FAN_AUTO_SYSTEM_COOLING,                           // To show the operation mode 2 status, if operation mode is selected by the user
    FAN_AUTO_SYSTEM_HEATING,                           // To show the operation mode 3 status, if operation mode is selected by the user
    FAN_AUTO_SYSTEM_EM_HEATING,                           // To show the operation mode 4 status, if operation mode is selected by the user
    FAN_AUTO_SYSTEM_CRUISE_CONTROL,
    FAN_AUTO_SYSTEM_DEHUMIDITYFY,                       // To show the operation mode 5 status, if operation mode is selected by the user
    FAN_AUTO_SYSTEM_HUMIDITYFY,



    TL_MODE_OPERATIONS
}Mode_of_operations_et;


typedef enum
{
    FAN_ON_SYSTEM_OFF_STATUS_BIT                        =(1<<FAN_ON_SYSTEM_OFF),                          
    FAN_ON_SYSTEM_COOLING_STATUS_BIT                    =(1<<FAN_ON_SYSTEM_COOLING),                          
    FAN_ON_SYSTEM_HEATING_STATUS_BIT                    =(1<<FAN_ON_SYSTEM_HEATING),                           
    FAN_ON_SYSTEM_EM_HEATING_STATUS_BIT                 =(1<<FAN_ON_SYSTEM_EM_HEATING),  
    FAN_ON_SYSTEM_CRUISE_CONTROL_STATUS_BIT             =(1<<FAN_ON_SYSTEM_CRUISE_CONTROL),                        
    FAN_ON_SYSTEM_DEHUMIDITYFY_STATUS_BIT               =(1<<FAN_ON_SYSTEM_DEHUMIDITYFY),                         
    FAN_ON_SYSTEM_HUMIDITYFY_STATUS_BIT                 =(1<<FAN_ON_SYSTEM_HUMIDITYFY), 

    FAN_AUTO_SYSTEM_OFF_STATUS_BIT                      =(1<<FAN_AUTO_SYSTEM_OFF),                          
    FAN_AUTO_SYSTEM_COOLING_STATUS_BIT                  =(1<<FAN_AUTO_SYSTEM_COOLING),                          
    FAN_AUTO_SYSTEM_HEATING_STATUS_BIT                  =(1<<FAN_AUTO_SYSTEM_HEATING),                          
    FAN_AUTO_SYSTEM_EM_HEATING_STATUS_BIT               =(1<<FAN_AUTO_SYSTEM_EM_HEATING), 
    FAN_AUTO_SYSTEM_CRUISE_CONTROL_STATUS_BIT           =(1<<FAN_AUTO_SYSTEM_CRUISE_CONTROL),                        
    FAN_AUTO_SYSTEM_DEHUMIDITYFY_STATUS_BIT             =(1<<FAN_AUTO_SYSTEM_DEHUMIDITYFY),
    FAN_AUTO_SYSTEM_HUMIDITYFY_STATUS_BIT               =(1<<FAN_AUTO_SYSTEM_HUMIDITYFY)                           
    

    
}Mode_of_operations_status_bit_et;


typedef struct 
{
    /* data */
    uint32_t hardware_ctl_status_reg;
    uint32_t operation_mode_reg;
    uint32_t sensor_data_status_reg;

}Status_reg_bank_st;


extern Status_reg_bank_st status_reg_bank;

/*Start common Function declarion here*/

int check_hardware_ctl_status_reg(Harware_clt_et_bit status);
int check_operation_mode_reg(Mode_of_operations_et status);
int check_sensor_data_status_reg(Harware_clt_et_bit status);






int hardware_initializations();

#endif


