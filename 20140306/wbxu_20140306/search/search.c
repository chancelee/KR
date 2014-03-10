#include <stdio.h>

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

/*
Function: whether key exists in array[len], if so return index, else -1
Param   :
Return  : index if key exists, else -1

*/
int
binarysearch(int array[], int len, int key)
{
    int low, high, middle;

    int index = -1;

    for ( low = 0, high = len -1; low <= high; )
    {
        middle = (low + high) / 2;

        if (key < array[middle])
        {
            high = middle - 1;
        }
        else if (key > array[middle])
        {
            low = middle + 1;
        }
        else
        {
            index = middle;
            break;            
        }
    }

    return index;
}

int
main(void)
{
    int key;
    int index;

    int array[10] = {-1, 1, 20, 35, 49, 80, 81, 90, 98, 100};

    output(array, 10);

    key = 80;

    index = binarysearch(array, 10, key);
    if (-1 == index)
    {
        printf("Not found\n");
    }
    else
    {
        printf("%d is found at %d\n", key, index);
    }


    return 0;
}