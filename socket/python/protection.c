
#include "motor_protection.h"
#include "rms.h"
#include "setup.h"


#define ON  (1U)
#define OFF (0U)
#define SQR(X)	((X)*(X))
/****START GLOBAL VARIBALE ***/

capture_t motor_var;


bool trip_happens=false;

extern uint8_t Motor_Class[7];
extern uint32_t All_phase_current;

extern rms_data_t   rms;  // all reading parameter
extern meter_setup_t			meter_setup;
fault_counter_t fault_trip_counter;

 bool stop=true,start=false,running=false;
/****START function only belong to that functions*******/
/*

@ helper function Motor On and off
*/
/* volt related fault ***/
static bool isUnderVolt(void);
static bool isOverVolt(void);
static bool isPhaseFailueVolt(void);
static bool isPhaseUnbalanceVolt(void);
static bool isPhaseReversalVolt(void);

static bool isUnderCurr(void);
static bool isOverCurr(void);
static bool isPhaseFailueCurr(void);
static bool isPhaseUnbalanceCurr(void);
static bool isPhaseReversalCurr(void);
static bool isRotorLockCurr(void);
static bool isProlongStartCurr(void);
static bool isInvCurrOverLoad(void);

static bool isOverPower(void);
static bool isUnderPower(void);


static bool isGroundFault(void);
static bool isEarthFault(void);

static bool isContactorFault(void);


static void thermalCapacity(void);

/*
										No of bits			Bit postions		requirmnet				    range(in dec)
1	Enable/ Disable = 1 bits ,				0							0,1												0-2
	parameters
2	Auto reset			=	2 bits					1-2						00,01,10,11(NA)						0-3			
3	trip relay 1		=	2 bits,					3-4						00,01, 11(NA)						0-3
4	alarm relay 2		=	2 bits					5-6						00,01, 11(NA)						0-3
5	trip-setting		=	10 bits,				7-16					(1-1000)%of nominal val		0-1023
	range																						 	
6 Alarm range			= 7 bits 					17-23					(50-100)%of setted val		0-127
7	Time delay/trip = 7+1 bits				24-30					(0.3-100)sec 						 0-127
										 1 bits				  31						0,1
1 means less than 1 sec.
				total bits= 32(used)
*/
static void extact_data(uint32_t *src,uint16_t *dest,uint8_t index,uint8_t num)
{
		uint8_t temp=0;
	for(temp=0;temp<num;temp++)
		*dest |= (*src & (1<<(index+temp)));
}

/*
@ helper function return current value
@Arg: pass percentage
@return  :if succes return value or else -1;
*/
int32_t FULL_LOAD_CURRENT(uint16_t percentage)
{
	int32_t rated_curr=meter_setup.meter_setup_menu[SETUP_FULL_LOAD_CURR]; /// 4.8 amp //10000 multipilcations //read from menu_config
		if(percentage>0)
		{
				return (rated_curr*percentage)/100;
		}
		else
			return -1; //return no ok
}
/*
@ helper function return voltage value
@Arg: pass percentage
@return  :if succes return value or else -1;
*/
int32_t NOMINAL_VOLTAGE(uint16_t percentage)
{
	int32_t nominal_voltage=meter_setup.meter_setup_menu[SETUP_NOMINAL_VOLT]; /// 4.8 amp //100 multipilcations
		if(percentage>0)
		{
				return (nominal_voltage*percentage)/100;
		}
		else
			return -1; //return no ok
}
/********************************************/

static float find_max(float *x,float *y,float *z)
{
	return (*x>*y?*x>*z?*x:*z:*y>*z?*y:*z);
}

static float find_min(float *x,float *y,float *z)
{
	return (*x<*y?*x<*z?*x:*z:*y<*z?*y:*z);
}
/*******************************************/

/*
 @Discriptions: if voltage is less than setted voltages
	@helper function to check UnderVolt
*/

static  bool isUnderVolt()
{
			uint16_t _under_volt_per;//=(uint16_t)menu_config[UV];

	
	if((rms.voltage[RY_PHASE]<(float)NOMINAL_VOLTAGE(_under_volt_per))|| \
		(rms.voltage[YB_PHASE]<(float)NOMINAL_VOLTAGE(_under_volt_per))|| \
			(rms.voltage[BR_PHASE]<(float)NOMINAL_VOLTAGE(_under_volt_per)))
	{
			motor_var.fault_status_reg |=UV_fault; //set UC bit high
			fault_trip_counter._counter[UV]++;
		
			return true;
	}
	else
	{
			motor_var.fault_status_reg &=(~UV_fault); //Reset UC bit high
			fault_trip_counter._counter[UV]=0;
			return false;
	}
}

/*
Discriptions: if voltage is greater than setted voltages
helper function to check overvolt
*/

