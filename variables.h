#include<stdbool.h>
#include<stdio.h>

// pre define the locale of the objects
#define Wheel_Rack_Location = ""
#define Engine_Location "D1"
#define Trailer_Location "A2"
#define Cabin_Location "D4"
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
    {"99","B4","C4","D4"},
    {"99","B3","C3","D3"},
    {"A2","B2","C2","D2"},
    {"A1","00","C1","D1"},
};

// define procedure array for the checkers
// Engine,w1,w2,w3,w4,cabin,trailer
bool procedure[7] = {false,false,false,false,false,false,false};

struct travel position;

/**     Function names    */
struct travel Engine_assembly(struct travel pos);
struct travel Trailer_assembly(struct travel pos);
struct travel Cabin_assembly(struct travel pos);
struct travel Rack_assembly(struct travel pos);
struct travel Upper_Right_Wheel(struct travel pos);
struct travel Upper_left_Wheel(struct travel pos);
struct travel Lower_Right_Wheel(struct travel pos);
struct travel Lower_Left_Wheel(struct travel pos);
struct travel navigation(struct travel pos);
struct travel Update_Forward_Position(struct travel pos);
struct travel Forward_Row_Update (struct travel pos);
// struct travel Row_Transversion (struct travel pos);
// struct travel Column_Transversion (struct travel pos);
// struct travel nav(struct travel pos);

/*  functions that involve moving the bot */
void Stop_Motors();
void Move_Forward();
void reverse();
void Go_right();
void Go_left();
void Turn_Right();
void Turn_left();
void Read_InfraRed();