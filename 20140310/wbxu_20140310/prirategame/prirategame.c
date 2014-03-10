#include <stdio.h>
#include <math.h>

#define N       20
#define MONEY   100

int array[N] = {0};


void
output(int n)
{
    int i;

    for (i = n - 1; i >= 0; i--)
    //for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\t\t\t\t%d", n);
    printf("\r\n");
}

void
divider(int n)
{
    int support;    //number of people we must get support
    int min;        //smallest money those people get
    int index;      //which people get the smallest money.
    int own;        //money ourself get
    int i;

    unsigned changed = 0;

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
        while (support > 0)
        {
            //find the first unchanged as the smallest
            for (i = n - 3; i >= 0; i--)
            {
                if (0 == (changed & (unsigned)pow(2,i)))
                {
                    min   = array[i];
                    index = i;

                    break;
                }
            }
            
            //find the real unchanged smallest.            
            for (i = n - 3; i >= 0; i--)
            {
                //changed
                if (0 != (changed & (unsigned)pow(2,i)))
                {
                    continue;
                }
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

            //record those changed
            changed = changed | (unsigned)pow(2,index);


        }//end for while(support != 0)

        array[n - 1] = own;

        //now clear those not changed
        for (i = n - 3; i >= 0; i--)
        {
            //not changed
            if (0 == (changed & ((unsigned)pow(2,i))))
            {
                array[i] = 0;
            }
        }
    }  
    
    output(n);
}

int
main(void)
{
    divider(N);


    return 0;
}