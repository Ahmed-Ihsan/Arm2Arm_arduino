#include <ESP32Servo.h>
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

// Bluetooth Serial Object (Handle)
BluetoothSerial SerialBT;

#define SERVO_PIN 13 // ESP32 pin GIOP26 connected to servo motor

Servo servoMotor;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); 
  servoMotor.attach(SERVO_PIN);  // attaches the servo on ESP32 pin
  servoMotor.write(90);
}

void loop() {

  bluetooth();
  

}

void event(char x) {
  Serial.println(x);
  if (x == '1') {
    AC1();
  }
  else if (x == '2') {
    AC2();
  }
  else if (x == '0'){
    servoMotor.write(90);
  }

}

void bluetooth() {
  char incoming;
  while (SerialBT.available()) {
    incoming = SerialBT.read();
    Serial.println(incoming);
    event(incoming);
  }
  
}

void AC1() {
  move1();
  delay(2000);
  servoMotor.write(90);
}


void AC2() {
  move2();
  delay(2000);
  servoMotor.write(90);
}



void move1() {
  // rotates from 90 degrees to 180 degrees
  for (int pos = 90; pos <= 180; pos += 1) {
    // in steps of 1 degree
    servoMotor.write(pos);
    delay(20); // waits 15ms to reach the position
  }
  // rotates from 90 degrees to 0 degrees
  for (int pos = 180; pos >= 90; pos -= 1) {
    servoMotor.write(pos);
    delay(20); // waits 15ms to reach the position
  }
}

void move2() {
  // rotates from 90 degrees to 0 degrees
  for (int pos = 90; pos >= 0; pos -= 1) {
    servoMotor.write(pos);
    delay(20); // waits 15ms to reach the position
  }
  // rotates from 90 degrees to 180 degrees
  for (int pos = 0; pos <= 90; pos += 1) {
    // in steps of 1 degree
    servoMotor.write(pos);
    delay(20); // waits 15ms to reach the position
  }
}
