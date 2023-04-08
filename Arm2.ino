#include <Servo.h>

Servo servo1;  // create servo objects to control six servos
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

void setup() {
  servo1.attach(9);  // attaches the servos to their respective pins
  servo2.attach(10);
  servo3.attach(11);
  servo4.attach(5);
  servo5.attach(6);
  servo3.write(33);
  servo1.write(50);
  servo4.write(50);
  servo5.write(50);
}

void loop() {

  //
  // for(int i = 150 ; i > 32;i--){
  //  servo3.write(i);
  //  delay(17);
  // }

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
  for (int i = 33 ; i < 177; i++) {
    servo3.write(i);
    delay(17);
  }
  delay(1000);

  for (int i = 95; i > 50; i--) {
    servo4.write(i);
    delay(30);
  }
  delay(1000);
    for(int i = 177; i > 32;i--){
    servo3.write(i);
    delay(17);
   }

}
