#include <stdio.h>

//defines direction
//#define DIR_X  (1)
//#define DIR_Y  (-1)

#define N 5

int array[N][N] = {0};

void
init(void)
{
    int i, j;
    
    for (i = 0; i < N; i++)
    {      
        for (j = 0; j < N; j++)
        {
            array[i][j] = 0;
        }
    }
}


void
output()
{
    int i, j;
    int sum;

    for (i = 0; i < N; i++)
    {
        sum = 0;

        for (j = 0; j < N; j++)
        {
            sum += array[i][j];

            printf("%d  ", array[i][j]);
        }
        printf("      %d", sum);
        printf("\r\n\r\n");
    }
}


/*
Function: ask for sudoku, if already used, then use the origin's up's space.
*/
//void
//sudoku2(void)
void
sudoku2(int DIR_X, int DIR_Y)
{
    int x, y;

    int tmpx, tmpy;
    
    int i;

    x = (N) - 1;
    y = (N) / 2;

    i = 1;

    array[x][y] = i;

    while (i++ < (N)*(N))
    {
        tmpx = x;
        tmpy = y;

        x = (x + (DIR_X)) % (N);

        y = (y + (DIR_Y)) % (N);

        if ( x < 0)
        {
            x += N;
        }

        if ( y < 0)
        {
            y += N;
        }

        //already used
        if (array[x][y] != 0)
        {
            //try array[tmpx - 1][tmpy]
            if (array[tmpx - 1][tmpy] != 0)
            {
                printf("sth wrong? \r\n");
            }
            else
            {
                x = tmpx - 1;
                y = tmpy;
            }
        }

        array[x][y] = i;           
    }
}


/*
Function: ask for sudoku, if already used, then use the already-used's up's space.
*/
void
//sudoku1(void)
sudoku1(int DIR_X, int DIR_Y)
{
    int x, y;
    
    int i;

    x = (N) - 1;
    y = (N) / 2;

    i = 1;

    array[x][y] = i;

    while (i++ < (N)*(N))
    {
        x = (x + (DIR_X)) % (N);

        y = (y + (DIR_Y)) % (N);

        if ( x < 0)
        {
            x += N;
        }

        if ( y < 0)
        {
            y += N;
        }

        //already used
        if (array[x][y] != 0)
        {
            x -= 1;
        }

        array[x][y] = i;           
    }
}


int
main(void)
{
    int i;
    int arydirection[4][2] = {
        {1, 1},
        {1, -1}, 
        {-1, 1}, 
        {-1, -1}
    };

    for (i = 0; i < 4; i++)
    {
        printf("----different direction-----\r\n\r\n");
        init();
        sudoku1(arydirection[i][0], arydirection[i][1]);
        output();
        
        printf("----different solution-----\r\n\r\n");
        
        init();
        sudoku2(arydirection[i][0], arydirection[i][1]);
        output();
    }

    return 0;
}