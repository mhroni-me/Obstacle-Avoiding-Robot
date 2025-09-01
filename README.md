
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
📄 [Circuit_Documentation.md](docs/Circuit_Documentation.md)  
📷 ![Circuit Diagram](docs/Wiring_Diagram.png)  

---

## 🖥️ Arduino Code
The complete Arduino sketch is available here:  
👉 [obstacle_avoiding_robot.ino](code/obstacle_avoiding_robot.ino)

---

## 🚀 How It Works
1. The ultrasonic sensor measures the distance in front.  
2. If the path is clear → Robot moves **forward**.  
3. If an obstacle is detected (≤ 15 cm):  
   - Robot stops → moves **backward** → stops.  
   - Sensor looks **right** and **left**.  
   - Robot turns toward the side with more space.  
   - Continues moving forward.  

📊 See [Flowchart.png](docs/Flowchart.png) for the logic flow.

---

---

## 📦 Repository Structure
