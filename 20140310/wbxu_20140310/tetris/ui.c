#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "ui.h"
#include "logic.h"

//
void
DrawBackGround(void)
{
    int i, j;

    for (i = 0; i < GAME_ROWS; i++)
    {
        for (j = 0; j < GAME_COLS; j++)
        {
            if (GAME_WALL == g_BackGround[i][j] )
            {
                printf("%s", "¡ö");
            }//wall
            else
            {
                printf("%s", "¡õ");
            }//not wall
        }
        
        printf("\r\n");
    }
}

/*
Function: change background according to brick, set specific position as wall
*/
void
ChangeBackGround(int wall)
{
    int i, j;
    
    for (i = 0; i < BRICK_ROWS; i++)
    {
        for (j = 0; j < BRICK_COLS; j++)
        {
            if (GAME_WALL == g_Brick[BRICK_START + i][j])
            {
                //change g_BackGround
                g_BackGround[g_nCurY + i][g_nCurX + j] = wall;
            }
        }
    }//end for change g_BackGround
}

/*
Function: draw brick
*/
void
DrawBrick(void)
{
    /*we need to change g_BackGround[][] according to new brick
    new brick is determined by (g_nType, g_nRotate, g_nCurX, g_nCurY)
    */
    ChangeBackGround(GAME_WALL);

    system("cls");

    //already changed background contains brick
    DrawBackGround();

    //now restore the background if not fixed
    if (0 == g_nFixed )
    {
        ChangeBackGround(GAME_NOT_WALL);
    }    
}

/*
Function: display score
*/
void
DisplayScore()
{
    printf("Score: %d\r\n", g_nScore);
}


/*
Function: get user input, to move left/right/down/rotate
*/
void
GetInput(void)
{
    char ch;
    
    ch = getch();
    ch = toupper(ch);

    switch (ch)
    {
    case 'W':
        {
            MoveUp();
            break;
        }

    case 'S':
        {
            MoveDown();
            break;
        }

    case 'A':
        {
            MoveLeft();
            break;
        }

    case 'D':
        {
            MoveRight();
            break;
        }

    default:
        {
            //none
            break;
        }       
        
    }    
}
