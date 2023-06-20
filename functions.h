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
struct travel Upper_Right_Wheel(struct travel pos)
{
    return pos;
}

struct travel Upper_left_Wheel(struct travel pos)
{
    return pos;
}

struct travel Lower_Right_Wheel(struct travel pos)
{
    return pos;
}

struct travel Lower_Left_Wheel(struct travel pos)
{
    return pos;
}

struct travel Trailer_assembly(struct travel pos)
{
    strcpy(pos.destination,Trailer_Location);
    return pos;
}

struct travel Cabin_assembly(struct travel pos)
{
    strcpy(pos.destination,Cabin_Location);
    return pos;
}

struct travel Rack_assembly(struct travel pos)
{
    strcpy(pos.destination,Rack_Location);
    return pos;
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
            // Line_Following();
            strcpy(pos.current_position,"A1");
        }

        //  Enter matrice coordinates
        else
        {   
            // Check for alignment of coordinates
            
            // columns matching
            if (pos.current_position[1] == pos.destination[1])
            {
                // check from where the bot is from
                if ( pos.previous_position[1] > pos.current_position[1])
                {
                    if (pos.current_position[0] > pos.destination[0])
                    {
                        // if column id is greater turn the right direction
                        printf("Turn right\n");
                        printf("Move to the next junction\n");
                        // Line_Following();
                    }
                    else if ( pos.current_position[0] < pos.destination[0] )
                    {
                        printf("Turn left\n");
                        printf("Move to the next junction\n");
                        /*  Move forward to next junction */
                        // Line_Following();
                    }
                    
                    pos = Update_Forward_Position(pos);
                }
                else if ( pos.previous_position[1] < pos.current_position[1] )
                {
                    if (pos.current_position[0] < pos.destination[0])
                    {
                        printf("Turn right\n");
                        printf("Move to the next junction\n");
                        /*  Move forward to next junction */
                        // Line_Following();
                    }
                    else if ( pos.current_position[0] > pos.destination[0] )
                    {
                        printf("Turn left\n");
                        printf("Move to the next junction\n");
                        /*  Move forward to next junction */
                        // Line_Following();
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
                        printf("Move to the next junction\n");
                        /*  move forward to junction    */
                        pos = Forward_Row_Update(pos);
                        printf("previousss %s, new  %s destination %s\n",pos.previous_position,pos.current_position,pos.destination);

                    }
                    else if ( pos.current_position[1] > pos.destination[1] )
                    {
                        /* e.g d3 to d2 from c3*/
                        printf("Turn right \n");
                        printf("Move to the next junction\n");
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
                    printf("Move forward out of junction\n");
                    printf("Move to the next junction\n");
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
                    if ( i - 3 >= 0 )
                    {
                        if ( !strcmp(positions[matrice_index][i-3],"99") )
                        {
                            pos = Row_Transversion(pos);
                        }
                    }
                }
                else
                {
                    strcpy(pos.current_position,positions[matrice_index][i-1]);
                    if ( i - 2 >= 0 )
                    {
                        if ( !strcmp(positions[matrice_index][i-2],"99") )
                            {
                                pos = Row_Transversion(pos);
                            }
                    }
                }
            }
            else if ( pos.current_position[0] < pos.destination[0] )
            {
                if (!strcmp(positions[matrice_index][i+1],"00"))
                {
                    strcpy(pos.current_position,positions[matrice_index][i+2]);

                    if ( i + 3  < 4 )
                    {
                        if ( !strcmp(positions[matrice_index][i+3],"99") )
                            {
                                pos = Row_Transversion(pos);
                            }  
                    }
                }
                else
                {
                    strcpy(pos.current_position,positions[matrice_index][i+1]);
                    
                    if ( i + 2 < 4 )
                    {
                        if ( !strcmp(positions[matrice_index][i+2],"99") )
                            {
                                pos = Row_Transversion(pos);
                            }
                    } 
                }
            }   
            break;
        }
    }
    printf("previous position %s, new position %s destination %s columns\n",pos.previous_position,pos.current_position,pos.destination);   
    return pos;
}

struct travel Forward_Row_Update (struct travel pos)
{
    // printf("indexxing...\n");
    int row_index = abs( (pos.current_position[0] - 'A' + 0) );

    // set the current position to the previous one
    strcpy(pos.previous_position,pos.current_position);

