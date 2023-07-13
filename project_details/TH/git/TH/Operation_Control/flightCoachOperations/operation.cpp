

#include"operation.h"
#include"common_def.h"
#include"setup_menu.h"




FightCoach_data_st  FightCoach_data;
static uint32_t gs_mode_control_registre=0; 

uint32_t time_counter[TL_NO_COUNTER];

static uint32_t tick_count_in_sec(uint32_t count)
{
     //TODO do some math 
     return count;
}


/* helper function declarations*/
static int fan_on_system_off_mode_hp_with_auxilary();
static int fan_on_system_off_mode_hp_with_gas();
static int fan_on_system_off_mode_sc_with_electric();
static int fan_on_system_off_mode_sc_with_gas();


static int fan_on_system_cooling_mode_hp_with_auxilary();
static int fan_on_system_cooling_mode_hp_with_gas();
static int fan_on_system_cooling_mode_sc_with_electric();
static int fan_on_system_cooling_mode_sc_with_gas();


static int fan_on_system_heating_mode_hp_with_auxilary();
static int fan_on_system_heating_mode_hp_with_gas();
static int fan_on_system_heating_mode_sc_with_electric();
static int fan_on_system_heating_mode_sc_with_gas();


static int fan_on_system_em_heating_mode_hp_with_auxilary();
static int fan_on_system_em_heating_mode_hp_with_gas();
static int fan_on_system_em_heating_mode_sc_with_electric();
static int fan_on_system_em_heating_mode_sc_with_gas();

static int fan_on_system_cruise_control_mode_hp_with_auxilary();
static int fan_on_system_cruise_control_mode_hp_with_gas();
static int fan_on_system_cruise_control_mode_sc_with_electric();
static int fan_on_system_cruise_control_mode_sc_with_gas();

static int fan_on_system_dehumidityfy_mode_hp_with_auxilary();
static int fan_on_system_dehumidityfy_mode_hp_with_gas();
static int fan_on_system_dehumidityfy_mode_sc_with_electric();
static int fan_on_system_dehumidityfy_mode_sc_with_gas();

static int fan_on_system_humidityfy_mode_hp_with_auxilary();
static int fan_on_system_humidityfy_mode_hp_with_gas();
static int fan_on_system_humidityfy_mode_sc_with_electric();
static int fan_on_system_humidityfy_mode_sc_with_gas();

static int fan_auto_system_off_mode_hp_with_auxilary();
static int fan_auto_system_off_mode_hp_with_gas();
static int fan_auto_system_off_mode_sc_with_electric();
static int fan_auto_system_off_mode_sc_with_gas();

static int fan_auto_system_cooling_mode_hp_with_auxilary();
static int fan_auto_system_cooling_mode_hp_with_gas();
static int fan_auto_system_cooling_mode_sc_with_electric();
static int fan_auto_system_cooling_mode_sc_with_gas();

static int fan_auto_system_heating_mode_hp_with_auxilary();
static int fan_auto_system_heating_mode_hp_with_gas();
static int fan_auto_system_heating_mode_sc_with_electric();
static int fan_auto_system_heating_mode_sc_with_gas();

static int fan_auto_system_em_heating_mode_hp_with_auxilary();
static int fan_auto_system_em_heating_mode_hp_with_gas();
static int fan_auto_system_em_heating_mode_sc_with_electric();
static int fan_auto_system_em_heating_mode_sc_with_gas();

static int fan_auto_system_cruise_control_mode_hp_with_auxilary();
static int fan_auto_system_cruise_control_mode_hp_with_gas();
static int fan_auto_system_cruise_control_mode_sc_with_electric();
static int fan_auto_system_cruise_control_mode_sc_with_gas();

static int fan_auto_system_dehumidityfy_mode_hp_with_auxilary();
static int fan_auto_system_dehumidityfy_mode_hp_with_gas();
static int fan_auto_system_dehumidityfy_mode_sc_with_electric();
static int fan_auto_system_dehumidityfy_mode_sc_with_gas();

static int fan_auto_system_humidityfy_mode_hp_with_auxilary();
static int fan_auto_system_humidityfy_mode_hp_with_gas();
static int fan_auto_system_humidityfy_mode_sc_with_electric();
static int fan_auto_system_humidityfy_mode_sc_with_gas();


/*
*/

void reset()
{
    status_reg_bank.operation_mode_reg= (uint32_t)FAN_ON_SYSTEM_OFF; // TODO read setup menu data from Nextion Display

    if(status_reg_bank.operation_mode_reg != gs_mode_control_registre)
    {
          gs_mode_control_registre=status_reg_bank.operation_mode_reg;          

          //TODO TURN OFF all devices 

    }
}


/* hardware control function definitons*/
static int fan(uint8_t status);
static int first_stage_heat(uint8_t status);
static int second_stage_heat(uint8_t status);
static int first_stage_cool(uint8_t status);
static int second_stage_cool(uint8_t status); 
static int rev_valve(uint8_t status);
static int humidity_control(uint8_t status);
static int dehumidity_control(uint8_t status);
static int aux_1_out(uint8_t status);
static int aux_2_out(uint8_t status);


