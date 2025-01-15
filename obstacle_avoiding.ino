#include <Servo.h>

#define trigPin A3
#define echoPin A2

// L298N Motor Driver Pins
#define IN1 9
#define IN2 8
#define IN3 7
#define IN4 6
#define ENA 10
#define ENB 5

Servo servo;
int distance;
int rightDistance = 0;
int leftDistance = 0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Motor driver pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Enable motors
  analogWrite(ENA, 255); // Full speed for Motor A
  analogWrite(ENB, 255); // Full speed for Motor B
  
  servo.attach(A5); // Attach servo to pin A5
  servo.write(90);  // Initial servo position (forward-facing)
  
  Serial.begin(9600);
}

int measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2; // Convert to cm
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void loop() {
  // Stop and scan the environment
  stopMotors();
  
  // Scan right side
  servo.write(135); // Look to the right
  delay(500);
  rightDistance = measureDistance();
  
  // Scan left side
  servo.write(45); // Look to the left
  delay(500);
  leftDistance = measureDistance();
  
  // Log distances
  Serial.print("Right Distance: ");
  Serial.println(rightDistance);
  Serial.print("Left Distance: ");
  Serial.println(leftDistance);
  
  // Decide direction
  if (rightDistance > leftDistance) {
    Serial.println("Turning Right...");
    turnRight();
    delay(1000); // Adjust delay based on your robot
  } else {
    Serial.println("Turning Left...");
    turnLeft();
    delay(1000); // Adjust delay based on your robot
  }
  
  // Move forward after turning
  servo.write(90); // Reset servo to forward-facing position
  moveForward();
  delay(100);
}
