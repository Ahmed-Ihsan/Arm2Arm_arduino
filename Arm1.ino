#include <Servo.h>

Servo servo1; 
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

const int ir1 = 12;
const int ir2 = 4;

void setup() {
  servo1.attach(9);  
  servo2.attach(10);
  servo3.attach(11);
  servo4.attach(5);
  servo5.attach(6);
  servo6.attach(3);

  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);

  servo3.write(0);
  servo1.write(50);
  servo4.write(50);
  servo5.write(50);
  Serial.begin(9600);
}

void loop() {
  int a = digitalRead(ir2);
  int b = digitalRead(ir1);
  Serial.print(a);
  Serial.print("  ");
  Serial.println(b);
  if(b){
    servo6.write(100);
  }else{
    servo6.write(100);
    delay(900);
    servo6.write(90);
    delay(2000);
  }
  if(a){
    
  }else{
    servo6.write(90);
    arm();
  }
  
}


void arm(){
   
  for (int i = 77 ; i > 10; i--) {
    servo2.write(i);
    delay(30);
  }
  delay(1000);

  for (int i = 50; i < 95; i++) {
    servo4.write(i);
    delay(30);
  }

  delay(1000);

  for (int i = 10 ; i < 77; i++) {
    servo2.write(i);
    delay(10);
  }
  delay(1000);
  for (int i = 0 ; i < 179; i++) {
    servo3.write(i);
    delay(17);
  }
  delay(1000);

  for (int i = 95; i > 50; i--) {
    servo4.write(i);
    delay(30);
  }
  delay(1000);
    for(int i = 179 ; i > 0;i--){
    servo3.write(i);
    delay(17);
   }
}
