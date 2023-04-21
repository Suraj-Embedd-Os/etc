# Thermostat_1.0
Thermostat Project v1.0

A programmable thermostat controlled via a home's automation system can save significant costs on heating and cooling bills by ensuring
that the home wastes as little energy as possible on HVAC consumption when, for example, the occupants of the home are away or asleep. 
Programmable, automated thermostats allow homeowners to turn heating and air conditioning on or off remotely or from within the home 
via a programmable schedule. Automated thermostats can often store and repeat multiple daily settings, which homeowners can generally 
override whenever necessary without affecting the core schedule.

There is 3 major module in the project.
1 Atmega4809 microcontroller.
  All the action and control performed by using this module , device read temperature ,humidity and Co2 from the sensor  SCD30.
  and based on the limit set by the user 
  
  
 #include"D:\\suraj\\FlightCoach-TKCS\\git\\Thermostat_1.0\\Operation_Control\\flightCoachOperations\\operation.h"
 #include"D:\\suraj\\FlightCoach-TKCS\\git\\Thermostat_1.0\\Operation_Control\\flightCoachOperations\\common_def.h"
 #include"D:\\suraj\\FlightCoach-TKCS\\git\\Thermostat_1.0\\Operation_Control\\flightCoachOperations\\SCD30.h"
 #include"D:\\suraj\\FlightCoach-TKCS\\git\\Thermostat_1.0\\Operation_Control\\flightCoachOperations\\setup_menu.h"
