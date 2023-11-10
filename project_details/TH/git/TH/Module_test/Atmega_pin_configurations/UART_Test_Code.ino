#include <SoftwareSerial.h>

// define the pins for the first UART
#define RX_PIN_1 4
#define TX_PIN_1 5

// define the pins for the second UART
#define RX_PIN_2 48
#define TX_PIN_2 1

//define the pins for the third UART
#define RX_PIN_3 8
#define TX_PIN_3 9

//define the output pinmode
#define FAN               44
#define FIRST_STG_HEAT    45
#define REV_VALVE         46
#define SECOND_STG_HEAT   16
#define FIRST_STAGE_COOL 17
#define SECOND_STAGE_COOL 18
#define HUM               19
#define MOD_A             20
#define MOD_B             21
#define OAT1              22
#define TEST_LED          23
#define AREF              27
#define DEHUM             33
#define AUX1              34
#define AUX2              35
#define PWM_CO2           38
#define RDY               39
#define RESET             40

// create instances of SoftwareSerial
SoftwareSerial uart1(RX_PIN_1, TX_PIN_1); // for sensor
SoftwareSerial uart2(RX_PIN_2, TX_PIN_2); // for display
SoftwareSerial uart3(RX_PIN_3, TX_PIN_3); //for debugger
SoftwareSerial uart4(10, 11); // for wifi module

void setup() {
  // initialize serial communication for debugging purposes
  Serial.begin(9600);
  while (!Serial);

  // initialize each instance of SoftwareSerial
  uart1.begin(9600);
  uart2.begin(9600);
  uart3.begin(115200);
  uart4.begin(115200);

  /////////
  pinMode(FAN, OUTPUT);
  pinMode(FIRST_STG_HEAT, OUTPUT);
  pinMode(REV_VALVE, OUTPUT);
  pinMode(SECOND_STG_HEAT, OUTPUT);
  pinMode(FIRST_STAGE_COOL, OUTPUT);
  pinMode(SECOND_STAGE_COOL, OUTPUT);
  pinMode(HUM, OUTPUT);
  pinMode(MOD_A, OUTPUT);
  pinMode(MOD_B, OUTPUT);
  pinMode(OAT1, OUTPUT);
  pinMode(TEST_LED, OUTPUT);
  pinMode(AREF, OUTPUT);
  pinMode(DEHUM, OUTPUT);
  pinMode(AUX1, OUTPUT);
  pinMode(AUX2, OUTPUT);
  pinMode(PWM_CO2, OUTPUT);
  pinMode(RDY, OUTPUT);
  pinMode(RESET, OUTPUT);

  // your setup code here
}

void loop() {
  // your main code here
  // use the appropriate instance of SoftwareSerial for each device
  uart1.write("Sensor Data");
  uart2.print("Display Data");
  uart3.print("Display on the serial monitor"); // debugger
  uart4.println("WiFi Data");

  delay(1000); // add some delay before sending the data again
}