static bool isOverVoltage()
{
			uint16_t _over_volt_per;//=(uint16_t)menu_config[OV];
	
	if((rms.voltage[RY_PHASE]>(float)NOMINAL_VOLTAGE(_over_volt_per))|| \
		(rms.voltage[YB_PHASE]>(float)NOMINAL_VOLTAGE(_over_volt_per))|| \
			(rms.voltage[BR_PHASE]>(float)NOMINAL_VOLTAGE(_over_volt_per)))
	{
			motor_var.fault_status_reg |=OV_fault; //set UC bit high
		fault_trip_counter._counter[OV]++;
			return true;
	}
	else
	{
			motor_var.fault_status_reg &=(~OV_fault); //Reset UC bit high
		fault_trip_counter._counter[OV]=0;
			return false;
	}
}


/*
Discrption: if any one of phase is less than certain limit consider as phase loss or failure
@helper function to check voltage phase failure
*/
static bool isPhaseFailueVolt()
{
	uint16_t _phase_failure_per= 50;//percent of nominal voltage;
	if((rms.voltage[RY_PHASE]<(float)NOMINAL_VOLTAGE(_phase_failure_per))|| \
		(rms.voltage[YB_PHASE]<(float)NOMINAL_VOLTAGE(_phase_failure_per))|| \
			(rms.voltage[BR_PHASE]<(float)NOMINAL_VOLTAGE(_phase_failure_per)))
	{
			motor_var.fault_status_reg |=VPH_F; //set UC bit high
			fault_trip_counter._counter[VPH_F]++;
			return true;
	}
	else
	{
			motor_var.fault_status_reg &=(~VPH_F_fault); //Reset UC bit high
		fault_trip_counter._counter[VPH_F]=0;
			return false;
	}
}

static bool isPhaseUnbalanceVolt(void)
{
	uint16_t _phase_ub_volt_per=10;
	float max_volt =find_max(&rms.voltage[R_PHASE],&rms.voltage[Y_PHASE],&rms.voltage[B_PHASE]);
	float min_volt =find_min(&rms.voltage[R_PHASE],&rms.voltage[Y_PHASE],&rms.voltage[B_PHASE]);
	
	int _per_error = (int)((100*(max_volt-min_volt))/max_volt);
	
	if(_phase_ub_volt_per>_per_error)
	{
		motor_var.fault_status_reg |=UB_V_fault;
		fault_trip_counter._counter[UB_V]++;
		return true;
		
	}
	else
	{
		motor_var.fault_status_reg &=(~UB_V_fault);
		fault_trip_counter._counter[UB_V]=0;
		return false;
	}
	
	
}
/*


*/

static void PhaseReversalVolt(void)
{
		//TODO phase reversal

}

static bool isUnderCurr(void)
{
	uint16_t _under_curr_per;//=(uint16_t)menu_config[UC];
	
	if((rms.display_currnet[RY_PHASE]<(float)FULL_LOAD_CURRENT(_under_curr_per))|| \
		(rms.display_currnet[YB_PHASE]<(float)FULL_LOAD_CURRENT(_under_curr_per))|| \
			(rms.display_currnet[BR_PHASE]<(float)FULL_LOAD_CURRENT(_under_curr_per)))
	{
			motor_var.fault_status_reg |=UC_fault; //set UC bit high
			fault_trip_counter._counter[UC]++;
			return true;
	}
	else
	{
			motor_var.fault_status_reg &=(~UC_fault); //Reset UC bit high
			fault_trip_counter._counter[UC]=0;
			return false ;
	
	}
}
	
static bool isOverCurr(void)
{
	uint16_t _oc_per;//=(uint16_t)menu_config[OC];
	
	if((rms.display_currnet[RY_PHASE]>(float)FULL_LOAD_CURRENT(_oc_per))|| \
		(rms.display_currnet[YB_PHASE]>(float)FULL_LOAD_CURRENT(_oc_per))|| \
			(rms.display_currnet[BR_PHASE]>(float)FULL_LOAD_CURRENT(_oc_per)))
	{
			motor_var.fault_status_reg |=OC_fault; //set UC bit high
			fault_trip_counter._counter[OC]++;
			return true;
	}
	else
	{
			motor_var.fault_status_reg &=~(OC_fault); //Reset UC bit high
			fault_trip_counter._counter[OC]=0;
			return false;
	}
	
}

static bool isPhaseFailueCurr(void)
{
	
	
}
static bool isPhaseUnbalanceCurr(void)
{
	uint16_t _phase_ub_curr_per=10;
	float max_curr =find_max(&rms.display_currnet[R_PHASE],&rms.display_currnet[Y_PHASE],&rms.display_currnet[B_PHASE]);
	float min_curr =find_min(&rms.display_currnet[R_PHASE],&rms.display_currnet[Y_PHASE],&rms.display_currnet[B_PHASE]);
	
	int _per_error = (int)((100*(max_curr-min_curr))/max_curr);
	
	if(_phase_ub_curr_per>_per_error)
	{
		motor_var.fault_status_reg |=UB_C_fault;
		fault_trip_counter._counter[UB_C]++;
		return true;
		
	}
	else
	{
		motor_var.fault_status_reg &=(~UB_C_fault);
		fault_trip_counter._counter[UB_C]=0;
		return false;
	}
	
	
}

