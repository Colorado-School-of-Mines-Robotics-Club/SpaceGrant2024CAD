#include <Servo.h>

int SP_1V = 9;
int SP_1H = 9;
int SP_2V = 9;
int SP_2H = 9;
int SP_3V = 9;
int SP_3H = 9;
int SP_4V = 9;
int SP_4H = 9;
int SP_5V = 9;
int SP_5H = 9;
int SP_6V = 9;
int SP_6H = 9;
int SPo_Default = 90;
int SPo_min = 30;
int SPo_max = 150;
int delay_def = 500;

Servo SER1V;
Servo SER1H;
Servo SER2V;
Servo SER2H;
Servo SER3V;
Servo SER3H;
Servo SER4V;
Servo SER4H;
Servo SER5V;
Servo SER5H;
Servo SER6V;
Servo SER6H;

void setup() {
  Serial.begin(9600);
  SER1V.attach(SP_1V);
  SER1H.attach(SP_1H);
  SER2V.attach(SP_2V);
  SER2H.attach(SP_2H);
  SER3V.attach(SP_3V);
  SER3H.attach(SP_3H);
  SER4V.attach(SP_4V);
  SER4H.attach(SP_4H);
  SER5V.attach(SP_5V);
  SER5H.attach(SP_5H);
  SER6V.attach(SP_6V);
  SER6H.attach(SP_6H);

  SER1V.write(SPo_Default);
  SER1H.write(SPo_Default);
  SER2V.write(SPo_Default);
  SER2H.write(SPo_Default);
  SER3V.write(SPo_Default);
  SER3H.write(SPo_Default);
  SER4V.write(SPo_Default);
  SER4H.write(SPo_Default);
  SER5V.write(SPo_Default);
  SER5H.write(SPo_Default);
  SER6V.write(SPo_Default);
  SER6H.write(SPo_Default);

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

void move_forward() {
  SER1_forward();
  delayMicroseconds(delay_def);
  SER2_forward();
  delayMicroseconds(delay_def);
  SER3_forward();
  delayMicroseconds(delay_def);
  SER4_forward();
  delayMicroseconds(delay_def);
  SER5_forward();
  delayMicroseconds(delay_def);
  SER6_forward();
  delayMicroseconds(delay_def);
  CHASSIS_forward();
  delayMicroseconds(delay_def);
}

void move_backward() {

}

void move_left() {

}

void move_right() {

}

void SER1_forward() {
  SER1V.write(SPo_max);
  delayMicroseconds(delay_def);
  SER1H.write(SPo_max);
  delayMicroseconds(delay_def);
  SER1V.write(SPo_min);
}

void SER2_forward() {
  SER2V.write(SPo_max);
  delayMicroseconds(delay_def);
  SER2H.write(SPo_max);
  delayMicroseconds(delay_def);
  SER2V.write(SPo_min);
}

void SER3_forward() {
  SER3V.write(SPo_max);
  delayMicroseconds(delay_def);
  SER3H.write(SPo_max);
  delayMicroseconds(delay_def);
  SER3V.write(SPo_min);
}

void SER4_forward() {
  SER4V.write(SPo_max);
  delayMicroseconds(500);
  SER4H.write(SPo_max);
  delayMicroseconds(500);
  SER4V.write(SPo_min);
}

void SER5_forward() {
  SER5V.write(SPo_max);
  delayMicroseconds(500);
  SER5H.write(SPo_max);
  delayMicroseconds(500);
  SER5V.write(SPo_min);
}

void SER6_forward() {
  SER6V.write(SPo_max);
  delayMicroseconds(500);
  SER6H.write(SPo_max);
  delayMicroseconds(500);
  SER6V.write(SPo_min);
}

void CHASSIS_forward() {
  SER1H.write(SPo_min);
  SER2H.write(SPo_min);
  SER3H.write(SPo_min);
  SER4H.write(SPo_min);
  SER5H.write(SPo_min);
  SER6H.write(SPo_min);
}