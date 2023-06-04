#include"motor_variables.h"

void Read_InfraRed()
{
  Far_Right = digitalRead(A1);
  Right = digitalRead(A2);
  Middle = digitalRead(A3);
  Left = digitalRead(A4); 
  Far_Left =digitalRead(A5); 
  Serial.print(Far_Right);
  Serial.print(Right);
  Serial.print(Middle);
  Serial.print(Left);
  Serial.println(Far_Left);
}

void Stop_Motors()
{
    Left_Motor.run(RELEASE);
    Right_Motor.run(RELEASE);
}

void Move_Forward()
{
    Left_Motor.setSpeed(speed);
    Right_Motor.setSpeed(speed);
    Left_Motor.run(FORWARD);
    Right_Motor.run(FORWARD);
    Serial.println("Forward");
}

void reverse()
{
    Left_Motor.setSpeed(speed);
    Right_Motor.setSpeed(speed);
    Left_Motor.run(BACKWARD);
    Right_Motor.run(BACKWARD);
}

void Go_right()
{
    Left_Motor.setSpeed(speed);
    Right_Motor.setSpeed(speed);
    Left_Motor.run(FORWARD);
    Right_Motor.run(BACKWARD);
}

void Go_left()
{
    Left_Motor.setSpeed(speed);
    Right_Motor.setSpeed(speed);
    Left_Motor.run(BACKWARD);
    Right_Motor.run(FORWARD);
}

void Turn_Right()
{
    /*  Ensure that the last ir in that side has reached a line    */
    
}

void Turn_left()
{


}
void conditional_stop()
{
    if ( !Far_Right && !Far_Left)
    {
        Stop_Motors();
    }
}
void Follow_line()
{
    Read_InfraRed();

    conditional_stop();
    while( !Middle )
    {
        Read_InfraRed();
        conditional_stop();
        Move_Forward();
        Serial.print(Middle);
        Serial.println("going_straight");
    }
    if( Middle )
    {
        // if tilted to the left should move right
        if ( Left)
        {
            Serial.println("going_right");
            Go_left();
        }
        else if ( !Left )
        {
            Serial.println("going left");
            Go_right();
        }
        // if tilted to the right should move left
    }
}