static bool isPhaseReversalCurr(void)
{
	
	
}

static bool isRotorLockCurr(void)
{
		uint16_t _rotor_lock_Per=500;
	if((rms.display_currnet[RY_PHASE]>(float)FULL_LOAD_CURRENT(_rotor_lock_Per))|| \
		(rms.display_currnet[YB_PHASE]>(float)FULL_LOAD_CURRENT(_rotor_lock_Per))|| \
			(rms.display_currnet[BR_PHASE]>(float)FULL_LOAD_CURRENT(_rotor_lock_Per)))
			{
				motor_var.fault_status_reg |=RL_fault; //set UC bit high
				fault_trip_counter._counter[RL]++;
				return true;
			}
	else
			{
				motor_var.fault_status_reg &=~(RL_fault); //Reset UC bit high
				fault_trip_counter._counter[RL]=0;
				return false;
			}
}


static void ProlongStartCurr(void)
{
			uint16_t _prolong_lock_Per=500;
	if((rms.display_currnet[RY_PHASE]>(float)FULL_LOAD_CURRENT(_prolong_lock_Per))|| \
		(rms.display_currnet[YB_PHASE]>(float)FULL_LOAD_CURRENT(_prolong_lock_Per))|| \
			(rms.display_currnet[BR_PHASE]>(float)FULL_LOAD_CURRENT(_prolong_lock_Per)))
			{
				motor_var.fault_status_reg |=PS_fault; //set UC bit high
				fault_trip_counter._counter[PS]++;
				return true;
			}
	else
			{
				motor_var.fault_status_reg &=~(PS_fault); //Reset UC bit high
				fault_trip_counter._counter[PS]=0;
				return false;
			}
	
}

static void InvCurrOverLoad(void)
{
	
	
}

static void OverPower(void)
{
	
	
}

static void UnderPower(void)
{
	
	
}


static void GroundFault(void)
{
	
	
}

static void EarthFault(void)
{
	
	
}

static void ContactorFault(void)
{
	
	
}


static void thermalCapacity(void)
{
	
	
}





/*
@ helper function to calculate over current Trip delay
*/
uint32_t Rated_current =200000; //20 Amp
uint8_t meterClass=1;

uint32_t invTripTime=1;
static void invTimeCal()
{	
	
	 float _Ir;//(float)Average_All_phase_Current/(menu_config[FULL_LOAD_CURRENT] * 10);
	if(_Ir > 1.1)
	{
	  invTripTime =(uint32_t)(1000*((float)(29.25 * 15/*Motor_Class[menu_config[MOTOR_CLASS]]*/)\
			/(_Ir*_Ir)-1));
		 thermalCapacity();
	}
	
 
 }

/*
	@presentCapacit=previousCapacity+(timeElapsed/tripTime)*100
	@ calculate thermal capacity
*/
float presentTHCapacity=0;
float previousTHCapacity=0;

 
void thermalCapacity()
{ 
	float _tempCapacity;
	if(stop!=true && invTripTime>0)
	{
		_tempCapacity=((float)10000/(invTripTime));
		presentTHCapacity +=_tempCapacity;//previousTHCapacity+((float)100000/(invTripTime));
		previousTHCapacity=presentTHCapacity;
		
	}
}

/*
	@presentCapacit=previousCapacity-(timeElapsed/cooloingconst)*100

*/
void coolingMotor()
{
	uint8_t runningCoolingConst=15*2;
	uint8_t stopCoolingConst=15*4;
	float __temp ;
   if(presentTHCapacity>0)  
		 {
		//if(Average_All_phase_Current<FULL_LOAD_CURRENT_PERCENTAGE(100))
		{
			__temp=(float)10/runningCoolingConst;
				presentTHCapacity =previousTHCapacity-__temp;
			if(presentTHCapacity<0)
					presentTHCapacity=0;
			    previousTHCapacity=presentTHCapacity;
		}
		//else if(stop)
		{
			__temp=(float)10/stopCoolingConst;
				presentTHCapacity =previousTHCapacity-__temp;
				if(presentTHCapacity<0)
					presentTHCapacity=0;
				previousTHCapacity=presentTHCapacity;
		}
	}
}
/*
	check the presentage
*/

/*
	initila starting delay
*/

/*
@ helper function to update Trip delay time accoudingly the fault conditions
*/
 void delayselect()
{	

	
}
/****End function only belong to that functions*******/

/***START OF FUNCTIONS belong to other file***/

/*
@ check for manual/Auto start
@ bydefault it is manual start
*/
bool autostartflag=false;
 bool IsAutoStartSet(void)
 {
	 /***ByDefault it is auto  start******/
	 if(HAL_GPIO_ReadPin(GPIOF,GPIO_PIN_6))
	 {
		 //auto start
		 
		 autostartflag=true;
		 return true;
	 }
	 else
	 {
		 autostartflag=false;
		 return false;
	 }
	 
 }
