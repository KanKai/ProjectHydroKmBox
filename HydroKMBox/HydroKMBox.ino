// Create By JeerawatIT_Innivation
#include <Wire.h>
#include <LCD.h>  //เรียกใช้ไลบราลี่ LCD
#include <LiquidCrystal_I2C.h>  //เรียกใช้ไลบราลี่ LCD I2C
#define I2C_ADDR    0x27  //กำหนดแอดเดรดของ lcd
#define BACKLIGHT_PIN     3
#include "DHT.h"

#define DHTPIN 2  //กำหนดค่าคงที่ ให้กับตัวแปร DHTPIN ให้เท่ากับขาที่ 2 
#define DHTTYPE DHT11  //กำหนดค่าคงที่ของ DHT11 ไปเก็บไว้ในตัวแปร DHTTYPE
int ledPin = 13;  //กำหนดตัวแปรใหกับขาที่ 13 
int ledPin2 = 12;  //กำหนดตัวแปรใหกับขาที่ 12 
int ledPin3 = 11;  //กำหนดตัวแปรใหกับขาที่ 11
int ledPin4 = 10;  //กำหนดตัวแปรใหกับขาที่ 10
int ledPin5 = 9;  //กำหนดตัวแปรใหกับขาที่ 9
int Relay1 = 5;  //กำหนดตัวแปรใหกับขาที่ 5
int Relay2 = 6;  //กำหนดตัวแปรใหกับขาที่ 6
int Relay3 = 7;  //กำหนดตัวแปรใหกับขาที่ 7
//int StatusController = 8;
LiquidCrystal_I2C lcd(I2C_ADDR,2,1,0,4,5,6,7); //กำหนดแอดเดรด

DHT dht (DHTPIN, DHTTYPE);
void setup()
{
  Serial.begin(9600);
  //Serial.println();
  Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)");
  lcd.begin (16,2);  //กำหนดว่าเป็น lcd แบบไหน ซึ่งแบบที่ใช้ก็คือ 16x2 
  // Switch on the backlight
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);  // สั่งให้เปิดไฟหน้าจอ LCD
  lcd.clear();  // คำสั่งเคลียข้อความ
  lcd.setCursor(0,0);  // กำหนดแถวที่จะแสดงข้อความเป็นแถวที่ 1 
  lcd.print("    Welcome.   ");  // ให้โชว์ข้อความ
  lcd.setCursor(0,2);  // กำหนดแถวที่จะแสดงข้อความเป็นแถวที่ 2
  lcd.print(" Go To Mushroom  ");
  delay(1000);  // หน่วงเวลา 1 วินาที
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("  Loading.      ");
  delay(500);
  lcd.setCursor(0,0);
  lcd.print("  Loading..     ");
  delay(500);
  lcd.setCursor(0,0);
  lcd.print("  Loading...    ");
  delay(2000);
  lcd.setCursor(0,2);
  lcd.print("Temp Monitoring...");
  
  
  delay(2000); // wait at least 2 seconds
  pinMode(ledPin, OUTPUT);  // กำหนดให้ทำหน้าที่เป็น OUTPUT
  pinMode(ledPin2, OUTPUT); 
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);  
  pinMode(ledPin5, OUTPUT);
  pinMode(Relay1, OUTPUT);  
  pinMode(Relay2, OUTPUT);
  pinMode(Relay3, OUTPUT);
  //pinMode(StatusController, OUTPUT);
  digitalWrite(Relay1, HIGH);  // แสดงสถานะว่าพร้อมใช้งาน
  digitalWrite(Relay2, HIGH);
  digitalWrite(Relay3, HIGH);
}

void loop()
{
  //digitalWrite(StatusController, HIGH);
  float humidity = dht.readHumidity(); // ดึงค่าความชื้น
  float temperature = dht.readTemperature(); // ดึงค่าอุณหภูมิ
  
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT");  // ถ้าอุณหภูมิกับความชื่นเท่ากันจะแสดงข้อความ
    
  } else {
    Serial.print("Humidity: ");  // แสดงข้อความผ่านหน้า SerialPort
    Serial.print(humidity);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" *C ");
    

    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Humidity: ");  // แสดงข้อความบนจอ LCD
    lcd.print(humidity);
    lcd.print("%");
    //lcd.print("%\t");
    lcd.setCursor(0,1);
    lcd.print("Temperature:"); 
    lcd.print(temperature);
    lcd.print("C");
    delay(1000); // wait at least 2 seconds


  }
  if(temperature==humidity){
    Serial.println("System Fail");
    digitalWrite(ledPin, LOW);
  }else
  if(temperature>34){
    Serial.println("Hot Over");  // ถ้าอุณหภูมิเกิน 34
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("  < Hot Over >");  // แสดงข้อความ hot Over
    //lcd.print("%\t");
    lcd.setCursor(0,1);
    lcd.print("");
    lcd.print(temperature,1);
    //lcd.print("*C || ");
    lcd.print(" C | ");
    lcd.print(humidity,1);
    lcd.print(" % ");
    digitalWrite(ledPin2, HIGH);  // สั่งเปิดไฟสถานะอุปกรณ์ตัวที่ 1 
    digitalWrite(Relay1, LOW);  // สั่งเปิด relay เพื่อให้อุปกรณ์ทำงาน
    delay(60000);
  }else  // ถ้าไม่ใช่ ปิดให้หมด
  {
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(Relay1, HIGH);
  }
  if(humidity>80){
    Serial.println("Wet");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("  <<< Wet. >>>");
    //lcd.print("%\t");
    lcd.setCursor(0,1);
    lcd.print("");
    lcd.print(temperature,1);
    //lcd.print("*C || ");
    lcd.print(" C | ");
    lcd.print(humidity,1);
    lcd.print(" % ");
    digitalWrite(ledPin3, HIGH);
    digitalWrite(Relay2, LOW);
    delay(60000);
  }else
  {
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin3, LOW);
    digitalWrite(Relay2, HIGH);
  }
  if(temperature<26){
    Serial.println("Cold");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("  <<< Cold >>>");
    //lcd.print("%\t");
    lcd.setCursor(0,1);
    lcd.print("");
    lcd.print(temperature,1);
    //lcd.print("*C || ");
    lcd.print(" C | ");
    lcd.print(humidity,1);
    lcd.print(" % ");
    digitalWrite(ledPin4, HIGH);
    digitalWrite(Relay3, LOW);
    delay(60000);
  }else
  {
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin4, LOW);
    digitalWrite(Relay3, HIGH);
  }
  if(humidity<30){
    Serial.println("Dry");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("  <<< Dry. >>>");
    //lcd.print("%\t");
    lcd.setCursor(0,1);
    lcd.print("");
    lcd.print(temperature,1);
    //lcd.print("*C || ");
    lcd.print(" C | ");
    lcd.print(humidity,1);
    lcd.print(" % ");
    digitalWrite(ledPin5, HIGH);
    digitalWrite(Relay1, LOW);
    delay(60000);
  }else
  {
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin5, LOW);
    digitalWrite(Relay1, HIGH);
  }
}
