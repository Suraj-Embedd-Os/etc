#include <scd30_modbus.h>
#include <ArduinoModbus.h>
#include "Nextion.h"
#include <NexText.h>
#include <SoftwareSerial.h>
SoftwareSerial Serial2(10, 11);
class NexSerial : public Stream {
  public:
    virtual int available(void);
    virtual int read(void);
    virtual void flush(void);
    virtual size_t write(uint8_t c);
};
int NexSerial::available(void) {
  return Serial2.available();
}
int NexSerial::read(void) {
  return Serial2.read();
}
void NexSerial::flush(void) {
  Serial2.flush();
}
size_t NexSerial::write(uint8_t c) {
  Serial2.write(c);
}



// #define uint32_t unsigned int
// #define uint16_t unsigned int
// #define unit8_t unsigned int 
// #define File _myFile

// Modbus address of SCD30
#define SCD30_ADDRESS 0x61

#define  Serial2 Serial

// Modbus command for reading measurement values
#define SCD30_READ_MEASUREMENT 0x0300

// Define SoftwareSerial pins
#define RX_PIN PB0
#define TX_PIN PB1

#define PWM_CO2 PF4
#define READY PF5

// Create SoftwareSerial object
// SoftwareSerial modbusSerial(RX_PIN, TX_PIN);

// Create SCD30_modbus object
SCD30_Modbus scd30;

// Create Nextion object
NexText t0 = NexText(0, 1, "t0");

void setup() {
  // Initialise serial port for debugging 
  Serial.begin(9600);

  // Initialise Nextion display
  nexInit();

  // Set SCD30 Modbus address
  // modbus.setSlaveId(SCD30_ADDRESS);    
   
  while (!Serial) 
    delay(10);

  Serial.println("SCD30 modbus test!");

  // Initialize sensor
  scd30.begin(&Serial);

  // Set measurement interval to 2 seconds
  if (!scd30.setMeasurementInterval(2)) {
    Serial.println("ERROR! Failed to set measurement interval");
    while(1) { 
      delay(10);
    }
  }
  Serial.print("Measurement Interval: "); 
  Serial.print(scd30.getMeasurementInterval()); 
  Serial.println(" seconds");

  // Start continuous measurement with no pressure offset
  if (!scd30.startContinuousMeasurement(0)) {
    Serial.println("ERROR! Failed to start continuous measurement");
    while(1) { 
      delay(10);
    }
  }

  // Set temperature offset to 0
  if (!scd30.setTemperatureOffset(0)) {
    Serial.println("ERROR! Failed to set temperature offset");
    while(1) { 
      delay(10);
    }
  }
  Serial.print("Temperature offset: ");
  Serial.print((float)scd30.getTemperatureOffset()/100.0);
  Serial.println(" degrees C");

  // Enable automatic self calibration (ASC)
  if (!scd30.selfCalibrationEnabled(true)) {
    Serial.println("ERROR! Failed to enable self calibration");
    while(1) { 
      delay(10);
    }
  }
  if (scd30.selfCalibrationEnabled()) {
    Serial.print("Self calibration enabled");
  } else {
    Serial.print("Self calibration disabled");
  }
}

void loop() {
  if (scd30.dataReady()) {
    Serial.println("Data available!");

    if (!scd30.read()) { 
      Serial.println("Error reading sensor data");
      return; 
    }

    Serial.print("CO2: ");
    Serial.print(scd30.CO2, 3);
    Serial.println(" ppm");

    // Display CO2 value on Nextion display
    char buffer[10];
    dtostrf(scd30.CO2, 4, 1, buffer);
    t0.setText(buffer);

    Serial.println("");
  }

  delay(2000);
}
