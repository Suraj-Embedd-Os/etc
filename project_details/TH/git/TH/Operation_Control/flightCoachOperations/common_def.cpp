#include "common_def.h"
#include <stdint.h>

/// @brief
Status_reg_bank_st floghtCoach_status_reg_bank = {
    .hardware_ctl_status_reg = 0,
    .operation_mode_reg = 0,
    .sensor_data_status_reg = 0,

};

/*
    Discrtiops: Function used for checking the status of register
    PARAM@ Status_bit_t
    return 1 ,0
*/

int check_hardware_ctl_status_reg(Harware_clt_et_bit status)
{
    if (floghtCoach_status_reg_bank.hardware_ctl_status_reg & status)
        return ON;
    else
        return OFF;
}

int check_operation_mode_reg(Mode_of_operations_status_bit_et status)
{
    if (floghtCoach_status_reg_bank.operation_mode_reg & status)
        return ON;
    else
        return OFF;
}

/// @brief 
/// @param status 
/// @return 
int check_sensor_data_status_reg(Harware_clt_et_bit status)
{
}

/// @brief function will be used to initialsed controller harware
/// @return sucess return  0  and fail will return-1
int hardware_initializations()
{
    return 0;
}

/*
    Discrtiops: This is used for turn on/off fan
    PARAM@ bool ,status of the fan
    Return  sucess 0 failed ERROR NO
*/
