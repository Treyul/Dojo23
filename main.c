// #include<stdio.h>
// #include<stdbool.h>
#include<string.h>
#include<time.h>
#include "functions.h"
#include<stdlib.h>

int main(void){
    clock_t begin = clock();

    // define the iniial position
    strcpy(position.current_position,"A0");
    strcpy(position.previous_position,"A0");

    // printf("check %s\n",positions[3][3]);

    // run through the array of checkers
    for (int i = 0; i < 7; i++ )
    {
        if(!procedure[i])
        {
            if (i == 0){
                Engine_assembly(position);
            }
            if (i == 1){}
            if (i == 2){}
            if (i == 3){}
            if (i == 4){}
            if (i == 5){}
            if (i == 6){}
        }
    }


    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    // printf("array size is %i\n",sizeof(positions[2]));
    // printf("element size is %i\n",(sizeof (positions[2][0])));
    printf("Execution time is %f",time_spent);
// use of indexes will be implement for easier mappind of coordinates
    // printf("test %s",position.current_position);
    return 0;  
}
