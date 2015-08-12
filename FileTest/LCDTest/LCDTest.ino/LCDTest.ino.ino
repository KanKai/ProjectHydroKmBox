#include<Wire.h>
#include<LiquidCrystal_I2C.h>

//#define I2C_ADDR 0x27 // กำหนดตำแหน่ง Address ของ I2C
//#define I2C_ADDR 0x3F // ในบางกรณีที่ Address ของ I2C เป็น 0x3F
#define BACKLIGHT_PIN 3 

LiquidCrystal_I2C lcd(0x27,16,2); // กำหนด Address ให้กับ LCD

void setup() {
  // lcd.begin (20,4);
  lcd.begin ();

  /* byte customChar0[8]={
     0b00000,
     0b00000,
     0b00000,
     0b11111,
     0b11111,
     0b11111,
     0b11111,
     0b00000
   };
   byte customChar1[8]={
    0b11100,
    0b11100,
    0b11100,
    0b11111,
    0b11111,
    0b11111,
    0b11110,
    0b00000
    };
    lcd.createChar(1,customChar0);
    lcd.createChar(2,customChar1);*/
    // Switch on the backlight
    //lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
    //lcd.setBacklight(HIGH);
    //lcd.home(); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

    //lcd.setCursor(1,0); // ไปตัวอักษรที่ 1 แถวที่ 1 
    //lcd.print("Welcome All");

    //lcd.setCursor(3,1); // ไปที่ตัวอักษรที่ 5 แถวที่ 2
    //lcd.print("ArduinoAll");
    //lcd.write(1);
    //lcd.write(2);
    
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print("Hydro KM Box");
  lcd.setCursor(0,1);
  lcd.print("By KiceMenIT ^_^");
  //delay(5000);
  //lcd.setBacklight(LOW);
  //delay(1000);
}