/*
    Discriptions: This function is used for to do ON/OFF the FAN.
    PARAM@ 
    Return On success it will return 0 and on failuare return ERROR NO.
*/
/*************************Hardware control output start********************/

/// @brief 
/// @param status 
/// @return 
static int 
fan(uint8_t status)
{
     uint32_t _minimum_off_cycle_tim = 0; //TODO read from setup menu
     time_counter[FAN_COUNTER]++; //increment fan counetr

    if(status == ON )
    {
        if(tick_count_in_sec(time_counter[FAN_COUNTER]) >= _minimum_off_cycle_tim)
        {
          if(check_hardware_ctl_status_reg(FAN_STATUS_BIT) == ON )
          return OK;
          //TODO turn ON fan and set the flightCoach_status_reg
          status_reg_bank.hardware_ctl_status_reg |=FAN_STATUS_BIT;
        }

    }
    else
    {
         time_counter[FAN_COUNTER] = 0; //reset counter
         if(check_hardware_ctl_status_reg(FAN_STATUS_BIT) == OFF )
            return OK;
            //TODO turn ON fan and set the flightCoach_status_reg
            status_reg_bank.hardware_ctl_status_reg &= (~FAN_STATUS_BIT);
    }
    return OK;
}


/// @brief 
/// @param status 
/// @return 
static
int first_stage_heat(uint8_t status)
{
      uint32_t _minimum_off_cycle_tim = 0; //TODO read from setup menu
      time_counter[FIRST_STAGE_HEAT_COUNTER]++; //increment fan counetr

     if(status == ON )
    {
       if(tick_count_in_sec(time_counter[FIRST_STAGE_HEAT_COUNTER]) >= _minimum_off_cycle_tim)
       {
        if(check_hardware_ctl_status_reg(FIRST_STAGE_HEAT_STATUS_BIT) == ON)
        return 0;
        //TODO turn ON first_stage_heat and set the flightCoach_status_reg
        status_reg_bank.hardware_ctl_status_reg |=FIRST_STAGE_HEAT_STATUS_BIT;

      }

    }
    else
    {
           time_counter[FIRST_STAGE_HEAT_COUNTER]=0;
         if(check_hardware_ctl_status_reg(FIRST_STAGE_HEAT_STATUS_BIT) == OFF)
            return 0;
            //TODO turn OFF first_stage_heat and set the flightCoach_status_reg
             status_reg_bank.hardware_ctl_status_reg &=(~FIRST_STAGE_HEAT_STATUS_BIT);
    }
    return 0;
}

/// @brief 
/// @param status 
/// @return 
static
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

/// @brief 
/// @param status 
/// @return 
static
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

/// @brief 
/// @param status 
/// @return 
static
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

static
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


static
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

static
int dehumidity_control(uint8_t status)
{
    if(status == ON)
    {
     if(check_hardware_ctl_status_reg(DEHUMIDIFIER_STATUS_BIT) == ON)
        return OK;
        //TODO turn ON heater and set the flightCoach_status_reg
        status_reg_bank.hardware_ctl_status_reg |=DEHUMIDIFIER_STATUS_BIT;

    }
    else
    {
         if(check_hardware_ctl_status_reg(DEHUMIDIFIER_STATUS_BIT) == OFF)
            return OK;
        //TODO turn off heater  and Reset the flightCoach_status_reg
          status_reg_bank.hardware_ctl_status_reg &=(~DEHUMIDIFIER_STATUS_BIT);
    }
    return OK;
}


static
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
          status_reg_bank.hardwrae_ctl_status_reg &=(~AUX_1_OUT_STATUS_BIT);
    }
    return 0;
}

static
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


                                          
                                          
/// @brief 
/// @return 
int system_type()
{
    int8_t sys_mode = g_th_setup_menu.basic_setup_menu.system_type;
    
    switch(sys_mode)
    {
        case HEAT_PUMP_WITH_AUXILIARY_HEAT:
            heat_pump_with_auxiliary_heat_system_type();
        break;

        case HEAT_PUMP_WITH_GAS_HEAT:
            heat_pump_with_gas_heat_system_type();

        break;

        case STRAIGHT_COOL_WITH_ELECTRIC_HEAT:
            straight_cool_with_electric_heat_system_type();
        break;

        case STRAIGHT_COOL_WITH_GAS_HEAT:
            straight_cool_with_gas_heat_system_type();
        break;

        default:
        return NOT_OK;
        
    }
    return OK;
}          
           


