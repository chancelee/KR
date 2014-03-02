#include <stdio.h>
#include <stdlib.h>

//for map
#define ROW         10
#define COL         10

//for start point
#define START_X     7
#define START_Y     2

//for end point
#define END_X       7
#define END_Y       6 


char map[ROW][COL] = {
    '1','1','1','1','1','1','1','1','1','1',
    '1','1','1','0','0','0','1','1','1','1',
    '1','1','1','0','1','1','1','1','1','1',
    '1','1','1','0','1','1','1','1','1','1',
    '1','1','1','0','0','0','0','1','1','1',
    '1','1','1','0','1','1','0','1','1','1',
    '1','1','1','0','1','1','0','1','1','1',
    '1','1','0','0','1','1','!','0','1','1',
    '1','1','1','1','1','1','1','1','1','1',
    '1','1','1','1','1','1','1','1','1','1'
};

void showmap()
{
    int i;
    int j;

    for ( i = 0; i < ROW; i++)
    {
        for ( j = 0; j < COL; j++)
        {
            printf("%c ", map[i][j]);
        }
        
        printf("\n");
    }
}

void 
maze(int x, int y)
{
    //
    system("cls");
    showmap();
    system("pause");

    //step into
    map[x][y] = '*';

    /*
    move like this way.
    */
    if( (END_X == x) && ( END_Y == y) )  //come to the end point
    {
        printf("Ok, you got it!\n");

        system("pause");

        return;
    }

    
    if( ('0' == map[x-1][y]) || ('!' == map[x-1][y]) )         //move up
    {
        maze(x-1, y);
    }
    
    if( ('0' == map[x+1][y]) || ('!' == map[x+1][y]))           //move down
    {
        maze(x+1, y);
    }
 
    if( ('0' == map[x][y-1]) || ('!' == map[x][y-1]))           //move left
    {
        maze(x, y-1);
    }
        
    if( ('0' == map[x][y+1]) || ('!' == map[x][y+1]))          //move right
    {
        maze(x, y+1);
    }
   
    //no way anymore, we need to go back.
    system("cls");
    showmap();
    system("pause");

    //step back
    map[x][y] = '#';
    
}

int
main(void)
{

    maze(START_X, START_Y);
    
    return 0;
}