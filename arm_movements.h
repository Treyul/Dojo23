#include "arm_variables.h"

/* C trigonometric function take params in radians*/
int Check_validity(int x,int y)
{
    int valid = pow(x,2) - pow(y,2);
    return valid;
} 

void Calculate_Angles(int x, int y)
{
    if (x <= MIN_X_VALUE || Check_validity(x,y) < 0)
    {
        printf("Invalid coordinates \n");
        return;
    }
    double Elbow_Cosine = ( pow(SHOULDER_LENGTH,2) + pow(ELBOW_LENGTH,2) - pow(x,2) ) / (2 * SHOULDER_LENGTH * ELBOW_LENGTH );

    double Elbow_Angle = Elbow_Cosine==-1? 180 : acos(Elbow_Cosine) * RAD_TO_DEG;

    double lower_Shoulder_angle = asin( (double)y / (double)x );

    double higher_shoulder_angle = asin( (sin(Elbow_Angle * DEG_TO_RAD ) * ELBOW_LENGTH ) / (double)x );

    double Total_Shoulder_Angle = lower_Shoulder_angle * RAD_TO_DEG + higher_shoulder_angle * RAD_TO_DEG;
    
    printf("Soulder angle is %lf\n",round(Total_Shoulder_Angle));
    printf("Higher angle is %lf\n",higher_shoulder_angle * RAD_TO_DEG);
    printf("Lower angle is %lf\n",lower_Shoulder_angle * RAD_TO_DEG);
    printf("Elbow angle is %lf",round(Elbow_Angle));
}
