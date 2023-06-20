#include<Arduino.h>

int speed = 180;
#define pwm 200
#define pwm2 130

// init the motor with the pin numbers
// Left motor
#define en1  46
#define in1  42 
#define in2  40

// Right motor
#define en2  44
#define in3  50
#define in4  48


int Far_Right,Right,Middle,Left,Far_Left,Back_left,Back_right;

// define movement functions
void Read_InfraRed()
{
    /*Readings interpretation
    * 0 ->  Not on line
    * 1 ->  On line
    */
  // Back_Fin = digitalRead(7);
  Back_left = digitalRead(7);
  Back_right = digitalRead(12);
  Far_Right = digitalRead(A0);
  Right = digitalRead(A1);
  Left = digitalRead(A2); 
  Far_Left =digitalRead(A3);

  // Serial.print(Far_Right);
  // Serial.print(Right);
// //   Serial.print(Middle);
  // Serial.println(Left);
  Serial.println(Far_Left);
}
