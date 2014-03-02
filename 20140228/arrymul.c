#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//(10^n)! < 10^n*10^n*10^n..*10^n = 10^(n+n+..+n)=10^(n*10^n) 
#define VALUE   (10000)
#define MAX_A   (4*VALUE)

#define MAX_B   8

// C = A*B
int arryA[MAX_A] = {0};
int arryB[MAX_B] = {0};
int arryC[MAX_A] = {0};

int flag = 0;

/*
求arryA[]的后M位和arryB[]的后N位的乘积
利用3元一次方程

A[M] = (aM-1.. a2 a1 a0)
B[N] = (bN-1.. b2 b1 b0)

A*B 所得每个位的结果由如下的序列组成(b,a,w) 或者(b,a)w
其中b = (N-1, N-2, .. 0)
    a = (M-1, M-2, .. 0)
    w = (0,1) 或者(%,/)

表示某位的结果为:
1)当 w = 0 时，是(B[b]*A[a])%10
2)当 w = 1 时，是(B[b]*A[a])/10

个位：(0,0)%                                        0 = b + a + w
十位：(0,1)%, (0,0)/, (1,0)%                        1 = b + a + w
百位：(0,2)%, (0,1)/, (1,1)%, (1,0)/, (2,0)%        2 = b + a + w
千位：(0,3)%, (0,2)/, (1,2)%, (1,1)/, (2,1)%, (2,0)/, (3,0)%    3 = b + a + w

所以，过渡为求3元一次方程的解。
i = b + a + w
b = (N-1, N-2,...,0)
w = (0,1)
i = (M+N-1, M+N-2, ..,0)
a = i - b - w

arryS * arryB = arryD

*/
void
arryMul(int *arryS, int M, int N, int *arryD)
{
    int i;
    int a;
    int b;
    int w;
    int c;

    c = 0;

    arryD[MAX_A-1] = 0;

    // i = a + b + w, how many possible answers for a, b and w
    for( i = 0; i <= (M - 1 + N - 1 + 1); i++)
    {
        //printf("%d:  ", i);
        
        for( b = 0; b < N; b++)
        {    
            //a = (i-b) or (i-b-1), cannot smaller than 0
            if( i - b < 0)      
            {
                break;
            }

            for( w = 0; w <= 1; w++)
            {
                a = i - b - w;

                if( a < M && a >= 0)
                {
                    //printf("(%d %d %d), ", b, a, w);    
                    
                    if( 0 == w)   // %
                    {
                        arryD[MAX_A-1-i] += ((arryS[MAX_A-1-a] * arryB[MAX_B-1-b]) % 10);
                    }
                    else if( 1 == w)  // /
                    {
                        arryD[MAX_A-1-i] += ((arryS[MAX_A-1-a] * arryB[MAX_B-1-b]) / 10);
                    }

                    c += arryD[MAX_A-1-i] / 10;
                    arryD[MAX_A-1-i] %= 10;  
                }
            }//end for w
        }//end for b

        arryD[MAX_A-1-i-1] = 0;
        arryD[MAX_A-1-i-1] += c;
        c = 0;

        //printf("\n");
        //system("pause");
    }//end for i    
}

/*
Function: copy elements in arryC to arryA, the length is determined by M and N
          meanwhile, clear arryC, used for storing next result.
Param   : M for arryA's length, N for arryB's length

*/
void
copy(int M, int N)
{
    int i = 0;

    for( ; i <= M + N - 1; i++)
    {
        arryA[MAX_A-1-i] = arryC[MAX_A-1-i];
        arryC[MAX_A-1-i] = 0;
    }
}

/*
Function: how many valuable inters are stored in this array
Param   : pointer to this array, max length of array
Return  : num of valuable inters

  like arryB[8] = {0,0,0,1,2,3,0,0}  then len(arryB, 8) will be 5
*/
int 
len(int *arry, int max)
{
    int i = 0;
    
    while(*(arry + i) == 0)
    {
        i++;
    }
    
    return max - i;
}

void
output()
{
    int * arryD;

    int i;
    int j;  

    i = 0;
    j = 0;

    if( 0 == flag)
    {
        arryD = arryA;
    }
    else if( 1 == flag)
    {
        arryD = arryC;
    }

    //skip 0
    while(arryD[i] == 0)
    {
        i++;
    }
    printf("====\n");

    while( i < MAX_A)
    {
        printf("%d", arryD[i]);
        i++;
        j++;
    }
    printf("\n");
    printf("total: %d\n", j);
}

/*
Function: Convert the specific int num and store into arry[max]
          e.g num is 123, then arryB[MAX_B] = {0,0,0,0,0,1,2,3}
Param   : num
Return  : how many inters are stored.
*/
int
push(int *arry, int max, int num)
{
    int i;
    
    i = 0;
    
    
    while((num / 10))
    {
        arry[max - i - 1] = num % 10;
        num /= 10;

        i++;
    }
    
    arry[max - i - 1] = num;
    
    return i+1;
    
}

void
start(int n)
{
    int i;
    int len_B;
    int len_A;

    for( i = 1; i <= n; i++)
    {
        len_B = push(arryB, MAX_B, i);

        if(0 == flag)       
        {
            len_A = len(arryA, MAX_A);
            
            //read from arryA, write arryA * arryB to arryC
            arryMul(arryA, len_A, len_B, arryC);

            flag = 1;
        }
        else if( 1 == flag)
        {
            len_A = len(arryC, MAX_A);
            
            //read from arryC, write arryC * arryB to arryA
            arryMul(arryC, len_A, len_B, arryA);

            flag = 0;
        }   
        
        //copy(len_A, len_B);
    }
}


void
init(void)
{
    arryA[MAX_A - 1] = 1;
    arryB[MAX_B - 1] = 1;
}

int
main(void)
{
    clock_t begin, end1, end2;
    begin = clock();

    //
    init();

    start(VALUE);

    //about time
    end1 = clock();

    output();

    end2 = clock();

    printf("(%d)! info:\n", VALUE);
    printf("diff1 = %f\n diff2 = %f\n", (double)(end1-begin)/CLOCKS_PER_SEC, (double)(end2-begin)/CLOCKS_PER_SEC);


    return 0;
}