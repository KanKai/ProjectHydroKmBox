#include "DHT.h"

#define DHTPIN 2     //กำหนดตัวแปรว่าจะต่อกับขาอะไร
#define DHTTYPE DHT11   // DHT 11 
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
// ต่อ pin1(+) เข้ากับ +5v โดยใช้ R  5k Pull up
// เชื่อมต่อขา 2(senser) เข้ากับ DHTPIN(จากโค๊ดคือขา 2)
// เชื่อมต่อขา 4(senser) เข้ากับ GND (ถ้าเซนเซอร์มี 4 ขา จะอยู่ขวาสุด)
// เชื่อมต่อตัวต้านทาน 5k จากขา 2 เข้ากับขา 1 ของเซ็นเซอร์

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  
  Serial.begin(9600); //กำหนดความเร็วในการแสดงผลข้อมูลในหน้า serialmonitor
  Serial.println("DHTxx test!"); //แสดงข้อความ
  dht.begin();
  
}

void loop() {
  
  delay(2000);   
  float h = dht.readHumidity(); //นำค่าที่ได้จาก dht.readHumidity มาเก็บไว้ในตัวแปร h  
  float t = dht.readTemperature(); //นำค่าที่ได้จาก dht.readTemperature มาเก็บไว้ในตัวแปร t   

  // ตรวจสอบว่าถ้ามีการอ่านค่าล้มเหลวให้แสดงข้อความบอก
  if (isnan(h) || isnan(t)) {
    
    Serial.println("Failed to read from DHT sensor!");   
     
  }else { 
    
    Serial.print("Humidity: ");
    Serial.print(h); // นำค่าที่อยู่ในตัวแปร h มาแสดง
    Serial.print(" %\t"); //แสดงข้อความ % แล้ว tab ไป 1 ครั้ง
    Serial.print("Temperature: ");
    Serial.print(t); // นำค่าที่อยู่ในตัวแปร t มาแสดง
    Serial.println(" *C ");  //แสดงอุณหภูมิเป็นองศาแล้วขึ้นบรรทัดใหม่
        
  }
}
