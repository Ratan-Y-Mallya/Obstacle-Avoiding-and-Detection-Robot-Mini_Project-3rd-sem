# Obstacle Avoidance and Detection Robot 

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Circuit Diagram](#circuit-diagram)
- [Working Principle](#working-principle)
- [How to Build](#how-to-build)
- [Demonstration](#demonstration)
- [Future Enhancements](#future-enhancements)

---

## Introduction
This project involves the design and implementation of an **Obstacle Avoidance and Detection Robot** using an Arduino microcontroller. The robot detects obstacles in its path using ultrasonic sensors and avoids collisions by dynamically altering its direction using servo motors and wheels.

The primary goal of this project is to demonstrate how Arduino can be used for robotics applications, specifically for autonomous navigation.

---

## Features
- **Obstacle Detection:** Uses ultrasonic sensors to detect objects in front of the robot.
- **Autonomous Navigation:** The robot changes its path to avoid obstacles.
- **Real-Time Processing:** The robot reacts to its environment in real-time.
- **Simple Design:** Easy to assemble with basic components.

---

## Hardware Requirements
To build this robot, you’ll need the following components:
1. **Arduino Uno** or any compatible microcontroller board.
2. **Ultrasonic Sensors (HC-SR04)** for obstacle detection.
3. **Servo Motors** to rotate the ultrasonic sensors.
4. **DC Motors** with motor driver (e.g., L298N) for wheel control.
5. **Wheels** for robot movement.
6. **Chassis** for mounting components.
7. **Battery Pack** (e.g., 6V or 9V) to power the robot.
8. **Jumper Wires** for connections.
9. **Breadboard** (optional) for prototyping.

---

## Software Requirements
1. **Arduino IDE** (latest version recommended).
2. Required Arduino libraries:
   - Servo Library (built-in with Arduino IDE).
   - NewPing Library (optional for ultrasonic sensors).

---

## Circuit Diagram
![Obstacle-Avoiding-Robot-using-Arduino-Circuit-1](https://github.com/user-attachments/assets/d497d5bd-3f16-4946-ab22-9a8a1fadba7c)

![98f14108-5600-4588-b1eb-f7b582aad33e](https://github.com/user-attachments/assets/aaa517e7-ce86-4743-acee-d35e8be68352)
![f2949e7c-9f0d-4ef3-8af6-8502990d10e6](https://github.com/user-attachments/assets/eb68f1e0-f4d8-447a-a8cb-f6a5bff7323e)

---

## Working Principle
1. The ultrasonic sensor measures the distance to the nearest object.
2. The Arduino processes the sensor data and determines whether the robot should stop or change direction.
3. If an obstacle is detected within a predefined distance:
   - The robot pauses.
   - The servo motor rotates the ultrasonic sensor to scan for a clear path.
   - The robot adjusts its direction based on the scan results.
4. The robot resumes movement once a clear path is identified.

## How to Build
1. Assemble the Robot:
   - Mount the motors and wheels on the chassis.
   - Secure the Arduino board to the chassis.
   - Attach the ultrasonic sensor to a servo motor for rotational movement.
2. Connect Components:
   - Use the circuit diagram to connect the components to the Arduino.
3. Upload the Code:
   - Connect the Arduino to your computer via USB.
   - Open the Arduino IDE and upload the provided code.
4. Power the Robot:
   - Connect the battery pack to power the Arduino and motors.
  
##  Demonstration

---
## Future Enhancements
   - Add more ultrasonic sensors for 360-degree obstacle detection.
   - Integrate infrared sensors for enhanced precision.
   - Implement machine learning for advanced obstacle avoidance.
   - Add a camera module for vision-based navigation.


