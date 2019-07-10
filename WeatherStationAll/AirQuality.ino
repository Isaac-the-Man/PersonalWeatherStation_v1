
 
int measurePin = 3;
int ledPower = 7;
 
int samplingTime = 280;
int deltaTime = 40;
int sleepTime = 9680;
 
float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;
 
//void setup(){
//  Serial.begin(9600);
//  initAQ();
//}
// 
//void loop(){
//  double readings[1];
//  getAQValues(readings);
// 
//  Serial.print(" - Dust Density: ");
//  Serial.println(readings[0]);
// 
//  delay(1000);
//}
//
// initialize the particle sensor
void initAQ() {
  pinMode(ledPower,OUTPUT);
}

// get values from airquality sensor
// readings: particle_Density
void getAQValues(double* output){
  digitalWrite(ledPower,LOW); // power on the LED
  delayMicroseconds(samplingTime);
 
  voMeasured = analogRead(measurePin); // read the dust value
 
  delayMicroseconds(deltaTime);
  digitalWrite(ledPower,HIGH); // turn the LED off
  delayMicroseconds(sleepTime);
 
  calcVoltage = voMeasured * (5.0 / 1024);
 
  dustDensity = 0.17 * calcVoltage - 0.1;
 
  output[0] = dustDensity;
}
