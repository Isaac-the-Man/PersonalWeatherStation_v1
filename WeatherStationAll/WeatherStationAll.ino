/*
 * Weather Station Integrated Code
 * By Steven Wang @simplycodebased.org
 * 7/9/2019
*/

// Test All sensors together of the WEATHER STATION
// sensors: UV, particle, composite

void setup() {
  // initialize all sensors
  Serial.begin(9600);
  initAQ();
  initUV();
  initBME();
  delay(2000);
}

void loop() {
  // read all sensors
  double AQreadings[1], BMEreadings[4], UVreadings[1];
  getAQValues(AQreadings);
  getBMEValues(BMEreadings);
  getUVValues(UVreadings);

  // broadcast to serial
  // the order should be:
  // humidity, temperature, pressure, AQ, UV, Particle, IMG
  double broadcasts[7];
  broadcasts[0] = BMEreadings[2];
  broadcasts[1] = BMEreadings[0];
  broadcasts[2] = BMEreadings[1];
  broadcasts[3] = BMEreadings[3];
  broadcasts[4] = UVreadings[0];
  broadcasts[5] = AQreadings[0];
  broadcasts[6] = 1.0;
  char finalStr[90];
  formatReadings(broadcasts, finalStr);
  Serial.write(finalStr);

  // comment out this block for output
//  Serial.println("");
//  Serial.print("Particle Density: ");
//  Serial.println(AQreadings[0]);
//  Serial.print("UV intensity: ");
//  Serial.println(UVreadings[0]);
//  Serial.print("Temperature: ");
//  Serial.println(BMEreadings[0]);
//  Serial.print("Pressure: ");
//  Serial.println(BMEreadings[1]);
//  Serial.print("Humidity: ");
//  Serial.println(BMEreadings[2]);
//  Serial.print("Gas: ");
//  Serial.println(BMEreadings[3]);
//  Serial.println(" ");
  
  delay(2000);
}
