[obstacle_avoiding_robot (code).cpp](https://github.com/user-attachments/files/22092758/obstacle_avoiding_robot.code.cpp)
# 🤖 Obstacle Avoiding Robot (Arduino Project)

An autonomous robot that detects and avoids obstacles using **Arduino Uno**, **Ultrasonic Sensor (HC-SR04)**, **Servo Motor**, and **L298N Motor Driver**.  
The robot continuously scans its surroundings and makes intelligent decisions to move forward, turn left, or turn right.
<img width="3750" height="1959" alt="Obstacle Avoiding Robot" src="https://github.com/user-attachments/assets/6cc825d8-6b32-4dc8-924c-c3e7cd9c5679" />

---

## ✨ Features
- 🚗 Moves autonomously without human control  
- 📡 Detects obstacles using ultrasonic sensor  
- 🔄 Servo motor rotates sensor to check left & right  
- ⚡ Powered by 12V battery  
- 🛠️ Built with Arduino + L298N motor driver  

---

## 🛠️ Components Used
- Arduino Uno (x1)  
- L298N Motor Driver (x1)  
- DC Gear Motors (x2)  
- Ultrasonic Sensor HC-SR04 (x1)  
- Servo Motor SG90 (x1)  
- 12V Battery (x1)  
- Wheels + Chassis  

---

## ⚡ Circuit Documentation
📄  [Circuit_Documentation.pdf](https://github.com/user-attachments/files/22092750/Circuit_Documentation.pdf)

📷 <img width="730" height="326" alt="Circuit Diagram" src="https://github.com/user-attachments/assets/e7f97d2e-cb5a-4cf0-930a-3da6235cf9ce" />


---

## 🖥️ Arduino Code
The complete Arduino sketch is available here:  
👉 [Uploadi#include <Servo.h>
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
ng obstacle_avoiding_robot (code).cpp…]()


---

## 🚀 How It Works
1. The ultrasonic sensor measures the distance in front.  
2. If the path is clear → Robot moves **forward**.  
3. If an obstacle is detected (≤ 15 cm):  
   - Robot stops → moves **backward** → stops.  
   - Sensor looks **right** and **left**.  
   - Robot turns toward the side with more space.  
   - Continues moving forward.  



---

---

## 📦 Repository Structure
