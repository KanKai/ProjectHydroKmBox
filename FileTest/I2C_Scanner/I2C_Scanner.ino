#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  delay(300);
  Serial.println ();
  Serial.println ("I2C scanner. Scanning ...");
  byte count = 0;
  Wire.begin();
  for (byte i = 1; 1 < 120; i++)
  {
    Wire.beginTransmission (i);
    if (Wire.endTransmission () == 0)
      {
        Serial.print ("Found address: ");
        Serial.print (i, DEC);
        Serial.print (" (0x");
        Serial.print (i, HEX);
        Serial.println (")");
        count++;
        delay (i);
        } // end of good response
        } // end of for loop
        Serial.println ("Done.");
        Serial.print("Found ");
        Serial.print(count, DEC);
        Serial.println (" device(s).");
} // end loop setup

void loop() {
  // put your main code here, to run repeatedly:

}
