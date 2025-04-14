#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servo = Adafruit_PWMServoDriver();

#define SERVOMIN  200 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  400 // This is the 'maximum' pulse length count (out of 4096)
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

int default_delay = 750;
int servonum = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  delay(1000);

  servo.begin();
  servo.setOscillatorFrequency(27000000);
  servo.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  servo.setPWM(servonum, 0, (SERVOMAX - SERVOMIN) / 2 + SERVOMIN);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //servo.setPWM(servonum, 0, SERVOMIN);
  delay(default_delay);
  //servo.setPWM(servonum, 0, SERVOMAX);
  delay(default_delay);
}
