#include <Wire.h> 
#define ADDRESS 0x60 // CMPS10

void setup(){
  Serial.begin(9600);                  
  Wire.begin();
}

void loop(){
  byte bearing;
  
  Wire.beginTransmission(ADDRESS);
  Wire.write(1);
  Wire.endTransmission();
  Wire.requestFrom(ADDRESS, 1);
  bearing = Wire.read();
  
  Serial.println(bearing, DEC);
  delay(100);
}

