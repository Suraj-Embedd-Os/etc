

#ifndef __COMMAND_H
#define __COMMAND_H

/* enum and structure declare here */
typedef enum{
	GET_CABLE_COUNT=1,
	GET_SENSOR_DATA,
	GET_VERSION,
	LOCATE_TO_ZERO_POSITIONS,
	PERFORM_SWEEP,
	SET_CABLE_COUNTER_TICKS,
	SET_CENTER_ANGLE,
	SET_NUMBER_OF_SAMPLE,
	SET_OVERSAMPLES,
	SET_REPEAT_RATE,
	SET_SAMPLE_RATE,
	SET_SCAN_ARC_SIZE,
	SET_STEP_SIZE,
	SET_TX_POWER,
	SET_TX_PULSE_WIDTH,
	STEP_MOTOR_ANTI_CLOCKWISE,
	STEP_MOTOR_CLOCKWISE,
	
	TOTAL_COMMAND_PARA
	
}CMD_LIST_ENUM;


/* function declare here */
void profile_survey(unsigned char * cmd,int _cmd_len,char *rd_buff,int _size);
void profiler_discovery(char *eth_ip_addr,char *rd_buff,int _size);
void select_options(void);
void show_options(void);
int create_socket();

void get_cable_count(void);
void get_sensor_data(void);
void get_version(void);
void locate_to_zero_position(void);
void perform_sweep(void);
void set_cable_counter_ticks(void);
void set_centre_angle(void);
void set_number_of_samples(void);
void set_oversamples(void);
void set_repeat_rate(void);
void set_sample_rate(void);
void set_scan_arc_size(void);
void set_step_size(void);
void set_tx_power(void);
void set_tx_pulse_width(void);
void step_motor_anti_clockwise(void);
void step_motor_clockwise(void);
void create_pcd_format(char *buff,int len);

//
float recieve_from_encoder();


#endif




