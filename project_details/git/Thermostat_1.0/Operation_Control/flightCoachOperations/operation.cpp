

#include"operation.h"
#include"common_def.h"
#include"setup_menu.h"




FightCoach_data_st  FightCoach_data;


/*
    Discriptions: This function is used for to do ON/OFF the FAN.
    PARAM@ 
    Return On success it will return 0 and on failuare return ERROR NO.
*/
/*************************Hardware control output start********************/
int fan(uint8_t status)
{
    if(status == ON )
    {
        if(check_hardware_ctl_status_reg(FAN_STATUS_BIT) == ON )
        return 0;
        //TODO turn ON fan and set the flightCoach_status_reg
         status_reg_bank.hardware_ctl_status_reg |=FAN_STATUS_BIT;

    }
    else
    {
         if(check_hardware_ctl_status_reg(FAN_STATUS_BIT) == OFF )
            return 0;
            //TODO turn ON fan and set the flightCoach_status_reg
            status_reg_bank.hardware_ctl_status_reg &= (~FAN_STATUS_BIT);
    }
    return 0;
}


/*
    Discriptions: This function is used for to do ON/OFF the HEATER.
    PARAM@
    Return On success it will return 0 and on failuare return ERROR NO.
*/

int first_stage_heat(uint8_t status)
{
      if(status == ON )
    {
        if(check_hardware_ctl_status_reg(FIRST_STAGE_HEAT_STATUS_BIT) == ON)
        return 0;
        //TODO turn ON first_stage_heat and set the flightCoach_status_reg
        status_reg_bank.hardware_ctl_status_reg |=FIRST_STAGE_HEAT_STATUS_BIT;

    }
    else
    {
         if(check_hardware_ctl_status_reg(FIRST_STAGE_HEAT_STATUS_BIT) == OFF)
            return 0;
            //TODO turn OFF first_stage_heat and set the flightCoach_status_reg
             status_reg_bank.hardware_ctl_status_reg &=(~FIRST_STAGE_HEAT_STATUS_BIT);
    }
    return 0;
}

int second_stage_heat(uint8_t status)
{
    if(status == ON )
    {
        if(check_hardware_ctl_status_reg(SECOND_STAGE_HEAT_STATUS_BIT) == ON)
        return 0;
        //TODO turn ON second_stage_heat and set the flightCoach_status_reg
        status_reg_bank.hardware_ctl_status_reg |=SECOND_STAGE_HEAT_STATUS_BIT;

    }
    else
    {
         if(check_hardware_ctl_status_reg(SECOND_STAGE_HEAT_STATUS_BIT) == OFF)
            return 0;

        //TODO turn off second_stage_heat  and Reset the flightCoach_status_reg
          status_reg_bank.hardware_ctl_status_reg &=(~SECOND_STAGE_HEAT_STATUS_BIT);
    }
    return 0;

}

int first_stage_cool(uint8_t status)
{
    if(status == ON )
    {
        if(check_hardware_ctl_status_reg(FIRST_STAGE_COOL_STATUS_BIT) == ON)
        return 0;
        //TODO turn ON first_stage_cool and set the flightCoach_status_reg
        status_reg_bank.hardware_ctl_status_reg |=FIRST_STAGE_COOL_STATUS_BIT;

    }
    else
    {
         if(check_hardware_ctl_status_reg(FIRST_STAGE_COOL_STATUS_BIT) == OFF)
            return 0;

        //TODO turn off first_stage_cool  and Reset the flightCoach_status_reg
          status_reg_bank.hardware_ctl_status_reg &=(~FIRST_STAGE_COOL_STATUS_BIT);
    }
    return 0;

    
}

int second_stage_cool(uint8_t status)
{

 if(status == ON )
    {
        if(check_hardware_ctl_status_reg(SECOND_STAGE_COOL_STATUS_BIT) == ON)
        return 0;
         //TODO turn ON heater and set the flightCoach_status_reg
        status_reg_bank.hardware_ctl_status_reg |=SECOND_STAGE_COOL_STATUS_BIT;

    }
    else
    {
         if(check_hardware_ctl_status_reg(SECOND_STAGE_COOL_STATUS_BIT) == OFF)
            return 0;

        //TODO turn off heater  and Reset the flightCoach_status_reg
          status_reg_bank.hardware_ctl_status_reg &=(~SECOND_STAGE_COOL_STATUS_BIT);
    }
    return 0;

    
}

