/*
 * return  coordination
 * 
 * define rest position
 * define height of objects for the y axis defination in arm movement
 * lcd screen ?* /*if minimum power consumption implement 
*/

#include "arm_variables.h"

/* C trigonometric function take params in radians*/
int Check_validity(int x,int y)
{
    int valid = pow(x,2) - pow(y,2);
    return valid;
} 

int * Calculate_Angles(int distance, int y, int ST_ANGLE = 404)
{
    static int Coordinates[3];
    int x = sqrt(pow(distance,2) + pow(y,2));
    if (x <= MIN_X_VALUE || Check_validity(x,y) < 0  || y < -ARM_HEIGHT || abs(x) > (SHOULDER_LENGTH + ELBOW_LENGTH ))
    {
        Serial.println("Invalid coordinates \n");
    Coordinates[0] = 0;
    Coordinates[1] = 0;
    Coordinates[2] = 0;
    return Coordinates;
    }
    // Serial.println(ST_ANGLE);
    if ( ST_ANGLE = 404)
    {
        if ( Previous_Coordinates[2] == 0 )
        {
            Coordinates[2] = 100;
        }
        else if ( Previous_Coordinates[2] == 180 )
        {
            Coordinates[2] = 100;
        }
    }
    else 
    {
        Coordinates[2] = ST_ANGLE;        
    }

    double Elbow_Cosine = ( pow(SHOULDER_LENGTH,2) + pow(ELBOW_LENGTH,2) - pow(x,2) ) / (2 * SHOULDER_LENGTH * ELBOW_LENGTH );

    double Elbow_Angle = Elbow_Cosine==-1? 180 : acos(Elbow_Cosine) * RAD_TO_DEG;

    double lower_Shoulder_angle = asin( (double)abs(y) / (double)abs(x) );

    double higher_shoulder_angle = asin( (sin(Elbow_Angle * DEG_TO_RAD ) * ELBOW_LENGTH ) / (double)abs(x) );

    double Total_Shoulder_Angle = lower_Shoulder_angle * RAD_TO_DEG + higher_shoulder_angle * RAD_TO_DEG;
    
    printf("Soulder angle is %lf\n",round(Total_Shoulder_Angle));
    printf("Higher angle is %lf\n",higher_shoulder_angle * RAD_TO_DEG);
    printf("Lower angle is %lf\n",lower_Shoulder_angle * RAD_TO_DEG);
    printf("Elbow angle is %lf\n",Elbow_Cosine);
    Coordinates[0] = y < 0 ? 90 + (int) round(Total_Shoulder_Angle) : 90 - (int) round(Total_Shoulder_Angle);
    Coordinates[1] = 180 - (int) round(Elbow_Angle);

    return Coordinates;
}

void Move_To_target(int* angle_array )
{
    int Shoulder_Angle = angle_array[0];
    int Previous_Shoulder_Angle = Previous_Coordinates[0];

    int Elbow_Angle = angle_array[1];
    int Previous_Elbow_Angle = Previous_Coordinates[1];

    int Stepper_Angle = angle_array[2];
    int Previous_Stepper_Angle = Previous_Coordinates[2];

    // TODO Rotate Stepper Motor
    if (Previous_Stepper_Angle < Stepper_Angle)
    {
        for (Previous_Stepper_Angle; Previous_Stepper_Angle < Stepper_Angle; Previous_Stepper_Angle++)
        {
            stepper.step(1);
            Serial.println("Moving Clockwise");
            delay(15);
        }
    }
    else if ( Previous_Stepper_Angle > Stepper_Angle )
    {
        for ( Previous_Stepper_Angle; Previous_Stepper_Angle > Stepper_Angle; Previous_Stepper_Angle--)
        {
            stepper.step(-1);
            Serial.println("Moving Anti-Clockwise");
            delay(15);
        }
    }

    // move elbow
    if ( Previous_Elbow_Angle < Elbow_Angle )
    {
        for (Previous_Elbow_Angle; Previous_Elbow_Angle <= Elbow_Angle; Previous_Elbow_Angle++ )
        {
            Serial.print("Increasing...\nElbow Angle is now ");
            Serial.println(Previous_Elbow_Angle);
            Elbow.write(Previous_Elbow_Angle);
            delay(15);        
        }
    }
    else if ( Previous_Elbow_Angle > Elbow_Angle )
    {
        for (Previous_Elbow_Angle; Previous_Elbow_Angle >= Elbow_Angle; Previous_Elbow_Angle-- )
        {
            Serial.print("Decreasing...\nElbow Angle is now ");
            Serial.println(Previous_Elbow_Angle);
            Elbow.write(Previous_Elbow_Angle);
            delay(15);          
        }
    }

    // move shoulder
    if ( Previous_Shoulder_Angle < Shoulder_Angle )
    {
        for (Previous_Shoulder_Angle; Previous_Shoulder_Angle <= Shoulder_Angle; Previous_Shoulder_Angle++ )
        {
            Serial.print("Increasing...\nShoulder Angle is now ");
            Serial.println(Previous_Shoulder_Angle);
            Shoulder.write(Previous_Shoulder_Angle);
            delay(15);
        }
    }
    else if ( Previous_Shoulder_Angle > Shoulder_Angle )
    {
        for ( Previous_Shoulder_Angle; Previous_Shoulder_Angle >= Shoulder_Angle; Previous_Shoulder_Angle-- )
        {
            Serial.print("Decreasing...\nShoulder Angle is now ");
            Serial.println(Previous_Shoulder_Angle);
            Shoulder.write(Previous_Shoulder_Angle);
            delay(15);       
        }
    }    

    Previous_Coordinates[1] = angle_array[1];
    Previous_Coordinates[0] = angle_array[0]; 
    Previous_Coordinates[2] = angle_array[2];   
}

void Open_Claws()
{
    Right_Claw.write(120);
    Left_Claw.write(60);
}

void Pick_Object()
{

}

void Close_Claws(int Right, int left)
{
    Right_Claw.write(Right);
    Left_Claw.write(left);
}