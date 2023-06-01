#include<stdio.h>
#include<math.h>
#include"variables.h"

// function for assembly of engine
void Engine_assembly(struct travel pos)
{
    strcpy(pos.destination,Engine_Location);
    navigation(pos);
    printf("picked engine\n");
    // write the point from which the bot should approach the assemble
    strcpy(pos.destination,Car_Assembly_Location);

    // light led up to show step is done
}
char* Trailer_assembly(struct travel pos)
{
    strcpy(pos.destination,Trailer_Location);
}
char* Cabin_assembly(struct travel pos)
{
    strcpy(pos.destination,Cabin_Location);
}
char* Rack_assembly(struct travel pos)
{
    strcpy(pos.destination,Rack_Location);
}

void navigation(struct travel pos)
{
    // get the values for the column and variables
    char Current_column = pos.current_position[0], Current_Row = pos.current_position[1];
    char destination_column = pos.destination[0], destination_Row = pos.destination[1];
    char previous_column = pos.previous_position[0], previous_Row = pos.previous_position[1];

    // move the bot as long as the position is not the destination
    while( strcmp(pos.current_position,pos.destination) )
    {
        // printf("comparison is showing %i",strcmp(pos.current_position,pos.destination));
        // printf("previous %s, new  %s destination %s\n",pos.previous_position,pos.current_position,pos.destination);

        // check if the bot is in the start position
        if ( !strcmp(pos.current_position,"A0") && !strcmp(pos.previous_position,"A0") )
        {
            printf("Start Position\n");
            printf("move forward\n");
            strcpy(pos.current_position,"A1");
        }

        //  Enter matrice coordinates
        else
        {   
            // Check for alignment of coordinates
            // columns matching
            if (pos.current_position[1] == pos.destination[1])
            {
                // check direction to move
                if (pos.previous_position[0] == pos.current_position[0] && pos.previous_position[1] < pos.current_position[1])
                {
                    printf("Turn right...move forward\n");
                    pos = Update_Forward_Position(pos);
                }
                else if (pos.previous_position[0] == pos.current_position[0] && pos.previous_position[1] > pos.current_position[1])
                {
                    printf("Turn left\n");
                    /* MOVE FORWARD next junction*/
                    strcpy(pos.current_position,"C1");
                    strcpy(pos.previous_position,"A1");
                }
                else if (pos.previous_position[0] < pos.current_position[0] && pos.previous_position[1] == pos.current_position[1])
                {
                    printf("moveforward\n");
                    /* next junction */
                    pos = Update_Forward_Position(pos);
                    printf("previousss %s, new  %s destination %s\n",pos.previous_position,pos.current_position,pos.destination);
                    
                    // strcpy(pos.current_position,"D1");
                    // strcpy(pos.previous_position,"C1");
                }
                
            }
            
            // rows matching
            else if (pos.current_position[0] == pos.destination[0])
            {
                printf("rows...\n");
            }
            // strcpy(pos.current_position,pos.destination);
            
        }
    }

    printf("Arrived. \n");

    // char Current_Row = pos.current_position[1];
    // char destination_Row = pos.destination[1];
}

struct travel Update_Forward_Position(struct travel pos)
{
    int matrice_index = abs( (pos.current_position[1] - '0' + 0) - 4);
    for(int i = 0; i < 4; i++ )
    {
        if ( !strcmp(positions[matrice_index][i],"00") )
        {
            printf("null\n");
            continue;
        }
        else if ( !strcmp(positions[matrice_index][i] , pos.current_position) )
        {
            strcpy(pos.previous_position,pos.current_position);

            if (!strcmp(positions[matrice_index][i+1],"00"))
            {
                strcpy(pos.current_position,positions[matrice_index][i+2]);
            }
            else
            {
                strcpy(pos.current_position,positions[matrice_index][i+1]);
            }

            
            break;
        }
    }
    printf("previous %s, new  %s destination %s\n",pos.previous_position,pos.current_position,pos.destination);
    
    return pos;
}


