#include <stdio.h>

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
            if (array[j] < array[j-1])
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
            if (array[k] > array[j])
            {
                k   = j;
            }
        }

        exchange(&array[i], &array[k]);     
    }
}


void 
output(int array[], int len)
{
    int i;

    for (i = 0; i < len; i++)
    {
        printf("%d ", array[i]);
    }
    
    printf("\n");
}


int
main(void)
{
    int array[10] = {3, 6, 5, 9, 8, 7, 1, 10, 4, 9};

    output(array, 10);

    //bublesort(array, 10);
    selectsort(array, 10);

    output(array, 10);

    return 0;
}