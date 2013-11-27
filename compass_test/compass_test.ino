#include <Wire.h> 

byte read_i2c(int address, int _register) {
  Wire.beginTransmission(address);
  Wire.write(_register);
  Wire.endTransmission();
  Wire.requestFrom(address, 1);
  return Wire.read();
}

byte bearing(){
  int compass_address = 0x60; // CMPS10 I2C address
  int bearing_register = 1; // register containing the bearing 0-255
  return read_i2c(compass_address, bearing_register);
}

void setup(){
  Serial.begin(9600);                  
  Wire.begin();
}

void loop(){
  Serial.println(bearing(), DEC);
  delay(100);
}

