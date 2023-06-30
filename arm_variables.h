#include <Arduino.h>
#include<math.h>
#include<stdio.h>
#include <Servo.h>
#include <Stepper.h>

#define LEFT 1
#define RIGHT 2
#define FORWARD 3

// defination of pins
#define LEFTCLAW 30
#define RIGHTCLAW 28
#define WRIST 26
#define ELBOW 24
#define SHOULDER 22

// arm dimensions
#define SHOULDER_LENGTH 210
#define ELBOW_LENGTH 100

int trig2 = 36;
int echo2 = 37;

// init servos
Servo Shoulder; 
Servo Elbow; 
Servo Left_Claw; 
Servo Right_Claw; 
Servo Wrist; 

// stepper
Stepper stepper(200, 45, 47, 49, 51);


