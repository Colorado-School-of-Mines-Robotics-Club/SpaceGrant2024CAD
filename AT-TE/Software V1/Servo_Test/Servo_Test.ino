#include <Servo.h>

int servo_pin = 9;
int servo_position_deg = 90;

Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(servo_pin);

  Serial.println("Setup Complete!");
}

void loop() {

  // Write Servo Position
  Serial.print("Servo Position: ");
  Serial.print(servo_position_deg);
  Serial.println("deg");
  servo.write(servo_position_deg);
  
  delay(1000);

  // Update Servo Position
  servo_position_deg += 0;
  if (servo_position_deg > 180) {
    servo_position_deg = 0;
  }
}