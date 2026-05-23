#include <Servo.h>

Servo sg90;

int initial_position = 90;   // start at center

int LDR1 = A0;  
int LDR2 = A1;

int error = 100;   // threshold (important)
int servopin = 4;

void setup() {
  Serial.begin(9600);

  sg90.attach(servopin);

  pinMode(LDR1, INPUT);
  pinMode(LDR2, INPUT);

  sg90.write(initial_position);  // move to center
  delay(2000);
}

void loop() {
  int R1 = analogRead(LDR1);
  int R2 = analogRead(LDR2);

  Serial.print("LDR1: ");
  Serial.print(R1);
  Serial.print("   LDR2: ");
  Serial.println(R2);

  int diff = abs(R1 - R2);

if (diff > error) {
  if (R1 > R2) {
    // Upper LDR brighter → go UP
    initial_position += 5;
  } else {
    // Lower LDR brighter → go DOWN
    initial_position -= 5;
  }
}

  // keep servo within limits
  initial_position = constrain(initial_position, 0, 180);

  sg90.write(initial_position);

  delay(200);
}