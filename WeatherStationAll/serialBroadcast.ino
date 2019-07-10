//void setup() {
//  // put your setup code here, to run once:
//  Serial.begin(9600);
//  initDHT();
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//  double fltarr[7];
//  readSensor(fltarr);
//
//  // read from DHT
////  double dhtValues[2];
////  getDHTValues(dhtValues);
//
//  char finalStr[50];
//
//  formatReadings(fltarr, finalStr);
////  formatReadings(dhtValues, finalStr);
//  Serial.write(finalStr);
//
//  delay(1000);
//}

void readSensor(double* output) {
  double container[7];
  for (int i = 0; i < 7; ++i) {
    container[i] = double(i);
  }
  for (int i = 0; i < 7; ++i) {
    output[i] = container[i];
  }
}

void flt2Str(double num, char* fltstr) {
  char strBuff[16];
  char strTemp[10];
  dtostrf(num, 4, 5, strTemp);
  sprintf(strBuff, "%s:", strTemp);

  fltstr = strBuff;
}

void formatReadings(double values[], char* outStr) {
  char formatBuff[50];
//  Serial.println(sizeof(values));
  strcpy(formatBuff, "");
  for (int i = 0; i < 7; ++i) {
    char valStr[16];
    flt2Str(values[i], valStr);
    strcat(formatBuff, valStr);
  }
  strcat(formatBuff, "]");

  outStr = formatBuff;
}
