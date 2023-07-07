// #include<stdio.h>
// #include<stdbool.h>
/**TODO
 * add 8 segment for displaying current position
*/
#include<string.h>
// #include<stdlib.h>
#include "functions.h"
// #include<time.h>


void setup()
{ 
  // set up ir pins for readings
  pinMode(FAR_LEFT_IR,INPUT);
  pinMode(BACK_LEFT,INPUT);
  pinMode(MIDDLE_LEFT,INPUT);
  pinMode(FAR_RIGHT_IR,INPUT);
  pinMode(BACK_RIGHT,INPUT);
  pinMode(MIDDLE_RIGHT,INPUT);
  pinMode(RIGHT_IR,INPUT);
  pinMode(LEFT_IR,INPUT);
  
  // set up for motor control
  pinMode(en1, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(en2, OUTPUT);

  // set up for ultra sonic sensor
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT_PULLUP);

  // set up of arm variables
  Shoulder.attach(SHOULDER);
  Elbow.attach(ELBOW);
  Wrist.attach(WRIST);
  Left_Claw.attach(LEFTCLAW);
  Right_Claw.attach(RIGHTCLAW);

  //Pins for Stepper Motor Control
  pinMode(Stepper_En1, OUTPUT);
  pinMode(Stepper_En2, OUTPUT);
  stepper.setSpeed(60);

  // Serial monitor printing
   Serial.begin(9600);
   Wrist.write(93);
   
  strcpy(position.current_position,"A0");
  strcpy(position.previous_position,"A0");
}


void loop() 
{
	// enable the steppers
	digitalWrite(Stepper_En1, HIGH);
  digitalWrite(Stepper_En2, HIGH);
	Serial.println("time_spent");
	int init[3] = {90,90,0};
	Move_To_target(init);
  	delay(5000);
	int *Coordinates = Calculate_Angles(310,-167);
  Serial.print(Coordinates[0]);
	Serial.println(Coordinates[1]);
	Open_Claws();
	Move_To_target(Coordinates);
	Close_Claws(80,100);
  delay(5000);

  // Serial.print()
    // Coordinates[0] = 150 - Coordinates[0];
    // Coordinates[1] =  Coordinates[1];
  	Serial.println(Coordinates[1]);

  
    // position = Engine_assembly(position);
    // // Stop_Motors();
    // // delay(2000);
    // position = Rack_assembly(position);
    // position = Cabin_assembly(position);
    // strcpy(position.destination,"C3");
    // position = New_Navigation(position);
    // // Stop_Motors();
    // // delay(2000);
    // strcpy(position.destination,"B3");
    // position = New_Navigation(position);
    // strcpy(position.destination,"B2");
    // position = New_Navigation(position);
    // strcpy(position.destination,"A2");
    // position = New_Navigation(position);
    // strcpy(position.destination,"A1");
    // position = New_Navigation(position);
    // Stop_Motors();
    // delay(100000);

        // Reverse_Line_Following();  

    
    // clock_t begin = clock();
    // run through the array of checkers


    // clock_t end = clock();
    // double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    Serial.print("Execution time is\n");
    // Serial.println(time_spent);
// use of indexes will be implement for easier mappind of coordinates
    // printf("test %s",position.current_position);
    return 0;  
}