int rev_valve(uint8_t status)
{
    if(status == ON)
    {
     if(check_hardware_ctl_status_reg(REV_VALVE_STATUS_BIT) == ON)
        return 0;
        //TODO turn ON heater and set the flightCoach_status_reg
        status_reg_bank.hardware_ctl_status_reg |=REV_VALVE_STATUS_BIT;

    }
    else
    {
        if(check_hardware_ctl_status_reg(REV_VALVE_STATUS_BIT) == OFF)
        return 0;
        //TODO turn off heater  and Reset the flightCoach_status_reg
          status_reg_bank.hardware_ctl_status_reg &=(~REV_VALVE_STATUS_BIT);
    }
    return 0;
}



int humidity_control(uint8_t status)
{
    if(status == ON)
    {
     if(check_hardware_ctl_status_reg(HUMIDITY_STATUS_BIT) == ON)
        return 0;
        //TODO turn ON heater and set the flightCoach_status_reg
        status_reg_bank.hardware_ctl_status_reg |=HUMIDITY_STATUS_BIT;
    }
    else
    {
        if(check_hardware_ctl_status_reg(HUMIDITY_STATUS_BIT) == OFF)
            return 0;
        //TODO turn off heater  and Reset the flightCoach_status_reg
          status_reg_bank.hardware_ctl_status_reg &=(~HUMIDITY_STATUS_BIT);
    }
    return 0;
}

int dehumidity_control(uint8_t status)
{
    if(status == ON)
    {
     if(check_hardware_ctl_status_reg(DEHUMIDIFIER_STATUS_BIT) == ON)
        return 0;
        //TODO turn ON heater and set the flightCoach_status_reg
        status_reg_bank.hardware_ctl_status_reg |=DEHUMIDIFIER_STATUS_BIT;

    }
    else
    {
         if(check_hardware_ctl_status_reg(DEHUMIDIFIER_STATUS_BIT) == OFF)
            return 0;
        //TODO turn off heater  and Reset the flightCoach_status_reg
          status_reg_bank.hardware_ctl_status_reg &=(~DEHUMIDIFIER_STATUS_BIT);
    }
    return 0;
}



int aux_1_out(uint8_t status)
{
    if(status == ON)
    {
     if(check_hardware_ctl_status_reg(AUX_1_OUT_STATUS_BIT) == ON)
        return 0;
        //TODO turn ON heater and set the flightCoach_status_reg
        status_reg_bank.hardware_ctl_status_reg |=AUX_1_OUT_STATUS_BIT;

    }
    else
    {
        if(check_hardware_ctl_status_reg(AUX_1_OUT_STATUS_BIT) == OFF)
        return 0;
        //TODO turn off heater  and Reset the flightCoach_status_reg
          status_reg_bank.hardware_ctl_status_reg &=(~AUX_1_OUT_STATUS_BIT);
    }
    return 0;
}

int aux_2_out(uint8_t status)
{
   if(status == ON)
    {
     if(check_hardware_ctl_status_reg(AUX_2_OUT_STATUS_BIT) == ON)
        return 0;

        //TODO turn ON heater and set the flightCoach_status_reg
        status_reg_bank.hardware_ctl_status_reg |=AUX_1_OUT_STATUS_BIT;

    }
    else
    {
         if(check_hardware_ctl_status_reg(AUX_2_OUT_STATUS_BIT) == OFF)
            return 0;
        //TODO turn off heater  and Reset the flightCoach_status_reg
          status_reg_bank.hardware_ctl_status_reg &=(~AUX_1_OUT_STATUS_BIT);
    }
    return 0;
}

/************************hardware control output end***************************/
/*
    Discriptions: This function is used for Temperature Monitoring.
    PARAM@
    Return On success it will return 0 and on failuare return ERROR NO.
*/

int temp_monitor(int32_t temperature)
{
    
    return 0;
}


/*
    Discriptions: 
    PARAM@
    Return 
*/

int humidity_monitor()
{
   
    return 0;
}

/*
    Discriptions: This function is used for CO Controlling.
    PARAM@
    Return When CO fall below then it will return 0 and CO rises above return 1.
*/

int co_monitor()
{
    
    return 0;
}

/*
    Discriptions: This function is used for CO2 Controllling.
    PARAM@
    Return When CO2 reaches 600 ppm then it will return 0 and on rises above 600 ppm return 1.
*/

int co2_monitor()
{
   
    return 0;
}








/*
    Discriptions: This function is used for selecting any System Modes.
    PARAM@
    Return 
*/

int system_mode(int8_t mode_select)
{
    
switch(mode_select)
{
        case 1:
            {
                // off

            }
        case 2:
            {
                // cooling
            
             }

        case 3:
            {
                 //heating
   
            }

        case 4:
             {
                //emergency heat
    
        
             }

        case 5:
             {
                //dehumidity
      
        
              }

        case 6:
             {
                 //cruise control

                 //system will energize the associated contacts as need for any "out of parameter” condition
        
             }
    } 

    return 0;  

}


