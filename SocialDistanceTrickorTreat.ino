// Created By: Ellen Wang
// Date: October 26th, 2020
// Social Distance Trick-or-Treat

//includes stpper library
#include <Stepper.h>

//Sensor's output and input pin number on the arduino 
const int sensorPin = 7;
const int echoPin = 6;

//constant number of steps per revolution (200 steps = 360deg)
const int stepsPerRev = 200;
int motorSpeed = 60;

//the stepper library is initialized on pins 8,10,9,11
Stepper stepperMotor(stepsPerRev, 8,9,10,11);

void setup() {
  
  //sets the stepper speed
  stepperMotor.setSpeed(motorSpeed);
  
  //initalize serical communication
  Serial.begin(9600);
}

void loop() {
  //sets the pins as input and output respectively 
  pinMode(echoPin, INPUT);
  pinMode(sensorPin, OUTPUT);
  
  //variable for the distance of the object from the sensor and the duration of the ping
  long distance, duration;

  delay(1000);
  
  //the LOW pulse(0v) is given before to ensure a clean HIGH pulse
  digitalWrite(sensorPin, LOW);
  delayMicroseconds(20);

  //the sensor is triggered by a HIGH pulse(5v) for 5 microseconds
  digitalWrite(sensorPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorPin, LOW);

  //recieve the signal from ping and store it in duration
  duration = pulseIn(echoPin, HIGH);

  //calculates the distance 
  distance = (duration/2/29.1);

  //to check if the sensor is working correctly 
  Serial.print("Distance: ");
  Serial.println(distance);
  
  if(distance > 10 && distance < 100){
          stepperMotor.step(stepsPerRev);
          delay(2000);
          }
  /*else{
    
    }*/

  //2 sec delay
  delay(2000);
}
