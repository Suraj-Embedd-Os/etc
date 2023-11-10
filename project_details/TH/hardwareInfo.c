
//G contact
static int fan(uint8_t status); 

//W contact
static int first_stage_heat(uint8_t status);
static int second_stage_heat(uint8_t status);
static int first_stage_cool(uint8_t status);

// Y/Y2 contact 
static int second_stage_cool(uint8_t status); 

// O/B contact
static int rev_valve(uint8_t status);
static int humidity_control(uint8_t status);
//dehumid
static int dehumidity_control(uint8_t status);
static int aux_1_out(uint8_t status);
static int aux_2_out(uint8_t status);
