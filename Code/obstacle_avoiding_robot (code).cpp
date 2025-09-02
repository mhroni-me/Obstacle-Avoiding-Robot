#include <Servo.h>
#include <NewPing.h>

// Motor pin definitions
const int RightMotorBackward = 4;
const int RightMotorForward  = 5;
const int LeftMotorBackward  = 6;
const int LeftMotorForward   = 7;
const int enA = 8;
const int enB = 3;

// Ultrasonic sensor pins
#define trig_pin 11
#define echo_pin 12
#define maximum_distance 200

boolean goesForward = false;
int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance);
Servo servo_motor;

void setup() {
  pinMode(RightMotorBackward, OUTPUT);
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  servo_motor.attach(9);

  servo_motor.write(115); // center position
  delay(2000);

  // Initialize distance readings
  for (int i = 0; i < 4; i++) {
    distance = readPing();
    delay(100);
  }
}

void loop() {
  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (distance <= 15) {
    moveStop();
    delay(300);
    moveBackward();
    delay(300);
    moveStop();
    delay(300);

    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);

    if (distanceRight >= distanceLeft) {
      turnRight();
    } else {
      turnLeft();
    }
  } else {
    moveForward();
  }

  distance = readPing();
}

// Look right
int lookRight() {
  servo_motor.write(50);
  delay(300);
  int dist = readPing();
  delay(100);
  servo_motor.write(115);
  return dist;
}

// Look left
int lookLeft() {
  servo_motor.write(170);
  delay(300);
  int dist = readPing();
  delay(100);
  servo_motor.write(115);
  return dist;
}

// Read ultrasonic distance
int readPing() {
  delay(70);
  int cm = sonar.ping_cm();
  if (cm == 0) {
    cm = 250; // if no obstacle detected, set max distance
  }
  return cm;
}

// Stop motors
void moveStop() {
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
}

// Move forward
void moveForward() {
  if (!goesForward) {
    goesForward = true;
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW);
    digitalWrite(enA, HIGH);
    digitalWrite(enB, HIGH);
  }
}

// Move backward
void moveBackward() {
  goesForward = false;
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
}

// Turn right
void turnRight() {
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);

  delay(300);

  moveForward();
}

// Turn left
void turnLeft() {
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);

  delay(300);

  moveForward();
}
