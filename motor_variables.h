#include<Arduino.h>

#define pwm 255
#define pwm2 130

// init the motor with the pin numbers
// Left motor
#define en1   40
#define in1   44
#define in2   42

// Right motor
#define en2   50
#define in3   48
#define in4   46

// define variables of ultra sonic
#define trigger 7
#define echo 6

// init variable to store ir readings
int Far_Right,Right,Middle,Left,Far_Left,Back_left,Back_right,middle_right,middle_left;

void Read_InfraRed()
{
    /*Readings interpretation
    * 0 ->  Not on line
    * 1 ->  On line
    */
  middle_left = digitalRead(2);
  middle_right = digitalRead(3);

  Back_left = digitalRead(5);
  Back_right = digitalRead(4);
  
  Far_Right = digitalRead(A0);
  Right = digitalRead(A1);
  Left = digitalRead(A2); 
  Far_Left =digitalRead(A3);
}
