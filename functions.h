#include<stdio.h>
#include<math.h>
#include<string.h>
#include"variables.h"
#include"movements.h"

// function for assembly of engine
struct travel Engine_assembly(struct travel pos)
{
    strcpy(pos.destination,Engine_Location);
    pos = navigation(pos);
    printf("picked engine\n");
    
    strcpy(pos.destination,"C1");
    pos = navigation(pos);
    strcpy(pos.destination,Car_Assembly_Location);
    printf("arrived to car\n");
    // light led up to show step is done
    pos= navigation(pos);

    return pos;
}
struct travel Upper_Right_Wheel(struct travel pos){}
struct travel Upper_left_Wheel(struct travel pos){}
struct travel Lower_Right_Wheel(struct travel pos){}
struct travel Lower_Left_Wheel(struct travel pos){}
struct travel Trailer_assembly(struct travel pos)
{
    strcpy(pos.destination,Trailer_Location);
}

struct travel Cabin_assembly(struct travel pos)
{
    strcpy(pos.destination,Cabin_Location);
}

struct travel Rack_assembly(struct travel pos)
{
    strcpy(pos.destination,Rack_Location);
}

struct travel navigation(struct travel pos)
{
    // move the bot as long as the position is not the destination
    while( strcmp(pos.current_position,pos.destination) )
    {
        // check if the bot is in the start position
        if ( !strcmp(pos.current_position,"A0") && !strcmp(pos.previous_position,"A0") )
        {
            printf("Start Position\n");
            printf("move forward\n");
            Line_Following();
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
                if ( pos.previous_position[1] > pos.current_position[1])
                {
                    if (pos.current_position[0] > pos.destination[0])
                    {
                        printf("Turn right\n");
                        /*  Move forward to next junction */
                        Line_Following();
                    }
                    else if ( pos.current_position[0] < pos.destination[0] )
                    {
                        printf("Turn left\n");
                        /*  Move forward to next junction */
                        Line_Following();
                    }
                    
                    pos = Update_Forward_Position(pos);
                }
                else if ( pos.previous_position[1] < pos.current_position[1] )
                {
                    if (pos.current_position[0] < pos.destination[0])
                    {
                        printf("Turn right\n");
                        /*  Move forward to next junction */
                        Line_Following();
                    }
                    else if ( pos.current_position[0] > pos.destination[0] )
                    {
                        printf("Turn left\n");
                        /*  Move forward to next junction */
                        Line_Following();
                    }
                    
                    pos = Update_Forward_Position(pos);
                }
                else
                {
                    printf("forward\n");
                    pos = Update_Forward_Position(pos);
                }                

            }
            
            // rows matching
            else if (pos.current_position[0] == pos.destination[0])
            {
                printf("rows...%i\n", pos.previous_position[0] < pos.current_position[0]);
                if ( pos.previous_position[0] < pos.current_position[0] )
                {
                    if ( pos.current_position[1] < pos.destination[1] )
                    {
                        /* e.g d3 -> d4  from c3*/
                        printf("Turn left\n");
                        /*  move forward to junction    */
                        pos = Forward_Row_Update(pos);
                        printf("previousss %s, new  %s destination %s\n",pos.previous_position,pos.current_position,pos.destination);

                    }
                    else if ( pos.current_position[1] > pos.destination[1] )
                    {
                        /* e.g d3 to d2 from c3*/
                        printf("Turn right \n");
                        pos = Forward_Row_Update(pos);
                        printf("previousss %s, new  %s destination %s\n",pos.previous_position,pos.current_position,pos.destination);
                        /*  move forward to junction    */

                    }
                }
                else if ( pos.previous_position[0] >  pos.current_position[0] )
                {
                    if ( pos.current_position[1] > pos.destination[1] )
                    {
                        /* e.g C2 -> C1  from D2*/
                        printf("Turn left\n");
                        /*  move forward to junction    */
                        pos = Forward_Row_Update(pos);
                        printf("previousss %s, new  %s destination %s\n",pos.previous_position,pos.current_position,pos.destination);

                    }
                    else if ( pos.current_position[1] < pos.destination[1] )
                    {
                        /* e.g c2 to c3 from d2*/
                        printf("Turn rightssss \n");
                        pos = Forward_Row_Update(pos);
                        printf("previousss %s, new  %s destination %s\n",pos.previous_position,pos.current_position,pos.destination);

                        /*  move forward to junction    */

                    }
                }
                else
                {
                    // forward runs
                    pos = Forward_Row_Update(pos);
                    printf("previouss %s, new  %s destination %s\n",pos.previous_position,pos.current_position,pos.destination);


                }
            
            }
            // strcpy(pos.current_position,pos.destination);

            // nothing matches
            else
            {
                // priority is rows to match thus ensure columns match first
                if ( pos.current_position[0] < pos.destination[0] )
                {
                    // check orientation
                    if ( pos.previous_position[0] == pos.current_position[0] )
                    {}
                }
                else if ( pos.current_position[0] > pos.destination[0] )
                {
                    // check orientation
                }
            }
        }
    }
    printf("Arrived. \n");

    return pos;
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
        
        else if ( !strcmp(positions[matrice_index][i],"99") )
        {
            printf("No way\n");
        }
        
        // get index
        else if ( !strcmp(positions[matrice_index][i] , pos.current_position) )
        {
            strcpy(pos.previous_position,pos.current_position);

            // going
            if ( pos.current_position[0] > pos.destination[0] )
            {
                if (!strcmp(positions[matrice_index][i-1],"00"))
                {
                    strcpy(pos.current_position,positions[matrice_index][i-2]);
                }
                else
                {
                    strcpy(pos.current_position,positions[matrice_index][i-1]);
                }
            }
            else if ( pos.current_position[0] < pos.destination[0] )
            {
                if (!strcmp(positions[matrice_index][i+1],"00"))
                {
                    strcpy(pos.current_position,positions[matrice_index][i+2]);
                }
                else
                {
                    strcpy(pos.current_position,positions[matrice_index][i+1]);
                }
            }   
            break;
        }
    }
    printf("previous %s, new  %s destination %s\n",pos.previous_position,pos.current_position,pos.destination);   
    return pos;
}

struct travel Forward_Row_Update (struct travel pos)
{
    int row_index = abs( (pos.current_position[0] - 'A' + 0) );
    // set the current position to the previous one
    strcpy(pos.previous_position,pos.current_position);
    for (int i = 0; i < 4; i++)
    {
        // get the index of the current position
        if ( !strcmp( pos.current_position, positions[i][row_index]))
        {
            // if going to the left
            if ( pos.current_position[1] < pos.destination[1])
            {
                if ( !strcmp(positions[i-1][row_index],"99") || !strcmp(positions[i-1][row_index],"00"))
                {
                    printf("No way\n");
                }
                else
                {
                    printf("forward\n");
                    strcpy( pos.current_position,  positions[i-1][row_index]);
                    break;
                }
            }

            // going right
            else if ( pos.current_position[1] > pos.destination[1])
            {
                if ( !strcmp(positions[i+1][row_index],"99") || !strcmp(positions[i+1][row_index],"00"))
                {
                    printf("No way\n");
                }
                else
                {
                printf("HAAA");
                    printf("forward\n");
                    strcpy( pos.current_position,  positions[i+1][row_index]);
                    break;
                }

            }
        }
        printf("position %s",pos.current_position);
        // position
    }
    return pos;
}
