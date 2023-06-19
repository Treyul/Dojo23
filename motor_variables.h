#include<Arduino.h>

int speed = 180;
#define pwm 200
#define pwm2 130

// init the motor with the pin numbers
// Left motor
#define en1 8
#define in1 9
#define in2 10

// Right motor
#define en2 13 
#define in3 11
#define in4 12

// initialize variables to store the ir readings
/*  A5  Far_Left light purple
 *  A4      black -> green  purple
 *  A3
 *  A2
 *  A1  Far_Right
 */ 
int Far_Right,Right,Middle,Left,Far_Left,Back_Fin;

// define movement functions
void Read_InfraRed()
{
    /*Readings interpretation
    * 0 ->  Not on line
    * 1 ->  On line
    */
  Back_Fin = digitalRead(7);
  Far_Right = digitalRead(6);
  Right = digitalRead(5);
  Left = digitalRead(4); 
  Far_Left =digitalRead(9);

  Serial.print(Far_Right);
  Serial.print(Right);
// //   Serial.print(Middle);
  Serial.println(Left);
//   Serial.println(Far_Left);
}
