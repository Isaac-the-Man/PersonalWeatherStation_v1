

//Hardware pin definitions
int UVOUT = A1; //Output from the sensor
int REF_3V3 = A0; //3.3V power on the Arduino board

//void setup()
//{
//  Serial.begin(9600);
//  initUV();
//}
//
//void loop()
//{
//  double values[1];
//  getUVValues(values);
//  
//  Serial.print(" / UV Intensity (mW/cm^2): ");
//  Serial.print(values[0]);
//  Serial.println();
//
//  delay(100);
//}

//Takes an average of readings on a given pin
//Returns the average
int averageAnalogRead(int pinToRead)
{
  byte numberOfReadings = 8;
  unsigned int runningValue = 0; 

  for(int x = 0 ; x < numberOfReadings ; x++)
    runningValue += analogRead(pinToRead);
  runningValue /= numberOfReadings;

  return(runningValue);  
}

//The Arduino Map function but for floats
//From: http://forum.arduino.cc/index.php?topic=3922.0
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

// initialize sensor
void initUV() {
  pinMode(UVOUT, INPUT);
  pinMode(REF_3V3, INPUT);
}

// get readings from sensor
// readings: UV_intensity
void getUVValues(double* output){
  int uvLevel = averageAnalogRead(UVOUT);
  int refLevel = averageAnalogRead(REF_3V3);

  //Use the 3.3V power pin as a reference to get a very accurate output value from sensor
  float outputVoltage = 3.3 / refLevel * uvLevel;

  float uvIntensity = mapfloat(outputVoltage, 0.99, 2.8, 0.0, 15.0); //Convert the voltage to a UV intensity levelx

  if (uvIntensity < 0) {
    output[0] = 0; // minimum output
  }else {
    output[0] = uvIntensity;
  }
}