/// @brief 
/// @return 
int heat_pump_with_auxiliary_heat_system_type()
{
        //TODO select operation mode
       uint32_t operation_mode=0;

       switch (operation_mode)
       {
        case FAN_ON_SYSTEM_OFF_STATUS_BIT:
        fan_on_system_off_mode_hp_with_auxilary();
        break;

        case FAN_ON_SYSTEM_COOLING_STATUS_BIT:
        fan_on_system_cooling_mode_hp_with_auxilary();
        break;

        case FAN_ON_SYSTEM_HEATING_STATUS_BIT:
        fan_on_system_heating_mode_hp_with_auxilary();
        break;

         case FAN_ON_SYSTEM_EM_HEATING_STATUS_BIT:
       fan_on_system_em_heating_mode_hp_with_auxilary();
        break;
       
       case FAN_ON_SYSTEM_CRUISE_CONTROL_STATUS_BIT:
        fan_on_system_cruise_control_mode_hp_with_auxilary();
         break;

         case FAN_ON_SYSTEM_DEHUMIDITYFY_STATUS_BIT:
       fan_on_system_dehumidityfy_mode_hp_with_auxilary();
        break;

       case FAN_ON_SYSTEM_HUMIDITYFY_STATUS_BIT:
       fan_on_system_humidityfy_mode_hp_with_auxilary();
        break;        

         

        case FAN_AUTO_SYSTEM_OFF_STATUS_BIT:
       fan_auto_system_off_mode_hp_with_auxilary();
        break;

        case FAN_AUTO_SYSTEM_COOLING_STATUS_BIT:
       fan_auto_system_cooling_mode_hp_with_auxilary();
        break;

        case FAN_AUTO_SYSTEM_HEATING_STATUS_BIT:
       fan_auto_system_heating_mode_hp_with_auxilary();
        break;

        case FAN_AUTO_SYSTEM_EM_HEATING_STATUS_BIT:
       fan_auto_system_em_heating_mode_hp_with_auxilary();
        break;

     
       case FAN_AUTO_SYSTEM_CRUISE_CONTROL_STATUS_BIT:
       fan_auto_system_cruise_control_mode_hp_with_auxilary();
       break;

       case FAN_AUTO_SYSTEM_DEHUMIDITYFY_STATUS_BIT:
        fan_auto_system_dehumidityfy_mode_hp_with_auxilary();
        break;

      case FAN_AUTO_SYSTEM_HUMIDITYFY_STATUS_BIT:
       fan_auto_system_humidityfy_mode_hp_with_auxilary();
        break;

       

       default:
       return NOT_OK;
        
       }
       return OK;
}

/// @brief 
/// @return 
int heat_pump_with_gas_heat_system_type()
{
            //TODO select operation mode
       uint32_t operation_mode=0;

       switch (operation_mode)
       {
       case FAN_ON_SYSTEM_OFF_STATUS_BIT:
       fan_on_system_off_mode_hp_with_gas();
        break;

        case FAN_ON_SYSTEM_COOLING_STATUS_BIT:
       fan_on_system_cooling_mode_hp_with_gas();
        break;

        case FAN_ON_SYSTEM_HEATING_STATUS_BIT:
       fan_on_system_heating_mode_hp_with_gas();
        break;

         case FAN_ON_SYSTEM_EM_HEATING_STATUS_BIT:
       fan_on_system_em_heating_mode_hp_with_gas();
        break;

         case FAN_ON_SYSTEM_CRUISE_CONTROL_STATUS_BIT:
        fan_on_system_cruise_control_mode_hp_with_gas();
         break;

         case FAN_ON_SYSTEM_DEHUMIDITYFY_STATUS_BIT:
       fan_on_system_dehumidityfy_mode_hp_with_gas();
        break;

        case FAN_ON_SYSTEM_HUMIDITYFY_STATUS_BIT:
       fan_on_system_humidityfy_mode_hp_with_gas();
        break;

        case FAN_AUTO_SYSTEM_OFF_STATUS_BIT:
       fan_auto_system_off_mode_hp_with_gas();
        break;

        case FAN_AUTO_SYSTEM_COOLING_STATUS_BIT:
       fan_auto_system_cooling_mode_hp_with_gas();
        break;

        case FAN_AUTO_SYSTEM_HEATING_STATUS_BIT:
       fan_auto_system_heating_mode_hp_with_gas();
        break;

        case FAN_AUTO_SYSTEM_EM_HEATING_STATUS_BIT:
       fan_auto_system_em_heating_mode_hp_with_gas();
        break;

        case FAN_AUTO_SYSTEM_CRUISE_CONTROL_STATUS_BIT:
       fan_auto_system_cruise_control_mode_hp_with_gas();
        break;

       case FAN_AUTO_SYSTEM_DEHUMIDITYFY_STATUS_BIT:
       fan_auto_system_dehumidityfy_mode_hp_with_gas();
        break;

       case FAN_AUTO_SYSTEM_HUMIDITYFY_STATUS_BIT:
       fan_auto_system_humidityfy_mode_hp_with_gas();
        break;

       default:
        return NOT_OK;
       
       }
       return OK;
}

