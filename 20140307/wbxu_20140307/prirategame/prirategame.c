#include <stdio.h>

#define N       6
#define MONEY   100

int array[N] = {0};


void
output(int n)
{
    int i;

    for (i = n - 1; i >= 0; i--)
    {
        printf("%d ", array[i]);
    }
    printf("\r\n");
}

void
divider(int n)
{
    int support;    //number of people we must get support
    int min;        //smallest money those people get
    int index;      //which people get the smallest money.
    int own;        //money ourself get
    int move;
    int i;

    //todo
    int arychanged[N] = {-1};
    int j = 0;
    int k;


    if (1 == n || 2 == n)
    {
        array[0] = 100;

    }
    else if (3 == n)
    {
        array[2] = 100;
        array[1] = 0;
        array[0] = 0;
        
    }
    else
    {
        //thinking n-1's solution
        divider(n - 1);

        own = MONEY;

        /*
        now for n:
        array[n-1] is for self
        array[n-2] is 0
        
        must get (n-1-0+1)/2 + 1=n/2 + 1 supports(contains ourself) 
        so n/2 supports from array[n-3, n-4,...0]
        */
        array[n - 2] = 0;
        
        support = n / 2;
        
        //拉拢前轮获得利益最小者
        move = 0;
        while (support > 0)
        {
            //find the smallest
            min   = array[n - 3 - move];
            index = n - 3 - move;
            
            for (i = n - 3 - move; i >= 0; i--)
            {
                if (array[i] < min)
                {
                    index   = i;
                    min = array[i];
                }
            }
            
            //get the support of the smallest
            array[index] += 1;
            support -= 1;
            
            own -= array[index];
            
            move += 1;

            //record those changed
            arychanged[j++] = index;

        }//end for while(support != 0)

#if 0
        //now clear those do not make contribution, those do not change
        for (i = n - 3; i >= 0; i--)
        {
            //find whether changed
            for (j = 0; arychanged[j] != -1; j++)
            {
                if (arychanged[j] != i)
                {
                    continue;
                }
            }

            //not changed
            if (-1 == arychanged[j])
            {
                array[i] = 0;
            }
            
        }

#endif

        array[n - 1] = own;
    }  

    output(n);
}

int
main(void)
{
    divider(N);


    return 0;
}