/*
@ check motor start or stop button pressed
*/
// bool test_start = 0;
// bool test_stop = 0;
// bool motorStartFlag=false;
// bool motorStopFlag=false;
// void IsMotorStartButtonPress(void)
// {
//	 //TODO
//	 test_start = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1);
//	 test_stop = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3);
//	 if((HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1))==GPIO_PIN_SET)
//	 {
//		 /**its for start a motor *****/
//		 motorStartFlag=true;
//     motorStopFlag=false;
//	 }
//	 else if((HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3))==GPIO_PIN_SET)
//	 {
//		 /***its for stop  a motor **/
//		 motorStartFlag=false;
//     motorStopFlag=true;
//	 }
//	
// }
 


  /*
	@ Short_Circuit  starter avg current between 700 % to 1000% 
	in running mode only
	trip delay =immidiately
 */
 bool Short_Circuit()
 {	/*
	 if(Average_All_phase_Current > FULL_LOAD_CURRENT_PERCENTAGE(SHORT_CIRCUIT_MIN))   
	 {
	 if(Rms_t.curentRms[RY_PHASE] > FULL_LOAD_CURRENT_PERCENTAGE(menu_config[SHORT_CIRCUIT]))
	 {
		 tripStatus=SC_flag;
		 return true;
	 }
	 else if(Rms_t.curentRms[YB_PHASE] > FULL_LOAD_CURRENT_PERCENTAGE(menu_config[SHORT_CIRCUIT]))
	 {
		 tripStatus=SC_flag;
		 return true;
	 }
	 else if(Rms_t.curentRms[BR_PHASE] > FULL_LOAD_CURRENT_PERCENTAGE(menu_config[SHORT_CIRCUIT]))
	 {
		 tripStatus=SC_flag;
		 return true;
	 }
	 else
	 {
		 if(tripStatus==SC_flag)
		  tripStatus=NONE;
		 return false;
	 }
 }
	 else
	 {
		 if(tripStatus==SC_flag)
		  tripStatus=NONE;
		 return false;
	 }*/
 }

 /*
	@ Rotor_Lock  starter avg current between 150 % to 800% 
	in running mode only
	trip delay =0.5 -10sec
 */
 
 bool Rotor_Lock()
 {
	 /*
	 if(Average_All_phase_Current > FULL_LOAD_CURRENT_PERCENTAGE(ROTOR_LOCK_MIN+1))
	 {
						 if(Rms_t.curentRms[RY_PHASE] > FULL_LOAD_CURRENT_PERCENTAGE(menu_config[ROTOR_LOCK]))
						 {
							 capture_t.__captureFault[RL_val]=Rms_t.curentRms[RY_PHASE];
							// tripStatus=RL_flag;
							 return true;
						 }
						 else if(Rms_t.curentRms[YB_PHASE] > FULL_LOAD_CURRENT_PERCENTAGE(menu_config[ROTOR_LOCK]))
						 {
							 capture_t.__captureFault[RL_val]=Rms_t.curentRms[YB_PHASE];
							// tripStatus=RL_flag;
							 return true;
						 }
						 else if(Rms_t.curentRms[BR_PHASE] > FULL_LOAD_CURRENT_PERCENTAGE(menu_config[ROTOR_LOCK]))
						 {
							 capture_t.__captureFault[RL_val]=Rms_t.curentRms[BR_PHASE];
							// tripStatus=RL_flag;
							 return true;
						 }
						 else
							 return false;
		}
	  else 
		{
			return false;
		}*/
 }
 
 
 /*
	@ prolong  starter avg current between 150 % to 800% 
	in starting mode only
 trip delay =0.5 -5 sec
 */
 bool Prolong_Starting()
 {
	 #if(0)
	 /*
	 if(Average_All_phase_Current > FULL_LOAD_CURRENT_PERCENTAGE(PROLONG_STARTING_MIN)\
		/* && Average_All_phase_Current < FULL_LOAD_CURRENT_PERCENTAGE(PROLONG_STARTING_MAX))*/
	 {
					 if(Rms_t.curentRms[RY_PHASE] > \
						 FULL_LOAD_CURRENT_PERCENTAGE(menu_config[PROLONG_STARTING]))
					 {
						 capture_t.__captureFault[PL_val]=Rms_t.curentRms[RY_PHASE];
						// tripStatus=PL_flag;
						 return true;
					 }
					 else if(Rms_t.curentRms[YB_PHASE] > FULL_LOAD_CURRENT_PERCENTAGE(menu_config[PROLONG_STARTING]))
					 {
						  capture_t.__captureFault[PL_val]=Rms_t.curentRms[YB_PHASE];
						// tripStatus=PL_flag;
						 return true;
					 }
					 else if(Rms_t.curentRms[BR_PHASE] > FULL_LOAD_CURRENT_PERCENTAGE(menu_config[PROLONG_STARTING]))
					 {
						  capture_t.__captureFault[PL_val]=Rms_t.curentRms[BR_PHASE];
						// tripStatus=PL_flag;
						 return true;
					 }
					 else
						 return false;
		}
	  else
		{
			return false;
		}
		*/
		#endif
 }
 
