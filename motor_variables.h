#include <AFMotor.h>
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
    /*
    * Readings interpretation
    * 0 ->  Not on line
    * 1 ->  On line
    */
//   Serial.println(digitalRead(8));
  Back_Fin = digitalRead(7);
  Far_Right = digitalRead(6);
  Right = digitalRead(5);
//   Middle = digitalRead(A3);
  Left = digitalRead(4); 
//   Far_Left =digitalRead(9); 
  Serial.print(Far_Right);
  Serial.print(Right);
// //   Serial.print(Middle);
  Serial.println(Left);
//   Serial.println(Far_Left);
}



void Stop_Motors()
{
    // Left_Motor.run(RELEASE);
    // Right_Motor.run(RELEASE);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}

void Move_Forward(int _pwm)
{
    // Left_Motor.setSpeed(speed);
    // Right_Motor.setSpeed(speed);
    // Left_Motor.run(FORWARD);
    // Right_Motor.run(FORWARD);
    analogWrite(en1, _pwm);
    analogWrite(en2, _pwm);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    Serial.println("Forward");
}

void reverse(int _pwm)
{
    analogWrite(en1, _pwm);
    analogWrite(en2, _pwm);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    // Left_Motor.setSpeed(speed);
    // Right_Motor.setSpeed(speed);
    // Left_Motor.run(BACKWARD);
    // Right_Motor.run(BACKWARD);
}

void Go_right(int _pwm)
{
    // Left_Motor.setSpeed(200);
    // Right_Motor.setSpeed(200);
    // Left_Motor.run(FORWARD);
    // Right_Motor.run(BACKWARD);
    analogWrite(en1, _pwm);
    analogWrite(en2, _pwm);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

void Go_left(int _pwm)
{
    // Left_Motor.setSpeed(200);
    // Right_Motor.setSpeed(200);
    // Left_Motor.run(BACKWARD);
    // Right_Motor.run(FORWARD);
    analogWrite(en1, _pwm);
    analogWrite(en2, _pwm);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

void Turn_Right()
{
    /*  Ensure that the last ir in that side has reached a line    */
    while ( Far_Right )
    {
        Go_right(pwm2);
        Read_InfraRed();
    }

    while ( !Back_Fin && !Far_Right )
    {
        Go_right(pwm2);
        Read_InfraRed();
        Serial.println("Turning.....");
        Serial.print("right is ");
        Serial.println(Far_Right?"on line":"Not in line");
        Serial.print("tail is ");
        Serial.println(Back_Fin?"on line":"Not in line");
        // Back_Fin = digitalRead(8);
    }
    
}

void Turn_left()
{
    while ( Far_Right )
    {
        Go_left(pwm2);
        Read_InfraRed();
    }
    
    // while ( !Far_Right )
    // {
    //     Go_left(200);
    //     Read_InfraRed();
    // }
    // Back_Fin = digitalRead(8);
    while (/* !Back_Fin &&*/ !Far_Right )
    {
        Go_left(pwm2);
        Read_InfraRed();
        Serial.println("Turning.....");
        Serial.print("right is ");
        Serial.println(Far_Right?"on line":"Not in line");
        Serial.print("tail is ");
        Serial.println(Back_Fin?"on line":"Not in line");
        // Back_Fin = digitalRead(8);
    }
    if ( Far_Right )
    {
        Serial.println("Reached end.....");
        while ( !Right )
        {
        Serial.println("readjustment....");
        Go_right(pwm2);
        Read_InfraRed();
        }
    }

    
    // while ( Far_Right )
    // {
    //     Go_left(pwm2);
    //     Read_InfraRed();
    // }
    // while ( !Far_Right )
    // {
    //     Go_left(pwm2);
    //     Read_InfraRed();
    // }
    // while ( Right )
    // {
    //     Go_left(pwm2);
    //     Read_InfraRed();
    // }
    // delay(5000);

}