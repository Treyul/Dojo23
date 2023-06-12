#include"motor_variables.h"

void conditional_stop()
{
    if ( !Far_Right && !Far_Left)
    {
        Stop_Motors();
    }
}
// void Follow_line()
// {
//     Read_InfraRed();
//     if ( !Middle && Far_Left && Far_Right || Right && Middle && Left )
//     {
//         Move_Forward();

//     }
//     else if (Middle)
//     {
//         // // while (Middle)
//         // // {

//     while (Middle)
//     {
//         // ERROR with ir raeding if fixed replace Right with !Left
//         if (!Right)
//         {
//             Go_right();
//         }
//         else if (Right)
//         {
//             Go_left();
//         }
//         Read_InfraRed();
//     }
//     }
//     else
//     {
//         Stop_Motors();
//     }
//     // conditional_stop();

// }


void Line_Following()
{
    Read_InfraRed();
    if ( Far_Right or Far_Left  )
    {
        // Serial.println("stoping");
        Stop_Motors();
        delay(1000);
        Turn_left();
        return;
    }
    // while () 
    // {
    if ( !Left && !Right)
    {
        Move_Forward(pwm2);
    }
    else if ( Left && !Right )
    {
        //when the left ir is on the line move left 
        Go_left(pwm2);
    }else if ( !Left && Right )
    {
        //when the right ir is on the line move right 
        Go_right(pwm2);
    }
    else
    {
        Move_Forward(pwm2);
    }
    }
// }
// void Follow_line()
// {
//     Read_InfraRed();

//     conditional_stop();
//     while( !Middle )
//     {
//         Read_InfraRed();
//         conditional_stop();
//         Move_Forward();
//         Serial.print(Middle);
//         Serial.println("going_straight");
//     }
//     if( Middle )
//     {
//         // if tilted to the left should move right
//         if ( Left)
//         {
//             Serial.println("going_right");
//             Go_left();
//         }
//         else if ( !Left )
//         {
//             Serial.println("going left");
//             Go_right();
//         }
//         // if tilted to the right should move left
//     }
// }