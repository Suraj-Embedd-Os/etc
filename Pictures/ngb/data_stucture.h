
typedef struct fault_data_frame
{
	char start_msg[4]; //ngb
	unsigned int status_reg; //
	uint8_t id; //
	float data[3];//r y b or only data
	float trip_data;
	uint8_t relay_status;
	char end_msg[4];
}fault_data_frame_t;

typedef struct measured_data_frame
{
	char start_msg[4];
	unsigned int status_reg;
	float data[3];//r y b or only data
	uint8_t relay_status;
	char end_msg[4];
}measured_data_frame_t;


typedef struct setup_data_frame
{
	char start_msg[4];
	unsigned int status_reg;
	uint8_t id;
	uint16_t trip_range;
	uint16_t alarm_range;
	uint16_t delay_range;
	uint8_t auto_reset;
	char end_msg[4];
}setup_data_frame_t;