/*
@ Motor functions
@ if motor is in cold condtions set D_time to TODO
@ if motor is in Hot condtions set D_time to TODO
@ Check is auto/mannual start set
@ check under current,over current,under volatge,over volatge
*/
/* helper fun */
 static void imidiateTrip()
 {
		//relayOnOff(OFF);
	  trip_happens=true;
	  clearFlag();
 }
 
 
 
 /*
	@ checking is motor start or not 
 */
  void Check_Motor_status()
 {
	 #if(0)
	 
	   //running mode
	 if(RelayOnStatus==true)
	 {
	 if(start==true && stop==false)
	 {
	  if(Average_All_phase_Current < FULL_LOAD_CURRENT_PERCENTAGE(110) \
			&& Average_All_phase_Current > FULL_LOAD_CURRENT_PERCENTAGE(15))    
	   {
					stop=false;
		      start=false;
		      running=true;
	    } 
   }
	
	 if(running==false)
	 {
	 //start mode
	  if(Average_All_phase_Current > FULL_LOAD_CURRENT_PERCENTAGE(110))
	 {
					 stop=false;
					 start=true;
					 running=false;
		       
	 }
	 //stop mode
	 else if(Average_All_phase_Current < FULL_LOAD_CURRENT_PERCENTAGE(15))
	 {
				 stop=true;
				 start=false;
				 running=false;			
	 }
	 
		}
	} 
	 else 
	 {
				 stop=true;
				 start=false;
				 running=false;	
	 }
	 #endif
}
 

 static void motorConditionCheck()
 {
	 #if(0)
	
			  if(menu_config[SHORT_CIRCUIT]!=0 && Short_Circuit()) //Short_Circuit
								{
											imidiateTrip();
								}
					else
				 {
								if(menu_config[PHASE_LOSS_ED]!=0 && isPhaseLoss())
								{
								 imidiateTrip(); 
								}
								else if(menu_config[PHASE_REVERSAL_E_D]!=0 &&isPhaseReversal())
								{
									 imidiateTrip();
								}
								else 
								{
								
										/* under and over volt*/
										 if(menu_config[OVER_VOLTAGE]!=0 &&isOverVoltage())
										{
											fault_counter_t.__counter[OverVolt_tim]++;
											fault_counter_t.__counter[UnderVolt_tim]=0;
										}
										else  if(menu_config[UNDER_VOLTAGE]!=0 && isUnderVoltage()){
											fault_counter_t.__counter[UnderVolt_tim]++;
											fault_counter_t.__counter[OverVolt_tim]=0;
										}
										else
										{
											fault_counter_t.__counter[OverVolt_tim]=0;
											fault_counter_t.__counter[UnderVolt_tim]=0;
										}
										/***********************************************/
									  if(	running)
										{
												// current and voltage unbalance check
												 if(menu_config[PHASE_UNBALANCE_CURRENT]!=0 && isPhaseUnblanceCurr())
													{
															fault_counter_t.__counter[PhaseUnblanceCurr_tim]++;
													}
													else
														fault_counter_t.__counter[PhaseUnblanceCurr_tim]=0;
													
													if(menu_config[PHASE_UNBALANCE_VOLTAGE]!=0 && isPhaseUnblanceVolt())
													{
															fault_counter_t.__counter[PhaseUnblanceVolt_tim]++;
													}
													else
														fault_counter_t.__counter[PhaseUnblanceVolt_tim]=0;
														/****************************************************/
													//under and over current
																	if(menu_config[UNDER_CURRENT]!=0 && isUnderCurrent())
																	{
																		 fault_counter_t.__counter[UnderCurr_tim]++;
																		 fault_counter_t.__counter[OverCurr_tim]=0;
																	}
																	else if(menu_config[OVER_CURRENT]!=0 && isOverCurrent())
																	{
																		 fault_counter_t.__counter[OverCurr_tim]++;
																		 fault_counter_t.__counter[UnderCurr_tim]=0;
																	}
																	else
																	{
																		 fault_counter_t.__counter[UnderCurr_tim]=0;
																		 fault_counter_t.__counter[OverCurr_tim]=0;
																	}
														/*****************************************************/
															if(menu_config[ROTOR_LOCK]!=0 && Rotor_Lock ())
															{
																	 fault_counter_t.__counter[RotorLock_tim]++;
															}
															else
															{
																fault_counter_t.__counter[RotorLock_tim]=0;
															}
										}
										else if(start)
										{
													if( menu_config[PROLONG_STARTING]!=0 && Prolong_Starting())
													{
														 fault_counter_t.__counter[ProLong_tim]++;
													}
													else
														 fault_counter_t.__counter[ProLong_tim]=0;
										}
										 
									 }
						  }
			
			#endif	
	}
			
		 			 	
 
 /*******************************************/
	
	static void preStartingMotorStatus()
 {
	 #if(0)
	 /*
	 static uint8_t relayTurnOnDelay=0;
	 
	 / if(menu_config[PHASE_LOSS_ED]!=0 && isPhaseLoss()/*||isPhaseReversal()*/)
		  {
					imidiateTrip();
		  }
		else if(menu_config[PHASE_REVERSAL_E_D]!=0 && isPhaseReversal())
		{
				imidiateTrip();
		}
		else  
		{
				if(menu_config[PHASE_UNBALANCE_VOLTAGE]!=0 && isPhaseUnblanceVolt())
						{
						 fault_counter_t.__counter[PhaseUnblanceVolt_tim]++;
						}
						else{
								fault_counter_t.__counter[PhaseUnblanceVolt_tim]=0;
								
			  if(menu_config[OVER_VOLTAGE]!=0 && isOverVoltage())
						{
								fault_counter_t.__counter[OverVolt_tim]++;
						}
						else  if(menu_config[UNDER_VOLTAGE]!=0 && isUnderVoltage())
							{
								fault_counter_t.__counter[UnderVolt_tim]++;
							}
							else
							{
								 fault_counter_t.__counter[OverVolt_tim]=0;
								 fault_counter_t.__counter[UnderVolt_tim]=0;
								
											
								if(tripStatus !=UC_flag && tripStatus!=OC_flag && tripStatus !=RL_flag
									&&tripStatus !=CurrentUnbalance &&tripStatus !=PL_flag  &&tripStatus !=ThermalCapacity_Flag
								 &&tripStatus!=Ph_Current_Loss_1 &&tripStatus!=Ph_Current_Loss_2 &&tripStatus!=Ph_Current_Loss_3)
								
								{
												relayTurnOnDelay++;
												if(relayTurnOnDelay>20){
													if(presentTHCapacity <15)
													{
														relayOnOff(ON);	
														tripStatus=NONE;
														relayTurnOnDelay=0;
														trip_happens=false;
													}
												} 		
								 }
							 }
								
					}
				}
		
		#endif
 }
