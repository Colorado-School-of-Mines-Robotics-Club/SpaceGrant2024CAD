#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servo = Adafruit_PWMServoDriver();

#define SERVOMIN  200 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  400 // This is the 'maximum' pulse length count (out of 4096)
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

// our servo # counter
uint8_t servonum = 0;
uint8_t servototal = 12;

int default_delay = 1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  delay(default_delay*2);

  servo.begin();
  servo.setOscillatorFrequency(27000000);
  servo.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  for (uint8_t servocurr = servonum; servocurr <= servototal; servocurr++) {
    Serial.print("Resetting Servo ");
    Serial.println(servocurr);
    servo.setPWM(servocurr, 0, (SERVOMAX - SERVOMIN) / 2 + SERVOMIN);
    delay(100);
    }

  Serial.println("Setup Complete");
  delay(default_delay*5);
  
}

void arm_place_f(int servo_num) {
  // pulselength = map(degrees, 0, 180, SERVOMIN, SERVOMAX);

  // Raise Vert
  Serial.print("Moving Servo ");
  Serial.println(servo_num + 1);
  servo.setPWM(servo_num + 1, 0, SERVOMAX);
  delay(default_delay);

  // Move Horz
  Serial.print("Moving Servo ");
  Serial.println(servo_num);
  if (servo_num > 5) {
    servo.setPWM(servo_num, 0, SERVOMIN);
  } else {
    servo.setPWM(servo_num, 0, SERVOMAX);
  }
  delay(default_delay);

  // Lower Vert
  Serial.print("Moving Servo ");
  Serial.println(servo_num + 1);
  servo.setPWM(servo_num + 1, 0, SERVOMIN);
  delay(default_delay);
  
}

void arm_place_b(int servo_num) {

  // Raise Vert
  Serial.print("Moving Servo ");
  Serial.println(servo_num + 1);
  servo.setPWM(servo_num + 1, 0, SERVOMAX);
  delay(default_delay);

  // Move Horz
  Serial.print("Moving Servo ");
  Serial.println(servo_num);
  if (servo_num < 5) {
    servo.setPWM(servo_num, 0, SERVOMAX);
  } else {
    servo.setPWM(servo_num, 0, SERVOMIN);
  }
  delay(default_delay);

  // Lower Vert
  Serial.print("Moving Servo ");
  Serial.println(servo_num + 1);
  servo.setPWM(servo_num + 1, 0, SERVOMIN);
  delay(default_delay);

}

void arm_shift_f(int servo_num) {
  // Move Horz
  Serial.print("Moving Servo ");
  Serial.println(servo_num);
  if (servo_num > 5) {
    servo.setPWM(servo_num, 0, SERVOMAX);
  } else {
    servo.setPWM(servo_num, 0, SERVOMIN);
  }
  delay(50);
}

void arm_shift_b(int servo_num) {
  // Move Horz
  Serial.print("Moving Servo ");
  Serial.println(servo_num);
  if (servo_num < 5) {
    servo.setPWM(servo_num, 0, SERVOMAX);
  } else {
    servo.setPWM(servo_num, 0, SERVOMIN);
  }
  delay(50);
}

void move_forward() {
  Serial.println("Moving Forward");
  arm_place_f(0);
  arm_place_f(6);
  arm_place_f(2);
  arm_place_f(8);
  arm_place_f(4);
  arm_place_f(10);

  arm_shift_f(0);
  arm_shift_f(2);
  arm_shift_f(4);
  arm_shift_f(6);
  arm_shift_f(8);
  arm_shift_f(10);
}

void move_backward() {
  Serial.println("Moving Backward");
  arm_place_b(10);
  arm_place_b(4);
  arm_place_b(8);
  arm_place_b(2);
  arm_place_b(6);
  arm_place_b(0);

  arm_shift_f(0);
  arm_shift_f(2);
  arm_shift_f(4);
  arm_shift_f(6);
  arm_shift_f(8);
  arm_shift_f(10);
}

void turn_left() {
  Serial.println("Turning Left");

  // Left Forward
  arm_place_f(0);
  arm_place_f(2);
  arm_place_f(4);

  // Right Backwards
  arm_place_b(10);
  arm_place_b(8);
  arm_place_b(6);

  // Rotate Body
  arm_shift_f(0);
  arm_shift_f(2);
  arm_shift_f(4);
  arm_shift_b(6);
  arm_shift_b(8);
  arm_shift_b(10);

}

void turn_right() {
  Serial.println("Turning Right");

  // Right Forward
  arm_place_f(6);
  arm_place_f(8);
  arm_place_f(10);

  // Left Backwards
  arm_place_b(4);
  arm_place_b(2);
  arm_place_b(0);

  // Rotate Body
  arm_shift_f(0);
  arm_shift_f(2);
  arm_shift_f(4);
  arm_shift_b(6);
  arm_shift_b(8);
  arm_shift_b(10);

}

void loop() {
  Serial.println("Navigate");
  int direction = 1; //navigate();

  switch (direction) {
    case 1:
      Serial.println("Move Forward");
      move_forward();
    case 0:
      Serial.println("Move Left");
      turn_left();
    case 2:
      Serial.println("Move Right");
      turn_right();
  } 
  delay(default_delay * 2);

}