/// @brief 
/// @return 
int straight_cool_with_electric_heat_system_type()
{   
            //TODO select operation mode
       uint32_t operation_mode=0;

       switch (operation_mode)
       {
       case FAN_ON_SYSTEM_OFF_STATUS_BIT:
       fan_on_system_off_mode_sc_with_electric();
        break;
       
        case FAN_ON_SYSTEM_COOLING_STATUS_BIT:
         fan_on_system_cooling_mode_sc_with_electric();
        break;

        case FAN_ON_SYSTEM_HEATING_STATUS_BIT:
         fan_on_system_heating_mode_sc_with_electric();
        break;

         case FAN_ON_SYSTEM_EM_HEATING_STATUS_BIT:
           fan_on_system_em_heating_mode_sc_with_electric();
        break;

         case FAN_ON_SYSTEM_CRUISE_CONTROL_STATUS_BIT:
         fan_on_system_cruise_control_mode_sc_with_electric();
         break;

          case FAN_ON_SYSTEM_DEHUMIDITYFY_STATUS_BIT:
        fan_on_system_dehumidityfy_mode_sc_with_electric();
        break;

         case FAN_ON_SYSTEM_HUMIDITYFY_STATUS_BIT:
        fan_on_system_humidityfy_mode_sc_with_electric();
        break;

        case FAN_AUTO_SYSTEM_OFF_STATUS_BIT:
        fan_auto_system_off_mode_sc_with_electric();
        break;

        case FAN_AUTO_SYSTEM_COOLING_STATUS_BIT:
        fan_auto_system_cooling_mode_sc_with_electric();
        break;

        case FAN_AUTO_SYSTEM_HEATING_STATUS_BIT:
        fan_auto_system_heating_mode_sc_with_electric();
        break;

        case FAN_AUTO_SYSTEM_EM_HEATING_STATUS_BIT:
        fan_auto_system_em_heating_mode_sc_with_electric();
        break;

        case FAN_AUTO_SYSTEM_CRUISE_CONTROL_STATUS_BIT:
        fan_auto_system_cruise_control_mode_sc_with_electric();
        break;
         case FAN_AUTO_SYSTEM_DEHUMIDITYFY_STATUS_BIT:
        fan_auto_system_dehumidityfy_mode_sc_with_electric();
        break;

         case FAN_AUTO_SYSTEM_HUMIDITYFY_STATUS_BIT:
        fan_auto_system_humidityfy_mode_sc_with_electric();
        break;
     

       default:
       return NOT_OK;
       }
       return OK;
 
}

/// @brief 
/// @return 
int  straight_cool_with_gas_heat_system_type()
{
            //TODO select operation mode
       uint32_t operation_mode=0;

       switch (operation_mode)
       {
       case FAN_ON_SYSTEM_OFF_STATUS_BIT:
       fan_on_system_off_mode_sc_with_gas();
        break;

        case FAN_ON_SYSTEM_COOLING_STATUS_BIT:
       fan_on_system_cooling_mode_sc_with_gas();
        break;

        case FAN_ON_SYSTEM_HEATING_STATUS_BIT:
       fan_on_system_heating_mode_sc_with_gas();
       
        break;
         case FAN_ON_SYSTEM_EM_HEATING_STATUS_BIT:
       fan_on_system_em_heating_mode_sc_with_gas();
        break;

       case FAN_ON_SYSTEM_CRUISE_CONTROL_STATUS_BIT:
        fan_on_system_cruise_control_mode_sc_with_gas();
         break;

        case FAN_ON_SYSTEM_DEHUMIDITYFY_STATUS_BIT:
       fan_on_system_dehumidityfy_mode_sc_with_gas();
        break;

        case FAN_ON_SYSTEM_HUMIDITYFY_STATUS_BIT:
       fan_on_system_humidityfy_mode_sc_with_gas();
        break;  

        case FAN_AUTO_SYSTEM_OFF_STATUS_BIT:
       fan_auto_system_off_mode_sc_with_gas();
        break;

        case FAN_AUTO_SYSTEM_COOLING_STATUS_BIT:
       fan_auto_system_cooling_mode_sc_with_gas();
        break;

        case FAN_AUTO_SYSTEM_HEATING_STATUS_BIT:
       fan_auto_system_heating_mode_sc_with_gas();
        break;

        case FAN_AUTO_SYSTEM_EM_HEATING_STATUS_BIT:
       fan_auto_system_em_heating_mode_sc_with_gas();
        break;


        case FAN_AUTO_SYSTEM_CRUISE_CONTROL_STATUS_BIT:
       fan_auto_system_cruise_control_mode_sc_with_gas();
        break;
     
      case FAN_AUTO_SYSTEM_DEHUMIDITYFY_STATUS_BIT:
       fan_auto_system_dehumidityfy_mode_sc_with_gas();
        break;

        case FAN_AUTO_SYSTEM_HUMIDITYFY_STATUS_BIT:
       fan_auto_system_humidityfy_mode_sc_with_gas();
        break;

       default:
       return NOT_OK;
       }
       return OK;
   
}








/* helper function definition start here*/

/*
    Discriptions :If the CO2 rises above 600ppm the AUX1 CO2 contacts are energized to allow for an outside air damper to 
    open. Once the CO2 reaches 500ppm the AUX1 CO2 contacts are de-energized. 
    since the Fan control button is in the ON position.
*/

