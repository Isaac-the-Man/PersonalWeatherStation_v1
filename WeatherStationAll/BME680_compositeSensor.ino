

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BME680.h"

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME680 bme; // I2C
//Adafruit_BME680 bme(BME_CS); // hardware SPI
//Adafruit_BME680 bme(BME_CS, BME_MOSI, BME_MISO,  BME_SCK);

//void setup() {
//  Serial.begin(9600);
//  while (!Serial);
//  Serial.println(F("BME680 test"));
//
//  initBME();
//}
//
//void loop() {
//  double readings[4];
//  getBMEValues(readings);
//  
//  Serial.print("Temperature = ");
//  Serial.print(readings[0]);
//  Serial.println(" *C");
//
//  Serial.print("Pressure = ");
//  Serial.print(readings[1]);
//  Serial.println(" hPa");
//
//  Serial.print("Humidity = ");
//  Serial.print(readings[2]);
//  Serial.println(" %");
//
//  Serial.print("Gas = ");
//  Serial.print(readings[3]);
//  Serial.println(" KOhms");
//
//  Serial.println();
//  delay(2000);
//}

// initialize BME680 sensor
void initBME(){
  bme.begin();
  // Set up oversampling and filter initialization
  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
  bme.setGasHeater(320, 150); // 320*C for 150 ms
}

// read BME values
// return: temperature, pressure, humidity, gas_resistance
void getBMEValues(double* output){
  if (bme.performReading()) {
    // read successful
    output[0] = bme.temperature;
    output[1] = (bme.pressure / 100.0);
    output[2] = bme.humidity;
    output[3] = (bme.gas_resistance / 1000.0);
  }else {
    output[0] = 0;
    output[1] = 0;
    output[2] = 0;
    output[3] = 0;
  }
}
