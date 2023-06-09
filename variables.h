#include<stdbool.h>
#include<stdio.h>

// pre define the locale of the objects
#define Wheel_Rack_Location = "D2"
#define Engine_Location "D1"
#define Trailer_Location "A2"
#define Cabin_Location "C4"
#define Wheel_Right_Side "C1"
#define Wheel_Left_Side "C3"
#define Rack_Location "D2"
#define Car_Assembly_Location "C2"

struct travel
{
    char previous_position[3];
    char current_position[3];
    char destination[3];
} ;

// The coordinate C2 cannot be used as a path
 char* positions[4][4] = {
    // rows defination are alpabetical
    // columns are numerical
/*    0     1    2    3 */
    {"99","B4","C4","99"}, 
    {"99","B3","C3","D3"},
    {"A2","B2","C2","D2"},
    {"A1","00","C1","D1"},
};

char* Next_position[3];

// define procedure array for the checkers
// Engine,w1,w2,w3,w4,cabin,trailer
bool procedure[7] = {false,false,false,false,false,false,false};

struct travel position;

/**     Function names    */
// Assembly functions
struct travel Engine_assembly(struct travel pos);
struct travel Trailer_assembly(struct travel pos);
struct travel Cabin_assembly(struct travel pos);
struct travel Rack_assembly(struct travel pos);
struct travel Upper_Right_Wheel(struct travel pos);
struct travel Upper_left_Wheel(struct travel pos);
struct travel Lower_Right_Wheel(struct travel pos);
struct travel Lower_Left_Wheel(struct travel pos);

// navigating functions
struct travel navigation(struct travel pos);
struct travel Update_Forward_Position(struct travel pos);
struct travel Forward_Row_Update (struct travel pos);
struct travel Row_Transversion (struct travel pos);
struct travel Column_Transversion (struct travel pos);
struct travel New_Navigation(struct travel pos);

/*  functions that involve moving the bot */
void Stop_Motors();
void Move_Forward(int pwm_speed);
void reverse(int pwm_speed);
void Go_right(int pwm_speed);
// void reverse_right(int pwm_speed);
// void reverse_left(int pwm_speed);
void Go_left(int pwm_speed);
void Go_Left_turn(int pwm_speed);
void Go_Right_turn(int pwm_speed);
void Turn_Right();
void Turn_left();
void Line_Following();
void Reverse_Line_Following();
void Read_InfraRed();
void Move_to_the_next_Junction();
void Move_to_the_prev_Junction();
void Move_out_of_Junction();
float Ultra_Sonic_reading();
void calibration();

// functions involing the movement of the arm
int* Calculate_Angles(int distance, int y, int ST_ANGLE = 404);
void Move_To_target(int* angle_array );
int Check_validity(int x,int y);
void Open_Claws();
void Close_Claws(int Right, int left);
void Pick_Object();