    for (int i = 0; i < 4; i++)
    {
        // get the index of the current position
        if ( !strcmp( pos.current_position, positions[i][row_index]))
        {
            // if going to the left
            // get the current position
            if ( pos.current_position[1] < pos.destination[1])
            {
                    // printf("forward\n");
                    // set the current position
                    strcpy( pos.current_position,  positions[i-1][row_index]);

                    printf("New position is %s\n",pos.current_position);
                    // check the next position
                    // confirm one can continue moving forward in the row
                    if ( i-2 >= 0 )
                    {
                        if ( !strcmp(positions[i-2][row_index],"99") || !strcmp(positions[i-2][row_index],"00"))
                            {
                                pos = Column_Transversion(pos);
                                // printf("No way\n");
                            }
                    }
                    break;
            }

            // going right
            // get the current position
            else if ( pos.current_position[1] > pos.destination[1])
            {
                printf("forward\n");
                strcpy( pos.current_position,  positions[i+1][row_index]);

                // check the next position
                if ( i + 2 < 4 )
                {
                    if ( !strcmp(positions[i+2][row_index],"99") || !strcmp(positions[i+2][row_index],"00"))
                    {
                        pos = Column_Transversion(pos);
                    }
                }
                break;
            }
        }
        // printf("position %s",pos.current_position);
        // position
    }
    return pos;
}

struct travel Row_Transversion (struct travel pos)
{

    if ( pos.previous_position[0] < pos.current_position[0] )
    {
        if ( pos.current_position[1] < pos.destination[1] )
        {
            /* e.g d3 -> d4  from c3*/
            printf("Turn left\n");
            printf("Move to the next junction\n");
            /*  move forward to junction    */
            pos = Forward_Row_Update(pos);
            printf("previousss %s, new  %s destination %s\n",pos.previous_position,pos.current_position,pos.destination);

        }
        else if ( pos.current_position[1] > pos.destination[1] )
        {
            /* e.g d3 to d2 from c3*/
            printf("Turn right \n");
            printf("Move to the next junction\n");
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
            printf("Move to the next junction\n");
            /*  move forward to junction    */
            pos = Forward_Row_Update(pos);
            printf("previousss %s, new  %s destination %s\n",pos.previous_position,pos.current_position,pos.destination);

        }
        else if ( pos.current_position[1] < pos.destination[1] )
        {
            /* e.g c2 to c3 from d2*/
            printf("Turn rightssss \n");
            printf("Move to the next junction\n");
            pos = Forward_Row_Update(pos);
            printf("previousss %s, new  %s destination %s\n",pos.previous_position,pos.current_position,pos.destination);

            /*  move forward to junction    */

        }
    }
    else
    {
        // forward runs
        printf("Forward ot of junction\n");
        printf("Move to the next junction\n");
        pos = Forward_Row_Update(pos);
        printf("previoussS %s, new  %s destination %s\n",pos.previous_position,pos.current_position,pos.destination);
    }
// }
    return pos;
}

struct travel Column_Transversion (struct travel pos)
{
        // check from where the bot is
    if ( pos.previous_position[1] > pos.current_position[1])
    {
        if (pos.current_position[0] > pos.destination[0])
        {
            // if column id is greater turn the right direction
            printf("Turn right\n");
            printf("Move to the next junction\n");
            // Line_Following();
        }
        else if ( pos.current_position[0] < pos.destination[0] )
        {
            printf("Turn left\n");
            printf("Move to the next junction\n");
            /*  Move forward to next junction */
            // Line_Following();
        }
        
        pos = Update_Forward_Position(pos);
    }
    else if ( pos.previous_position[1] < pos.current_position[1] )
    {
        if (pos.current_position[0] < pos.destination[0])
        {
            printf("Turn right\n");
            printf("Move to the next junction\n");
            /*  Move forward to next junction */
            // Line_Following();
        }
        else if ( pos.current_position[0] > pos.destination[0] )
        {
            printf("Turn left\n");
            printf("Move to the next junction\n");
            /*  Move forward to next junction */
            // Line_Following();
        }
        
        pos = Update_Forward_Position(pos);
    }
    else
    {
        printf("forward out of junction\n");
        printf("Move to the next junction\n");
        pos = Update_Forward_Position(pos);
    }                

    return pos;
}


struct travel New_Navigation(struct travel pos)
{

    while( strcmp(pos.current_position,pos.destination) )
    {
        if ( !strcmp(pos.current_position,"A0") && !strcmp(pos.previous_position,"A0") )
        {
            printf("Start Position\n");
            printf("move forward\n");
            // Line_Following();
            strcpy(pos.current_position,"A1");
            printf("Now at %s\n",pos.current_position);
        }
        else if (pos.current_position[1] == pos.destination[1])
        {
            printf("Moving through columns\n\n");
            pos = Column_Transversion(pos);
        }
        else if (pos.current_position[0] == pos.destination[0] || pos.current_position[0] != pos.destination[0])
        {
            printf("Moving through rows\n\n");
            pos = Row_Transversion(pos);
        }
    }
    printf("Arrived\n");
    return pos;
}