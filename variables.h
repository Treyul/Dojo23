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
    /* data */
    char previous_position[3];
    char current_position[3];
    char destination[3];

} ;

    // The coordinate C2 cannot be used as a path
 char* positions[4][4] = {
    // rows defination are alpabetical
    // columns are numerical
    {"00","B4","C4","D4"},
    {"00","B3","C3","D3"},
    {"A2","B2","C2","D2"},
    {"A1","00","C1","D1"},
};
// define checkers for assembly
// bool Engine_pass = false;
// bool rack_pass = false;
// bool wheel1_pass = false;
// bool wheel2_pass = false;
// bool wheel3_pass = false;
// bool wheel4_pass = false;
// bool Trailer_pass = false;
// bool cabin_pass = false;

// define procedure array for the checkers
// Engine,w1,w2,w3,w4,cabin,trailer
bool procedure[7] = {false,false,false,false,false,false,false};

struct travel position;

/**     Function names    */
void Engine_assembly(struct travel pos);
char* Trailer_assembly(struct travel pos);
char* Cabin_assembly(struct travel pos);
char* Rack_assembly(struct travel pos);
void navigation(struct travel pos);
struct travel Update_Forward_Position(struct travel pos);