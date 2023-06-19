// #include<stdio.h>
// #include<stdbool.h>
/**TODO
 * add 8 segment for displaying current position
*/
#include<string.h>
// #include<time.h>
#include "functions.h"
#include<stdlib.h>

void setup()
{ 
  // set up ir pins for readings
  pinMode(13,INPUT);
  pinMode(12,INPUT);
  pinMode(11,INPUT);
  pinMode(10,INPUT);
  
  // set up for motor control
  pinMode(en1, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(en2, OUTPUT);

  // Serial monitor printing
   Serial.begin(9600);
   
  // strcpy(position.current_position,"A0");
  // strcpy(position.previous_position,"A0");
}


void loop() 
{
    Serial.println("time_spent");
    // Read_InfraRed();
    // Follow_line();
    Line_Following();
    // Turn_left();
    // Go_left(130);
    // Go_right(130);        
    // delay(6000);
    // Turn_Right();
    // delay(6000);
    
    // Move_Forward(120);
    // delay(2000);
    // Stop_Motors();
    // delay(2000);
    
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
    //             // position = 
    //         }
    //         if (i == 2){}
    //         if (i == 3){}
    //         if (i == 4){}
    //         if (i == 5){}
    //         if (i == 6){}
    //     }
    // }
    // Move_Forward();
    // delay(2000);
    // reverse();
    // delay(2000);
    // Go_right();
    // delay(2000);
    // Serial.println("going left");
    // Go_left();
    
    // delay(2000);

    // clock_t end = clock();
    // double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    Serial.print("Execution time is");
    // Serial.println(time_spent);
// use of indexes will be implement for easier mappind of coordinates
    // printf("test %s",position.current_position);
    return 0;  
}
