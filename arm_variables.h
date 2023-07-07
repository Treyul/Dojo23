#include <Arduino.h>
#include<math.h>
#include<stdio.h>
#include <Servo.h>
#include <Stepper.h>

// rest angles for both joints
#define REST 90


// defination of pins
#define LEFTCLAW A4
#define RIGHTCLAW A5
#define WRIST A6
#define ELBOW A7
#define SHOULDER A8

// define stepper pins
#define Stepper_En1 8
#define Stepper_In1 9
#define Stepper_In2 10
#define Stepper_In3 11
#define Stepper_In4 12
#define Stepper_En2 13

// arm dimensions
#define SHOULDER_LENGTH 210.0
#define ELBOW_LENGTH 172.0
#define MIN_X_VALUE 110 + 10
#define ARM_HEIGHT 180.0

//Error values 
#define SHOULDER_OFFEST 150
#define ELBOW_OFFSET 42

int trig2 = 36;
int echo2 = 37;

// init servos
// moves anticlockwise
Servo Shoulder; 

// moves clockwise
Servo Elbow; 

// closes at 120 degrees, increase in degrees is clockwise
Servo Left_Claw; 

// closes at 50 degrees, increase in degrees is clockwise
Servo Right_Claw; 

// axis rotation
Servo Wrist; 

// stepper
Stepper stepper(200, Stepper_In1, Stepper_In2, Stepper_In3, Stepper_In4);

int Previous_Coordinates[3] = {0,0,0};