/// @brief 
/// @return 
static
int fan_on_system_off_mode_hp_with_auxilary()
{

    //check system mode and operations
    /*if(!(status_reg_bank.operation_mode_reg & FAN_ON_SYSTEM_OFF))
    {
        // ADD debug log
        return NOT_OK; 
    }*/
    
    // turn on fan
    fan(ON);

    //TODO read co2 live data
    int32_t co2_ppm=0;

     if(check_hardware_ctl_status_reg(AUX_1_OUT_STATUS_BIT) == OFF)
     {
          if (co2_ppm > LIMIT_CO2_MAX)
          {
             //TODO turn on AUX1 contact 
               aux_1_out(ON);
          }

     }
     else
     {
        if (co2_ppm < LIMIT_CO2_MIN)
        {
            // turn OFF AUX1 contact
            aux_1_out(OFF);
        }
    }

    return OK;

}

/// @brief 
/// @return 
static
int fan_on_system_off_mode_hp_with_gas()
{    
     //TODO features not available in this version of applications
     return OK;
}

/// @brief 
/// @return 
static
int fan_on_system_off_mode_sc_with_electric()
{
    return fan_on_system_off_mode_hp_with_auxilary();
}


/// @brief 
/// @return 
static
int fan_on_system_off_mode_sc_with_gas()
{
    return fan_on_system_off_mode_hp_with_auxilary();
}


