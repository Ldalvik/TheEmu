#include <Servo.h>

Servo z_axis; //SPIN
Servo y_axis; //ARM BOTTOM
Servo x_axis; //ARM TOP
Servo clamp_axis; //CLAMP

int arm_z = A0;
int arm_y = A1;
int arm_x = A2;
int arm_clamp = A3;
int motor_z = 3;
int motor_y = 4;
int motor_x = 5;
int motor_clamp = 6;

void setup() {
  Serial.begin(115200);
  pinMode(motor_z, OUTPUT);
  pinMode(motor_y, OUTPUT);
  pinMode(motor_x, OUTPUT);
  pinMode(motor_clamp, OUTPUT);

  z_axis.attach(motor_z);
  y_axis.attach(motor_y);
  x_axis.attach(motor_x);
  clamp_axis.attach(motor_clamp);
}

void loop() {
  int arm_y_pot = analogRead(arm_y);
  int arm_z_pot = analogRead(arm_z);
  int arm_x_pot = analogRead(arm_x);
  int arm_clamp_pot = analogRead(arm_clamp);
  
  Serial.print("Y: ");
  Serial.println(arm_y_pot);
  Serial.print("Z: ");
  Serial.println(arm_z_pot);
  Serial.print("X: ");
  Serial.println(arm_x_pot);
  Serial.print("CLAMP: ");
  Serial.println(arm_clamp_pot);

  int arm_y_val = map(arm_y_pot, 400, 850, 0, 180);
  int arm_z_val = map(arm_z_pot, 100, 800, 0, 180);
  int arm_x_val = map(arm_x_pot, 850, 1023, 0, 180);
  int arm_clamp_val = map(arm_clamp_pot, 0, 1023, 0, 180);

  yaxis(arm_y_val);
  zaxis(arm_z_val);
  xaxis(arm_x_val);
  clampaxis(arm_clamp_val);
}

void zaxis(int data) {
  z_axis.write(data);
  delay(10);
}

void yaxis(int data) {
  y_axis.write(data);
  delay(10);
}

void xaxis(int data) {
  x_axis.write(data);
  delay(10);
}

void clampaxis(int data) {
  clamp_axis.write(data);
  delay(10);
}
