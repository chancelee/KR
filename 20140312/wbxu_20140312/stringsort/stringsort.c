#include <stdio.h>
#include <string.h>

#define N   10
#define MAX_INPUT   255

int iary[N];                //store the sequence 
char szary[N][MAX_INPUT];    //store the strings to sort
    

/*
Function: exchange two int pointed by pi and pj
*/
void
exchange( int *pi, int *pj)
{
    int tmp;

    tmp = *pi;
    *pi   = *pj;
    *pj   = tmp;
}


/*
Function: sort all elements within array[len] from little to large.

*/
void
bublesort(int array[],  int len)
{
    int i, j;

    int flag;   //whether swapped: 0 not, 1 yes.

    //to make array[i] be the i-st small number  
    for (i = 0; i < len; i++)
    {
        flag = 0;

        //deal with array[i, i+1, ..., len-1]
        for (j = len - 1; j > i; j--)
        {
            //if (array[j] < array[j-1])
            if (0 > strcmp(szary[iary[j]], szary[iary[j-1]]) )
            {
                exchange(&array[j], &array[j-1]);

                flag = 1;
            }
        }

        //no swap last time, so we leave.
        if (0 == flag)
        {
            break;
        }
    }
}

void
selectsort(int array[], int len)
{
    int i, j;

    int k;      //for min    

    for (i = 0; i < len; i++)
    {
        k = i;
        
        for (j = i+1; j < len; j++)
        {
            //if (array[k] > array[j])
            if (0 < strcmp(szary[iary[k]], szary[iary[j]]))
            {
                k   = j;
            }
        }

        exchange(&array[i], &array[k]);     
    }
}


void 
output(void)
{
    int i;

    for (i = 0; i < N; i++)
    {
        printf("%s ", szary[iary[i]]);
    }
    printf("\r\n");
}

void
input(void)
{
    int i;

    printf("Please Enter %d words to sort\r\n", N);

    for (i = 0; i < N; i++)
    {
        scanf("%s", szary[i]);
        
        //also init the iary
        iary[i] = i;
    }

}


int
main(void)
{
    input();    

    //bublesort(iary, N);
    selectsort(iary, N);

    output();

    return 0;
}