/***********************/
 /*
	@ motor function
 */
 
void motorfunctions(void)
 {	
	 /*
if(tripStatus!=ThermalCapacity_Flag)
{
	 Check_Motor_status();
	 if(stop==true) 
	 {
		 
			preStartingMotorStatus();
			delayselect();
	 }
	 else{
		 
				
				if((start ||running) && trip_happens==false)
					{
						motorConditionCheck();
						delayselect();
					}
					
				}
							
	}
else if(presentTHCapacity <1)
{
	tripStatus=NONE;
}
							TripRelay();
							//hysteresis();
							invTimeCal();
							coolingMotor();
							*/

}


/* 
@Trip relay to protect motor
@update the fault status
*/

void TripRelay(void)
{
	/*
	 //if( RelayOnStatus==true)
	 {	
		 if(fault_counter_t.__counter[UnderVolt_tim]> \
			 delaySetup_t.__delaySetup[UnderVolt_tim]/10)
		 {
			 faultCap_Val=capture_t.__captureFault[UV_val];
				relayOnOff(OFF); //if any fault occur stop motor
			  trip_happens=true;
				tripStatus=UV_flag; //trip due to under volt
			 fault_counter_t.__counter[UnderVolt_tim]=0;
			  clearFlag();
		 }
		 else if(fault_counter_t.__counter[OverVolt_tim]> \
			 delaySetup_t.__delaySetup[OverVolt_tim]/10)
		 {
			  faultCap_Val=capture_t.__captureFault[OV_val];
				relayOnOff(OFF); //if any fault occur stop motor
			  trip_happens=true;
				tripStatus=OV_flag;
			 fault_counter_t.__counter[OverVolt_tim]=0;
			  clearFlag();
		 }
		 else if(fault_counter_t.__counter[UnderCurr_tim]> \
			 delaySetup_t.__delaySetup[UnderCurr_tim]/10)
		 {
			 faultCap_Val=capture_t.__captureFault[UC_val];
				relayOnOff(OFF); //if any fault occur stop motor
			  trip_happens=true;
				tripStatus=UC_flag;
			 fault_counter_t.__counter[UnderCurr_tim]=0;
			  clearFlag();
		 }
		  else if(fault_counter_t.__counter[OverCurr_tim]> \
			 delaySetup_t.__delaySetup[OverCurr_tim]/10)
		 {
			 faultCap_Val=capture_t.__captureFault[OC_val];
				relayOnOff(OFF); //if any fault occur stop motor
			  trip_happens=true;
				tripStatus=OC_flag;
			 fault_counter_t.__counter[OverCurr_tim]=0;
			  clearFlag();
		 }
		 else if(fault_counter_t.__counter[PhaseUnblanceVolt_tim]> \
			 delaySetup_t.__delaySetup[PhaseUnblanceVolt_tim]/10)
		 {
			 faultCap_Val=capture_t.__captureFault[VoltUnb_val];
				relayOnOff(OFF); //if any fault occur stop motor
			  trip_happens=true;
				tripStatus=VoltageUnbalance;
			 fault_counter_t.__counter[PhaseUnblanceVolt_tim]=0;
			  clearFlag();
		 }
		  else if(fault_counter_t.__counter[PhaseUnblanceCurr_tim]> \
			 delaySetup_t.__delaySetup[PhaseUnblanceCurr_tim]/10)
		 {
			 faultCap_Val=capture_t.__captureFault[CurrUnb_val];
				relayOnOff(OFF); //if any fault occur stop motor
			  trip_happens=true;
				tripStatus=CurrentUnbalance;
			 fault_counter_t.__counter[PhaseUnblanceCurr_tim]=0;
			  clearFlag();
		 }
		  else if(fault_counter_t.__counter[RotorLock_tim]> \
			 delaySetup_t.__delaySetup[RotorLock_tim]/10)
		 {
			  faultCap_Val=capture_t.__captureFault[RL_val];
				relayOnOff(OFF); //if any fault occur stop motor
			  trip_happens=true;
				tripStatus=RL_flag;
				fault_counter_t.__counter[RotorLock_tim]=0;
			  clearFlag();
		 }
		 
		  else if(fault_counter_t.__counter[ProLong_tim]> \
			 delaySetup_t.__delaySetup[ProLong_tim]/10)
		 {
			 faultCap_Val=capture_t.__captureFault[PL_val];
				relayOnOff(OFF); //if any fault occur stop motor
			  trip_happens=true;
				tripStatus=PL_flag;
				fault_counter_t.__counter[ProLong_tim]=0;
			  clearFlag();
		 }
		 else if(presentTHCapacity>=100 && tripStatus!=ThermalCapacity_Flag)
		{
			relayOnOff(OFF);
			trip_happens=true;
			tripStatus=ThermalCapacity_Flag;
			clearFlag();
		}
	}
*/
}
 
 /* 
@ Reset relay and all  flag status
*/
void reset(void)
 {
	 if((GPIOB->IDR & GPIO_PIN_2)>>2==GPIO_PIN_RESET)
	 {
			
	 }
 }
 /* 
@ Condition :A phase failure occurs when one phase of a three-phase
 supply is open circuited. It is also referred to as single-phasing
 when a three-phase motor is running on two phases due to the loss 
of voltage on one phase. More current will flow through the other
 two lines and heat is generated in the stator winding. A phase loss 
 that is not quickly detected and rectified can result in equipment
 failure or motor burnout
 trip time =0.5~5 sec
*/
bool isPhaseLoss(void)
{	
	/*if(stop==false)
	{
							//less than 30 voltage in any of one phase only
							// consider its an open
						if(Rms_t.voltageRms[RY_PHASE] < 29000)
						{
							tripStatus=Ph_Voltage_Loss_1;
							return true;		
						}
						else if(Rms_t.voltageRms[YB_PHASE] < 29000)
						{
							tripStatus=Ph_Voltage_Loss_2;
							return true;		
						}
						else if(Rms_t.voltageRms[BR_PHASE] < 29000)
						{
							tripStatus=Ph_Voltage_Loss_3;
							return true;		
						}	
						else if(Rms_t.curentRms[RY_PHASE] < FULL_LOAD_CURRENT_PERCENTAGE(15))
						{
							tripStatus=Ph_Current_Loss_1;
							return true;
						}
						else if(Rms_t.curentRms[YB_PHASE] < FULL_LOAD_CURRENT_PERCENTAGE(15))
						{
							tripStatus=Ph_Current_Loss_2;
							return true;
						}
						else if(Rms_t.curentRms[BR_PHASE] < FULL_LOAD_CURRENT_PERCENTAGE(15))
						{
							tripStatus=Ph_Current_Loss_3;//PhaseLoss
							return true;
						}
						else
						{
							 if(tripStatus==Ph_Voltage_Loss_1 ||tripStatus==Ph_Voltage_Loss_2||tripStatus==Ph_Voltage_Loss_3
								 || tripStatus==Ph_Current_Loss_1 ||tripStatus==Ph_Current_Loss_1||tripStatus==Ph_Current_Loss_1)
							 {
									tripStatus=NONE;
							 }
							return false;
						}
					}
					else if(stop==true)
					{
						//check voltage while in stop conditions
						if(Rms_t.voltageRms[RY_PHASE] < 29000)
						{
							tripStatus=Ph_Voltage_Loss_1;
							return true;		
						}
						else if(Rms_t.voltageRms[YB_PHASE] < 29000)
						{
							tripStatus=Ph_Voltage_Loss_2;
							return true;		
						}
						else if(Rms_t.voltageRms[BR_PHASE] < 29000)
						{
							tripStatus=Ph_Voltage_Loss_3;
							return true;		
						}
							else {
								 if(tripStatus!=Ph_Current_Loss_1 &&tripStatus!=Ph_Current_Loss_2&&tripStatus!=Ph_Current_Loss_3)
								 {
								 if(tripStatus==Ph_Voltage_Loss_1 ||tripStatus==Ph_Voltage_Loss_2||tripStatus==Ph_Voltage_Loss_3)
								 {tripStatus=NONE;}
								}
								 return false;
							}
					}
	*/
}

  /* 
@ Condition :  Phase reversal occurs when any two phases of a three-phase
supply are interchanged from the normal sequence
 trip time= within 0.15sec
*/


