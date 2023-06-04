// #include<stdio.h>
// #include<stdbool.h>
#include<string.h>
// #include<time.h>
#include "functions.h"
#include<stdlib.h>

void setup()
{
  Serial.begin(9600);
  pinMode(A5,INPUT);
  pinMode(A4,INPUT);
  pinMode(A3,INPUT);
  pinMode(A2,INPUT);
  pinMode(A1,INPUT);
  // strcpy(position.current_position,"A0");
  // strcpy(position.previous_position,"A0");
}
void loop() 
{
    Serial.println("time_spent");
    // Read_InfraRed();
    Follow_line();
    // Move_Forward();
    
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
