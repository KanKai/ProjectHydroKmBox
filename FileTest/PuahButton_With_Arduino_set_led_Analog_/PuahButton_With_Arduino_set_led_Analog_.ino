  
int analogPin = A0;   // กำหนดตัวแปร analogPin เชื่อมกับขา A0
int analogPin1 = A1;
int analogPin2 = A2;
int buttonPin = 2;

int buttonState = 0;  // กำหนดให้ค่าเริ่มต้นเป็น 0 ถ้ากดปุ่มจะกลายเป็น 1 = HIGH

       // variable to store the read value
void setup()

{

  pinMode(analogPin, OUTPUT);   // ตั้ง analogPin เป็นขาออก
  pinMode(analogPin1, OUTPUT);
  pinMode(analogPin2, OUTPUT);
  pinMode(buttonPin, INPUT); // ตั้ง buttonPin เป็นรับค่า
 
}

void loop()
{ 

  buttonState = digitalRead(buttonPin); // กำหนดให้อ่านค่าจาก buttonPin แล้วมาเก็บไว้ใน ตัวแปร buttonState
 
  
  if(buttonState == HIGH){ 
    
  analogWrite(analogPin, 255);  // สั่งให้ Led ทำงาน กรณีเป็น analog จะต้องใช้ 0 = ปิด , 1 = เปิด ถ้าเป็น digatal ต้องใช้ LOW,HIGH
  
  }
  else{
    analogWrite(analogPin, 0);
    } 
  
  }
  