bool isPhaseReversal()
{	
	/*uint16_t _noofsample120=(300*NO_Of_Sample_per_Cycle)/360;
	if(Rms_t.voltageRms[RY_PHASE]>29000 && Rms_t.voltageRms[YB_PHASE]>29000)
	{

	if(Stored.STOREDRevCount >= (_noofsample120-5) \
		  && Stored.STOREDRevCount <= (_noofsample120+5))
	{
		if(tripStatus==PhaseReversal)
		tripStatus=NONE;
	return false;
	}
	else
	{

		tripStatus=PhaseReversal;
		return true;
	}
}
	else
	{
		if(tripStatus==PhaseReversal)
		tripStatus=NONE;
		return false;
	}
*/
}
  /* 
@ Condition : Any deviation in voltage and current waveforms from perfect
sinusoidal in terms of magnitude or phase shift is termed as unbalance
  Setting range : 10~50% of imbalance
*/

bool isPhaseUnblanceCurr(void)
{
	/*
//	float _temp = (float)Rms_t.voltageRms[0]/Rms_t.voltageRms[1];
	int8_t current_phaseError =  ((Highest_Current - Lowest_Current) *100)/ Lowest_Current;
	 if( current_phaseError > menu_config[PHASE_UNBALANCE_CURRENT])
	{
			capture_t.__captureFault[CurrUnb_val]=current_phaseError;
			tripStatus=CurrentUnbalance;//PhaseUnblance;
		return true;	
	}
	 else
	 {
		 if(tripStatus==CurrentUnbalance)
		 {
		capture_t.__captureFault[CurrUnb_val]=0;
		 tripStatus=NONE;
		 }
		return false;
	 }
}
bool isPhaseUnblanceVolt(void)
{
	
//	float _temp = (float)Rms_t.voltageRms[0]/Rms_t.voltageRms[1];
	int8_t voltage_phaseError =  ((Highest_Voltage - Lowest_Voltage)*100) / Lowest_Voltage;
	if(voltage_phaseError> menu_config[PHASE_UNBALANCE_VOLTAGE] )
	{
		capture_t.__captureFault[VoltUnb_val]=voltage_phaseError;
		tripStatus=VoltageUnbalance;
		return true;			
	}
	 else
	 {
		 if(tripStatus==VoltageUnbalance)
		 {
		  tripStatus=NONE;
			 capture_t.__captureFault[VoltUnb_val]=0;
		 }
		return false;
	 }*/
}
/*
	@if falt happen due to over voltage and under voltage and it clear automatics
		then reset relay .
*/
void hysteresis()
{
/*	static uint32_t __temp_delay;
	if(RelayOnStatus==false)
	{
	if(trip_happens && tripStatus==OV_flag)
	{
		if((Rms_t.voltageRms[RY_PHASE] < (menu_config[OVER_VOLTAGE] / 10)-10) \
			&&((Rms_t.voltageRms[YB_PHASE] < (menu_config[OVER_VOLTAGE] / 10))-10)
			&&(Rms_t.voltageRms[BR_PHASE] < (menu_config[OVER_VOLTAGE] / 10))-10)
		{
			__temp_delay++;
			if(__temp_delay>20)
			{
					clearFlag();
				__temp_delay=0;
					relayOnOff(ON);	
				tripStatus=NONE;
				trip_happens=false;
			}
		}
	}
	else if(trip_happens && tripStatus==UV_flag)
	{
		if((Rms_t.voltageRms[RY_PHASE] > (menu_config[UNDER_VOLTAGE] / 10)+10) \
			&&((Rms_t.voltageRms[YB_PHASE] > (menu_config[UNDER_VOLTAGE] / 10))+10)
			&&(Rms_t.voltageRms[BR_PHASE] >(menu_config[OVER_VOLTAGE] / 10))+10)
		{
					__temp_delay++;
			if(__temp_delay>20)
			{
					clearFlag();
				__temp_delay=0;
					relayOnOff(ON);	
					tripStatus=NONE;
					trip_happens=false;
			}
		}
	}
}*/
}
void clearFlag()
{
	// make flag in default mode
	         stop=true;
					 start=false;
					 running=false;
	
}
/***END of FUNCTIONS belong to other file***/
 
 
