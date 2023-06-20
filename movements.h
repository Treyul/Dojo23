#include"motor_variables.h"


void Move_to_the_next_Junction()
{
    bool Junction = false;

    while ( !Junction )
    {

        if ( Far_Right || Far_Left )
        {
            Junction = true;
            Serial.println(Far_Right);
            Serial.println(Far_Left);        
        }
        Serial.print(Junction);
        Serial.println("Moving");
        Line_Following();
    }

    // stop the motors when a junction is reached
    Serial.println("Arrived at  Junction");
    // Stop_Motors();
    // delay(2000);
}

void Move_out_of_Junction()
{
    // Line_Following();
    bool Passed = false;

    while ( !Passed )
    {

        if ( Back_right || Back_left )
        {
            Passed = true;
        }

        Read_InfraRed();

        // Move within limits
        if ( Far_Left && !Far_Right )
        {
            Go_left(pwm2);
        }
        else if ( Far_Right && !Far_Left )
        {
            Go_right(pwm2);
        }
        else
        {
          Move_Forward(pwm2);
        }
    }

    // Stop_Motors();
    // delay(2000);
}

void Line_Following()
{
        // take the infra-red readings
        Read_InfraRed();

        if ( !Left && !Right || Left && Right)
        {
            Move_Forward(pwm);
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
            Move_Forward(pwm);
        }
}

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

void Go_Left_turn(int pwm_speed)
{
    analogWrite(en1, pwm_speed);
    analogWrite(en2, pwm_speed);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

void Go_Right_turn(int pwm_speed)
{
    analogWrite(en1, pwm_speed);
    analogWrite(en2, pwm_speed);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}

void Turn_Right()
{
    Move_out_of_Junction();
    /*  Ensure that the last ir in that side has reached a line    */
    while ( !Far_Right )
    {
        Go_Right_turn(pwm2);
        Read_InfraRed();
    }

    while ( !Right )
    {
        Go_Right_turn(pwm2);
        Read_InfraRed();
    }

    Read_InfraRed();
    // Stop_Motors();
    // delay(2000);
    return;
    
}

void Turn_left()
{
    Move_out_of_Junction();
    
    while ( !Far_Left )
    {
      
        Go_Left_turn(pwm2);
        Read_InfraRed();
        Serial.println("Going far left");
    }
    Serial.println("Next....");
    // Stop_Motors();
    // delay(2000);

    while ( !Left )
    {
        Go_Left_turn(pwm2);
        Read_InfraRed();

    }
    // Read_InfraRed();
    // Stop_Motors();
    // delay(2000);
    return;
}
