#define pwm 255
#define pwm2 130

// define pin number of Ir sensors
#define LEFT_IR 
#define FAR_LEFT_IR A3
#define RIGHT_IR
#define FAR_RIGHT_IR
#define MIDDLE_LEFT 2
#define MIDDLE_RIGHT 3
#define BACK_LEFT 5 
#define BACK_RIGHT 4
// init the motor with the pin numbers
// Left motor
#define en1   40
#define in1   44
#define in2   42

// Right motor
#define en2   50
#define in3   48
#define in4   46

// define variables of ultra sonic
#define trigger 7
#define echo 6

// init variable to store ir readings
int Far_Right,Right,Middle,Left,Far_Left,Back_left,Back_right,middle_right,middle_left;

void Read_InfraRed()
{
    /*Readings interpretation
    * 0 ->  Not on line
    * 1 ->  On line
    */
  middle_left = digitalRead(MIDDLE_LEFT);
  middle_right = digitalRead(MIDDLE_RIGHT);

  Back_left = digitalRead(BACK_LEFT);
  Back_right = digitalRead(BACK_RIGHT);
  
  Far_Right = digitalRead(FAR_RIGHT_IR);
  Right = digitalRead(RIGHT_IR);
  Left = digitalRead(LEFT_IR); 
  Far_Left =digitalRead(FAR_LEFT_IR);
}
