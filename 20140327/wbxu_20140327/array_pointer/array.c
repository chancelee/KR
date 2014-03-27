#include <stdio.h>

#define COUNT   20

/*
Question from <Pointers on C> 8.7.13
*/
void
verify_array3(void)
{
    int iary[4][5][3];
    int *ip;
    int i;

    for (ip = &iary[0][0][0], i = 0; ip <= &iary[3][4][2]; ip++, i++ )
    {
        *ip = i;
    }

    //= iary[0];
    *iary;

    //= iary[2]
    *(iary + 2);

    //iary[1] + 4
    *(iary +1) + 4;

    //iary[3][1][2]
    *(*(*(iary + 3) + 1) + 2);

    //iary[0][1][2]
    *(*(*iary + 1) + 2);

    //iary[0][0][2]
    *(**iary + 2);

    //iary[0][1][0]
    **(*iary + 1);
    
    //iary[0][0][0]
    ***iary;

}

/*
Question from <Pointers on C> 8.7.11
*/
void
verify_array4(void)
{
    int iary[4][2][3][6];
    int i;

    // &iary[0]   int[2][3][6]
     i = (int)iary;

    // &iary[2] = &iary[2][0]  (They do differ)
    // (int)iary + 2 * sizeof(int[2][3][6])  = (int)iary + 2 * sizeof(iary[0])
    i = (int)(iary + 2);

    // *(iary + 3)  = &iary[3][0]  
    // (int)iary + 3 * sizeof(int[2][3][6]) + 0 * sizeof(int[3][6]) 
    //= (int)iary + 3 * sizeof(iary[3]) + 0 * sizeof(iary[3][0])
    i = (int)iary[3];

    // *(iary + 2) - 1 = &iary[2][0] - 1 * sizeof(iary[2][0]) = &iary[1][1]
    // (int)iary + 1 * sizeof(int[2][3][6]) + 1 * sizeof(int[3][6])
    i = (int)(iary[2] - 1);

    // = (*(iary + 2))[1] = *((*(iary + 2)) + 1)
    // &iary[2][1][0]
    // (int)iary + 2 * sizeof(int[2][3][6]) + 1 * sizeof(int[3][6]) + 0 * sizeof(int[6])
    //=(int)iary + 2 * sizeof(iary[2]) + 1 * sizeof(iary[2][1]) + 0 * sizeof(iary[2][1][0])
    i = (int)(iary[2][1]);

    //=(*(iary + 1))[0] + 1 = *((*(iary + 1)) + 0) + 1
    // = &iary[1][0][0] + 1 * sizeof(iary[1][0][0]) 
    i = (int)(iary[1][0] + 1);

    // = (*(iary + 1))[0][2] = (*((*(iary+1))+0))[2] = *((*((*(iary+1))+0)) + 2)
    // = &iary[1][0][2][0]
    // = (int)iary + 1 * sizeof(iary[1]) + 0 * sizeof(iary[1][0]) + 2 * sizeof(iary[1][0][2])
    i = (int)(iary[1][0][2]);


    //= (*(iary + 0))[1][0] + 2 = (*iary)[1][0] + 2
    //= (*((*(iary+0))+1))[0] + 2 = (*((*iary)+1))[0] + 2
    //= *((*((*(iary+0))+1)) + 0) + 2
    // = (int)&iary[0][1][0][0] + 2 * sizeof(iary[0][1][0][0])
    i = (int)(iary[0][1][0] + 2);

    //=(*(iary+3))[1][2][5]
    //=(*((*(iary+3)) + 1))[2][5]
    //=(*((*((*(iary+3)) + 1)) + 2))[5]
    //=(*((*((*((*(iary+3)) + 1)) + 2)) + 5))
    i = (int)iary[3][1][2][5];


}


/*
Questions from <Pointer on C> 8.7.10
*/
void
verify_array2(void)
{
    int iary[4][2];
    int i;

    //addr(iary)
    i = (int)iary;

    // = (int)iary + 2 * sizeof(int[2]) = (int)iary + 2 * sizeof(iary[0])
    i = (int)(iary + 2);

    // = *(iary + 3)  = &iary[3][0]
    i = (int)(iary[3]);

    // = *(iary + 2) - 1 = &iary[2][0] - 1 = (int)&iary[2][0] - 1 * sizeof(iary[2][0]) = &iary[1][1]
    i = (int)(iary[2] - 1);

    // = &iary[2][0]
    i = (int)(&iary[1][2]);

    //
    i = (int)(&iary[2][0]);
}


/*
Questions from <Pointers on C> 8.7.1
*/
void
verify_array1(void)
{
    int iary[COUNT] = {0};
    int *ip;
    int i;
    
    for (i = 0; i < COUNT; i++)
    {
        iary[i] = (i + 1) * 10;
    }
    
    ip = iary + 3;

    /*Here we go, debug all these*/
    
    //iary = 1244892   0x0012fedc
    i = (int)iary;

    // 50
    i = iary[4];

    // 1244892 + 4 * sizeof(int)
    i = (int)(iary + 4);

    // 10 + 4
    i = *iary + 4;

    // = iary[4]   50
    i = *(iary + 4);

    //it depends, here is the last result of i, 50
    i = iary[-2];

    // 1244892  &iary[0], iary
    //  ebp - 4 * 20 = ebp - 0x50h
    i = (int)&iary;

    // iary + 4
    i = (int)&iary[4];

    // Take Care!!!
    // ebp  - 4 * 20 + 4 * sizeof(int[20]) = ebp - 4 * 20 + 4 * 4 * 20 = ebp + 3 * 4 * 20 = ebp + 0x0F0h
    // this is different from ary + 4
    i = (int)(&iary + 4);

    // = &i
    i = (int)&iary[-2];


    /*here we go, ip */
    // = iary + 3   1244892 + 3 * sizeof(int)
    i = (int)ip;

    // = iary[3 + 4]  80
    i = ip[4];

    // iary + 3 + 4
    i = (int)(ip + 4);

    // 40 + 4
    i = *ip + 4;

    // = ip[4] = iary[7] = 80
    i = *(ip + 4);

    // = iary[3 - 2] = iary[1] = 20
    i = ip[-2];

    // ((int)&iary) - 1 * 4 = 1244892 - 4
    i = (int)&ip;

    // = ip + 4
    i = (int)&ip[4];

    //iary - 1 + 4 = iary + 3
    //Take Care!!!
    i = (int)(&ip + 4);

    //= iary + 3 - 2 = iary + 1 
    i = (int)&ip[-2];

}

int
main(void)
{
    verify_array1();

    verify_array2();

    verify_array4();

    verify_array3();

    return 0;
}