/// @brief 
/// @return 
static
int fan_on_system_cooling_mode_hp_with_auxilary()
{
       //TODO read system dehumidify 
     uint8_t dehumidity_setup=ON;

     float  curr_humidity =0 ;// TODO read humidity data
     uint8_t setup_humidity=0; //TODO read setup data
     // TODO read tempearture in farenhite / convert to farenhite
     float curr_temp=0;
     uint8_t setup_temp=0;
    

     //check system mode and operations
  /* if(!(status_reg_bank.operation_mode_reg & FAN_ON_SYSTEM_DEHUMIDITYFY))
    {
        // ADD debug log
        return NOT_OK; 
    } */
  // Fan will be on in this mode
     fan(ON);
     rev_valve(ON);    

   if(check_hardware_ctl_status_reg(SECOND_STAGE_COOL_STATUS) == OFF)
   {
          if(curr_temp > (float)(setup_temp + 0.5)
          {
               second_stage_cool(ON);     // Y/Y2
              
          }
   }
   else
   {
          if(curr_temp < (float)(setup_temp + 0.5)
          {
               second_stage_cool(OFF);     // Y/Y2
              
          }
   }


     

/************************************Start To control dehumidity*****************************************************************/
    if (dehumidity_setup == ON)
    {
          // intitial when no even occurs
          if(check_hardware_ctl_status_reg(DEHUMIDIFIER_STATUS_BIT) == OFF && check_hardware_ctl_status_reg(REV_VALVE_STATUS_BIT) == OFF)
          {
               if (curr_humidity > (setup_humidity+(setup_humidity * 7)/100))     
               {
                    //turn on Y/Y1 contact,fan ,W electric heat,Dehum contact O/B reserving valve contact 
                    second_stage_cool(ON);     // Y/Y2
                    dehumidity_control(ON);     //Dehumid
                    first_stage_heat(ON);         //W electric contact
               }
          }
          else
          {
               //This modulation will continue until the humidity reaches the humidity set point -3%
                if (curr_humidity <= (setup_humidity-(setup_humidity * 3)/100))
                {
                    // maintatin the heat while dehumidityfy
                    if (check_hardware_ctl_status_reg(FIRST_STAGE_HEAT_STATUS_BIT) == OFF)
                    {
                         if(curr_temp <= (setup_temp - 0.75))
                         {
                              first_stage_heat(ON);         //W electric contact  
                         }
                         
                    }
                    else
                    {
                         if(curr_temp >= (setup_temp + 0.75))
                         {
                              first_stage_heat(OFF);         //W electric contact  
                         }
                    }

                    // turn off Y/Y2 contact
                    if(check_hardware_ctl_status_reg(SECOND_STAGE_COOL_STATUS_BIT) == ON)
                    {
                         if(curr_temp <= (setup_temp - 1))
                         {
                              second_stage_cool(OFF);         // Y/Y2 
                         }
                    }
                    else 
                    {
                         if(curr_temp >= (setup_temp + 0.75))
                         {
                              second_stage_cool(ON);         // Y/Y2 
                         }
                    }

                }
                else
                {
                    // system temperature is within 5deg F above or below set point AND the humidity is within 5% of the set point
                    //system goes to IDEL state
                    if ( (curr_humidity > (setup_humidity -(setup_humidity * 5 )/100)) &&  (curr_humidity < (setup_humidity +(setup_humidity * 5 )/100)))     
                    {
                    
                         if(curr_temp <= (setup_temp + 0.5) && curr_temp >= (setup_temp - 0.5))
                         {
                              //turn on Y/Y1 contact,fan ,W electric heat,Dehum contact O/B reserving valve contact 
                              second_stage_cool(OFF);     // Y/Y2
                              dehumidity_control(OFF);     //Dehumid
                              first_stage_heat(OFF);         //W electric contact
                         }
                    }
                }
          }
    }

/**************************************************End To control dehumidity***************************************************/

//humidity control
fan_on_system_humidityfy_mode_hp_with_auxilary();

//co2 control
fan_on_system_off_mode_hp_with_auxilary();
     return OK;

}

static
int fan_on_system_cooling_mode_hp_with_gas()
{
     //TODO features not available in this version of applications
    return OK;
}

static
int fan_on_system_cooling_mode_sc_with_electric()
{
     return OK;
}

static
int fan_on_system_cooling_mode_sc_with_gas()
{
     return OK;
}

static
int fan_on_system_heating_mode_hp_with_auxilary()
{
     return OK;
}

static
int fan_on_system_heating_mode_hp_with_gas()
{
     return OK;
}

static
int fan_on_system_heating_mode_sc_with_electric()
{
     return OK;
}

static
int fan_on_system_heating_mode_sc_with_gas()
{
     return OK;
}


static
int fan_on_system_em_heating_mode_hp_with_auxilary()
{
     return OK;
}

static
int fan_on_system_em_heating_mode_hp_with_gas()
{
     return OK;
}

static
int fan_on_system_em_heating_mode_sc_with_electric()
{
     return OK;
}

static
int fan_on_system_em_heating_mode_sc_with_gas()
{
     return OK;
}


static
int fan_on_system_cruise_control_mode_hp_with_auxilary()
{
     return OK;
}

static
int fan_on_system_cruise_control_mode_hp_with_gas()
{
     return OK;
}

static
int fan_on_system_cruise_control_mode_sc_with_electric()
{
     return OK;
}

static
int fan_on_system_cruise_control_mode_sc_with_gas()
{
     return OK;
}

/// @brief 
/// @return 
static
int fan_on_system_dehumidityfy_mode_hp_with_auxilary()
{
      //TODO read system dehumidify 
     uint8_t dehumidity_setup=ON;

     uint8_t  curr_humidity =0 ;// TODO read humidity data
     uint8_t setup_humidity=0; //TODO read setup data
     // TODO read tempearture in farenhite / convert to farenhite
     uint8_t curr_temp=0;
     uint8_t setup_temp=0;
    
  
     //check system mode and operations
    if(!(status_reg_bank.operation_mode_reg & FAN_ON_SYSTEM_DEHUMIDITYFY))
    {
        // ADD debug log
        return NOT_OK; 
    }

     // Fan will be on in this mode
     fan(ON);

    if (dehumidity_setup == ON)
    {
          // intitial when no even occurs
          if(check_hardware_ctl_status_reg(DEHUMIDIFIER_STATUS_BIT) == OFF && check_hardware_ctl_status_reg(REV_VALVE_STATUS_BIT) == OFF)
          {
               if (curr_humidity > (setup_humidity+(setup_humidity * 7)/100))     
               {
                    //turn on Y/Y1 contact,fan ,W electric heat,Dehum contact O/B reserving valve contact 
                    second_stage_cool(ON);     // Y/Y2
                    rev_valve(ON);             // O/B contact
                    dehumidity_control(ON);     //Dehumid
                    first_stage_heat(ON);         //W electric contact
               }
          }
          else
          {
               //This modulation will continue until the humidity reaches the humidity set point -3%
                if (curr_humidity <= (setup_humidity-(setup_humidity * 3)/100))
                {
                    // maintatin the heat while dehumidityfy
                    if (check_hardware_ctl_status_reg(FIRST_STAGE_HEAT_STATUS_BIT) == OFF)
                    {
                         if(curr_temp <= (setup_temp - 5) )
                         {
                              first_stage_heat(ON);         //W electric contact  
                         }
                         
                    }
                    else
                    {
                         if(curr_temp >= (setup_temp + 5))
                         {
                              first_stage_heat(OFF);         //W electric contact  
                         }
                    }

                    // turn off Y/Y2 contact
                    if(check_hardware_ctl_status_reg(SECOND_STAGE_COOL_STATUS_BIT) == ON)
                    {
                         if(curr_temp <= (setup_temp - 6))
                         {
                              second_stage_cool(OFF);         // Y/Y2 
                         }
                    }
                    else 
                    {
                         if(curr_temp >= (setup_temp + 6))
                         {
                              second_stage_cool(ON);         // Y/Y2 
                         }
                    }

                }
                else
                {
                    // system temperature is within 5deg F above or below set point AND the humidity is within 5% of the set point
                    //system goes to IDEL state
                    if ( (curr_humidity > (setup_humidity -(setup_humidity * 5 )/100)) &&  (curr_humidity < (setup_humidity +(setup_humidity * 5 )/100)))     
                    {
                    
                         if(curr_temp <= (setup_temp + 5) && curr_temp >= (setup_temp - 5))
                         {
                              //turn on Y/Y1 contact,fan ,W electric heat,Dehum contact O/B reserving valve contact 
                              second_stage_cool(OFF);     // Y/Y2
                              rev_valve(OFF);             // O/B contact
                              dehumidity_control(OFF);     //Dehumid
                              first_stage_heat(OFF);         //W electric contact
                         }
                    }
                }
          }
    }
    return OK;
}


static
int fan_on_system_dehumidityfy_mode_hp_with_gas()
{
     //TODO features not available in this version of applications
     return OK;
}

static
int fan_on_system_dehumidityfy_mode_sc_with_electric()
{
     uint8_t 
     //TODO read system dehumidify 
     uint8_t dehumidity_setup=ON;

     uint8_t  curr_humidity =0 ;// TODO read humidity data
     uint8_t setup_humidity=0; //TODO read setup data
     // TODO read tempearture in farenhite / convert to farenhite
     uint8_t curr_temp=0;
     uint8_t setup_temp=0;


     //check system mode and operations
    if(!(status_reg_bank.operation_mode_reg & FAN_ON_SYSTEM_DEHUMIDITYFY))
    {
        // ADD debug log
        return NOT_OK; 
    }

     // Fan will be on in this mode
     fan(ON);

    if (dehumidity_setup == ON)
    {

          if(check_hardware_ctl_status_reg(DEHUMIDIFIER_STATUS_BIT) == OFF)
          {
               if (curr_humidity > (setup_humidity+(setup_humidity * 7)/100))     
               {
                    //turn on Y/Y1 contact,fan ,W electric heat,Dehum contact O/B reserving valve contact 
                    second_stage_cool(ON);     // Y/Y2
                    dehumidity_control(ON);     //Dehumid
                    first_stage_heat(ON);         //W electric contact
               }
          }
          else
          {
               //This modulation will continue until the humidity reaches the humidity set point -3%
                if (curr_humidity <= (setup_humidity-(setup_humidity * 3)/100))
                {

                    // maintatin the heat while dehumidityfy
                    if (check_hardware_ctl_status_reg(FIRST_STAGE_HEAT_STATUS_BIT) == OFF)
                    {
                         if(curr_temp <= (setup_temp - 5) )
                         {
                              first_stage_heat(ON);         //W electric contact  
                         }
                         
                    }
                    else
                    {
                         if(curr_temp >= (setup_temp + 5))
                         {
                              first_stage_heat(OFF);         //W electric contact  
                         }
                    }

                    // turn off Y/Y2 contact
                    if (check_hardware_ctl_status_reg(SECOND_STAGE_HEAT_STATUS_BIT) == ON)
                    {
                         if(curr_temp <= (setup_temp -6))
                         {
                              second_stage_cool(OFF);         // Y/Y2 
                         }
                    }
                    else 
                    {
                         if(curr_temp >= (setup_temp + 6))
                         {
                              second_stage_cool(ON);         // Y/Y2 
                         }
                    }

                }
                else
                {
                    // system temperature is within 5deg F above or below set point AND the humidity is within 5% of the set point
                    //system goes to IDEL state
                    if ( (curr_humidity > (setup_humidity -(setup_humidity * 5 )/100)) &&  (curr_humidity < (setup_humidity +(setup_humidity * 5 )/100)))     
                    {
                    
                         if(curr_temp <= (setup_temp + 5) && curr_temp >= (setup_temp - 5))
                         {
                              //turn on Y/Y1 contact,fan ,W electric heat,Dehum contact O/B reserving valve contact 
                              second_stage_cool(OFF);     // Y/Y2
                              dehumidity_control(OFF);     //Dehumid
                              first_stage_heat(OFF);         //W electric contact
                         }
                    }
                }
          }
    }

    
    return OK;
}

/// @brief 
/// @return 
static
int fan_on_system_dehumidityfy_mode_sc_with_gas()
{
    
     //TODO read system dehumidify 
     uint8_t dehumidity_setup=ON;

     uint8_t  curr_humidity =0 ;// TODO read humidity data
     uint8_t setup_humidity=0; //TODO read setup data

     //check system mode and operations
    if(!(status_reg_bank.operation_mode_reg & FAN_ON_SYSTEM_DEHUMIDITYFY))
    {
        // ADD debug log
        return NOT_OK; 
    }

     // Fan will be on in this mode
     fan(ON);

    if (dehumidity_setup == ON)
    {
           if(check_hardware_ctl_status_reg(DEHUMIDIFIER_STATUS_BIT) == OFF)
          {
               if (curr_humidity > (setup_humidity+(setup_humidity * 7)/100))     
               {
                    dehumidity_control(ON);     //Dehumid
               }
          }
          else
          {
               //This modulation will continue until the humidity reaches the humidity set point -3%
                if (curr_humidity <= (setup_humidity-(setup_humidity * 3)/100))
                {
                    dehumidity_control(OFF);     //Dehumid
                }

          }
    }

    
    return OK;
}


/// @brief 
/// @return 
static
int fan_on_system_humidityfy_mode_hp_with_auxilary()
{
  
     //TODO read system dehumidify 
     uint8_t humidity_setup=ON;

     uint8_t  curr_humidity =0 ;// TODO read humidity data
     uint8_t   setup_humidity=0; //TODO read setup data

     uint8_t  curr_temp =0 ;// TODO read humidity data
     uint8_t  setup_temp=0;

      //check system mode and operations
   /* if(!(status_reg_bank.operation_mode_reg & FAN_ON_SYSTEM_HUMIDITYFY))
    {
        // ADD debug log
        return NOT_OK; 
    }*/

     // Fan will be on in this mode
     fan(ON);
     
    if (humidity_setup ==ON)
    {
          if(check_hardware_ctl_status_reg(HUMIDITY_STATUS_BIT) == OFF)
          {
               // if current humidity less than seted humidity   7% 
               if (curr_humidity <= (setup_humidity-(setup_humidity * 7)/100))     
               {
                    humidity_control(ON);     //humid
               }
          }
          else
          {
               // system  humidity is 3% above humidity set point
               //system goes to IDEL state
               if ( (curr_humidity >= (setup_humidity +(setup_humidity * 3 )/100)))     
               {
                    humidity_control(OFF);     //humid
                    
               }
          }
    }

    return OK;
}

/// @brief 
/// @return 
static
int fan_on_system_humidityfy_mode_hp_with_gas()
{
     //TODO features not available in this version of applications
     return OK;
}

/// @brief 
/// @return 
static
int fan_on_system_humidityfy_mode_sc_with_electric()
{
    return fan_on_system_humidityfy_mode_hp_with_auxilary();
}

/// @brief 
/// @return 

static
int fan_on_system_humidityfy_mode_sc_with_gas()
{
     return fan_on_system_humidityfy_mode_hp_with_auxilary();
}

/*******End of FAN on and system other function definitions *******************/



/*******start of FAN auto/off and system other function definitions *******************/
static
int fan_auto_system_off_mode_hp_with_auxilary()
{
    //Turn off all hardware
     fan(OFF);
     first_stage_heat(OFF);
     second_stage_heat(OFF);
     first_stage_cool(OFF);
     second_stage_cool(OFF); 
     rev_valve(OFF);
     humidity_control(OFF);
     dehumidity_control(OFF);
     aux_1_out(OFF);
     aux_2_out(OFF);


    return OK;
}

static
int fan_auto_system_off_mode_hp_with_gas()
{
    return fan_auto_system_off_mode_hp_with_auxilary();
     
}

static
int fan_auto_system_off_mode_sc_with_electric()
{
    return fan_auto_system_off_mode_hp_with_auxilary();
     
}

static
int fan_auto_system_off_mode_sc_with_gas()
{
    return fan_auto_system_off_mode_hp_with_auxilary();
    
}

static
int fan_auto_system_cooling_mode_hp_with_auxilary()
{
     return OK;
}

static
int fan_auto_system_cooling_mode_hp_with_gas()
{
     return OK;
}

static
int fan_auto_system_cooling_mode_sc_with_electric()
{
     return OK;
}

static
int fan_auto_system_cooling_mode_sc_with_gas()
{
     return OK;
}

static
int fan_auto_system_heating_mode_hp_with_auxilary()
{
     return OK;
}

static
int fan_auto_system_heating_mode_hp_with_gas()
{
     return OK;
}

static
int fan_auto_system_heating_mode_sc_with_electric()
{
     return OK;
}

static
int fan_auto_system_heating_mode_sc_with_gas()
{
     return OK;
}

static
int fan_auto_system_em_heating_mode_hp_with_auxilary()
{
     return OK;
}

static
int fan_auto_system_em_heating_mode_hp_with_gas()
{
     return OK;
}

static
int fan_auto_system_em_heating_mode_sc_with_electric()
{
     return OK;
}

static
int fan_auto_system_em_heating_mode_sc_with_gas()
{
     return OK;
}


static
int fan_auto_system_cruise_control_mode_hp_with_auxilary()
{
     return OK;
}

static
int fan_auto_system_cruise_control_mode_hp_with_gas()
{
     return OK;
}

static int 
fan_auto_system_cruise_control_mode_sc_with_electric()
{
     return OK;
}

static int 
fan_auto_system_cruise_control_mode_sc_with_gas()
{
     return OK;
}

static
int fan_auto_system_dehumidityfy_mode_hp_with_auxilary()
{
     return OK;
}

static
int fan_auto_system_dehumidityfy_mode_hp_with_gas()
{
     return OK;
}

static
int fan_auto_system_dehumidityfy_mode_sc_with_electric()
{
     return OK;
}

static
int fan_auto_system_dehumidityfy_mode_sc_with_gas()
{
     return OK;
}


/// @brief  operation is fan auto and system humidi
///        
/// @return 

static int 
fan_auto_system_humidityfy_mode_hp_with_auxilary()
{
     return OK;
}

static int 
fan_auto_system_humidityfy_mode_hp_with_gas()
{
     return OK;
}

static int 
fan_auto_system_humidityfy_mode_sc_with_electric()
{
     return OK;
}

static int 
fan_auto_system_humidityfy_mode_sc_with_gas()
{
     return OK;
}


/*******End of FAN auto/off and system other function definitions *******************/



