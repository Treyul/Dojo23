// #include<stdio.h>
// #include<stdbool.h>
/**TODO
 * add 8 segment for displaying current position
*/
#include<string.h>
#include "functions.h"
#include<stdlib.h>
// #include<time.h>

void setup()
{ 
  // set up ir pins for readings
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(7,INPUT);
  pinMode(12,INPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  
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

  // Serial monitor printing
   Serial.begin(9600);
   
  strcpy(position.current_position,"A0");
  strcpy(position.previous_position,"A0");
}


void loop() 
{
    Serial.println("time_spent");
    // Line_Following();
// Move_Forward(pwm);
  // Reverse_Line_Following();
    position = Engine_assembly(position);
    // Stop_Motors();
    // delay(2000);
    position = Rack_assembly(position);
    position = Cabin_assembly(position);
    strcpy(position.destination,"C3");
    position = New_Navigation(position);
    // Stop_Motors();
    // delay(2000);
    strcpy(position.destination,"B3");
    position = New_Navigation(position);
    strcpy(position.destination,"B2");
    position = New_Navigation(position);
    strcpy(position.destination,"A2");
    position = New_Navigation(position);
    strcpy(position.destination,"A1");
    position = New_Navigation(position);
    Stop_Motors();
    delay(100000);

        // Reverse_Line_Following();  

    
    // clock_t begin = clock();
    // run through the array of checkers
    // for (int i = 0; i < 7; i++ )
    // {
    //     if(!procedure[i])
    //     {
    //         if (i == 0){
    //             position = Engine_assembly(position);
    //         }
    //         if (i == 1){
    //             // position = Rack_assembly(position);
    //         }
    //         if (i == 2){}
    //         if (i == 3){}
    //         if (i == 4){}
    //         if (i == 5){}
    //         if (i == 6){}
    //     }
    // }


    // clock_t end = clock();
    // double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    Serial.print("Execution time is");
    // Serial.println(time_spent);
// use of indexes will be implement for easier mappind of coordinates
    // printf("test %s",position.current_position);
    return 0;  
}
