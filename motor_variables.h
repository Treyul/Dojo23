#include <AFMotor.h>

int speed = 180;

// init the motor with the pin numbers
AF_DCMotor Left_Motor(4);
AF_DCMotor Right_Motor(3);

// initialize variables to store the ir readings
/*  A5 
 *  A4
 *  A3
 *  A2
 *  A1
 */ 
int Far_Right,Right,Middle,Left,Far_Left;