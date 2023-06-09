#include<math.h>
#include<stdio.h>

#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105

#define SHOULDER_LENGTH 210
#define ELBOW_LENGTH 100
#define MIN_X_VALUE 110 + 10


/* C trigonometric function take params in radians*/
int Check_validity(int x,int y)
{
    int valid = pow(x,2) - pow(y,2);
    return valid;
}
int * Calculate_Angles(int x, int y)
{
    static int Coordinates[2];
    if (x <= MIN_X_VALUE || Check_validity(x,y) < 0)
    {
        printf("Invalid coordinates \n");
    Coordinates[0] = 0;
    Coordinates[1] = 0;
    return Coordinates;
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
    Coordinates[0] = Total_Shoulder_Angle;
    Coordinates[1] = Elbow_Angle;

    return Coordinates;
}

int main (void )
{
    int *Coordinates = Calculate_Angles(212.5,100);
    printf("Angles is %d", (int) Coordinates[0]);
    // printf
}
