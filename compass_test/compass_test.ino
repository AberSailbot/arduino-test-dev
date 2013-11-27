#include <Wire.h> 

byte bearing(){
  #define ADDRESS 0x60 // CMPS10 I2C address
  Wire.beginTransmission(ADDRESS);
  Wire.write(1);
  Wire.endTransmission();
  Wire.requestFrom(ADDRESS, 1);
  return Wire.read();
}

void setup(){
  Serial.begin(9600);                  
  Wire.begin();
}

void loop(){
  Serial.println(bearing(), DEC);
  delay(100);
}

