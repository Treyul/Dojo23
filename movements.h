#include"motor_variables.h"

void Line_Following()
{

    while ( !Far_Right && !Far_Left )
    {
        // take the infra red readings
        Read_InfraRed();

        if ( !Left && !Right)
        {
            Move_Forward(pwm2);
        }
        else if ( Left && !Right )
        {
            //when the left ir is on the line move left 
            Go_left(pwm2);
        }
        else if ( !Left && Right )
        {
            //when the right ir is on the line move right 
            Go_right(pwm2);
        }
        else
        {
            Move_Forward(pwm2);
        }
    }

    // stop the motors when a junction is reached
    Stop_Motors();
}
// }

void Stop_Motors()
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}

void Move_Forward(int pwm_speed)
{
    analogWrite(en1, pwm_speed);
    analogWrite(en2, pwm_speed);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

void reverse(int pwm_speed)
{
    analogWrite(en1, pwm_speed);
    analogWrite(en2, pwm_speed);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);

}

void Go_right(int pwm_speed)
{
    analogWrite(en1, pwm_speed);
    analogWrite(en2, pwm_speed);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

void Go_left(int pwm_speed)
{
    analogWrite(en1, pwm_speed);
    analogWrite(en2, pwm_speed);
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
        // Serial.println("Turning.....");
        // Serial.print("right is ");
        // Serial.println(Far_Right?"on line":"Not in line");
        // Serial.print("tail is ");
        // Serial.println(Back_Fin?"on line":"Not in line");
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

    while (/* !Back_Fin &&*/ !Far_Right )
    {
        Go_left(pwm2);
        Read_InfraRed();
        // Serial.println("Turning.....");
        // Serial.print("right is ");
        // Serial.println(Far_Right?"on line":"Not in line");
        // Serial.print("tail is ");
        // Serial.println(Back_Fin?"on line":"Not in line");
        // Back_Fin = digitalRead(8);
    }
    if ( Far_Right )
    {
        // Serial.println("Reached end.....");
        while ( !Right )
        {
        // Serial.println("readjustment....");
        Go_right(pwm2);
        Read_InfraRed();
        }
    }
}