/*
    Discriptions: This function is used for represent all the Operation Mode.
    PARAM@
    Return 
*/

int thermostate_system_monitor()
{
    /*if(temp_monitor() !=0)
    {

    }

    if(co_monitor() !=0)
    {

    }

    if(co2_monitor() !=0)
    {

    }

    if(humidity_monitor() !=0)
    {

    }
       
*/
 return 0;
}


/// @brief  The function will call to check the fan & system mode type and call functions accordingly
/// @return  0 on success and -1 on faild
int thermostate_system_control()
{
    
    switch (status_reg_bank.operation_mode_reg)
    {
        /**********************FAN ON and SYSTEM*/
    case FAN_ON_SYSTEM_OFF:
        fan_on_system_off_mode();
        break;

    case FAN_ON_SYSTEM_COOLING:
        fan_on_system_cooling_mode();
        break;

    case FAN_ON_SYSTEM_HEATING:
        fan_on_system_heating_mode();
        break;
    case FAN_ON_SYSTEM_EM_HEATING:
        fan_on_system_em_heating_mode();
    
        break;
    case FAN_ON_SYSTEM_DEHUMIDIYFY:
       fan_on_system_dehumidiyfy_mode();
        break;
        
    case FAN_ON_SYSTEM_CRUISE_CONTROL:
        fan_on_system_cruise_control_mode();
    
        break;
    /*********************************FAN AUTO and SYSTEM***********************************************/
    case FAN_AUTO_SYSTEM_OFF:
        fan_auto_system_off_mode();
        
        break;
    case FAN_AUTO_SYSTEM_COOLING:
        
        fan_auto_system_cooling_mode();
        break;
    case FAN_AUTO_SYSTEM_HEATING:
        fan_auto_system_heating_mode();
    
        break;
    case FAN_AUTO_SYSTEM_EM_HEATING:
        fan_auto_system_em_heating_mode();
    
        break;
    case FAN_AUTO_SYSTEM_DEHUMIDIYFY:
        fan_auto_system_dehumidiyfy_mode();
    
        break;
    case FAN_AUTO_SYSTEM_CRUISE_CONTROL:
        fan_auto_system_cruise_control_mode();
    
        break; 
    default:

      
        break;
    }

    return 0;
}

                                          
                                          
/// @brief 
/// @return 
int system_type()
{
    switch(g_th_setup_menu.basic_setup_menu.system_type)
    {
        case HEAT_PUMP_WITH_AUXILIARY_HEAT:

        break;

        case HEAT_PUMP_WITH_GAS_HEAT:

        break;

        case STRAIGHT_COOL_WITH_ELECTRIC_HEAT:

        break;

        case STRAIGHT_COOL_WITH_GAS_HEAT:

        break;

        default:
        return -1;
        break;
    }
    return 0;
}          
           
/*mode of operation */


/*
    Discriptions:
    
*/
int fan_on_system_off_mode()
{
       return 0;
}

/*
    Discriptions:
    
*/
int fan_on_system_cooling_mode()
{
       return 0;
}

/*
    Discriptions:
    
*/
int fan_on_system_heating_mode()
{
     return 0;
}

/*
    Discriptions:
    
*/
int fan_on_system_em_heating_mode()
{
     return 0;
}

/*
    Discriptions:
    
*/
int fan_on_system_dehumidiyfy_mode()
{
     return 0;
}

/*
    Discriptions:
    
*/
int fan_on_system_cruise_control_mode()
{
     return 0;
}

/*
    Discriptions:
    
*/
int fan_auto_system_off_mode()
{
        
       return 0;     
        
}

/*
    Discriptions:
    
*/
int fan_auto_system_cooling_mode()
{
     return 0;
}

/*
    Discriptions:
    
*/
int fan_auto_system_heating_mode()
{
     return 0;
}

/*
    Discriptions:
    
*/
int fan_auto_system_em_heating_mode()
{
     return 0;
}

/*
    Discriptions:
    
*/
int fan_auto_system_dehumidiyfy_mode()
{
   return 0;
}

/*
    Discriptions:
    
*/
int fan_auto_system_cruise_control_mode()
{
    return 0;
}


int heat_pump_with_auxiliary_heat_system_type()
{
    return 0;
}
int heat_pump_with_gas_heat_system_type()
{
    return 0;
}
int straight_cool_with_electric_heat_system_type()
{
    return 0;
}
int  STRAIGHT_COOL_WITH_GAS_HEAT_system_type()
{
    return 0;
}