#include"motor_variables.h"

void Move_to_the_next_Junction()
{
    bool Junction = false;

    while ( !Junction )
    {

        if ( Far_Right || Far_Left )
        {
            Junction = true;       
        }
        Line_Following();
    }

    // stop the motors when a junction is reached
    Stop_Motors();
}

void Move_to_the_prev_Junction()
{
    bool Junction = false;

    while ( !Junction )
    {   
        // If the periphery ir read a line a junction has been met
        if ( Far_Right || Far_Left )
        {
            Junction = true;     
        }
        Reverse_Line_Following();
    }

    // stop the motors when a junction is reached
    Stop_Motors();
}

void Move_out_of_Junction()
{
    // Line_Following();
    bool Passed = false;

    while ( !Passed )
    {

        if ( middle_right || middle_left )
        {
            Passed = true;
        }

        Read_InfraRed();

        // Move within limits
        Line_Following();
        // if ( Far_Left && !Far_Right )
        // {
        //     Go_left(pwm2);
        // }
        // else if ( Far_Right && !Far_Left )
        // {
        //     Go_right(pwm2);
        // }
        // else
        // {
        //   Move_Forward(pwm2);
        // }
    }

    Stop_Motors();
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

void Reverse_Line_Following()
{
        // take the infra-red readings
        Read_InfraRed();

        if ( !Back_right && !Back_left || Back_right && Back_left)
        {
            reverse(pwm);
        }
        else if ( Back_left && !Back_right )
        {
            //when the Back_right ir is on the line move Back_right 
            Go_left(pwm2);
        }
        else if ( Back_right && !Back_left )
        {
            //when the right ir is on the line move right 
            Go_right(pwm2);
        }
        else
        {
            reverse(pwm);
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

// void reverse_left(int pwm_speed)
// {
//     analogWrite(en1, pwm_speed);
//     analogWrite(en2, pwm_speed);
//     digitalWrite(in1, LOW);
//     digitalWrite(in2, HIGH);
//     digitalWrite(in3, HIGH);
//     digitalWrite(in4, LOW);
// }

// void reverse_right ( int pwm_speed)
// {
//     analogWrite(en1, pwm_speed);
//     analogWrite(en2, pwm_speed);
//     digitalWrite(in1, LOW);
//     digitalWrite(in2, HIGH);
//     digitalWrite(in3, HIGH);
//     digitalWrite(in4, LOW);
// }

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

void calibration()
{
    bool calibrated = false;

    while ( !calibrated )
    {
        // GO left until right is reached
        while ( !Far_Right )
        {
            Go_left(pwm2);
            Read_InfraRed();
            if ( Left && Right )
            {
                calibrated = true;
                return;
            }
            else if ( Far_Right )
            {

            Stop_Motors();
            while ( !Far_Left )
            {
                Go_right(pwm2);
                Read_InfraRed();
                if ( Left && Right )
                {
                    calibrated = true;
                    return;
                }
                else if ( Far_Left )
                {
                    Stop_Motors();
                    return;
                }
            }
                return;
            }
        }
 
    }
}

float Ultra_Sonic_reading()
{
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);

    float duration = pulseIn(echo, HIGH);
    float d = duration * 0.034 /2;
    return d;
}