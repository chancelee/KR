#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAX 10

/*
Function: exchange two int pointed by pi and pj
*/
void
exchange(void *elm1, void *elm2, size_t width)
{
    void *tmp = malloc(width);

    memcpy(tmp, elm1, width);
    memcpy(elm1, elm2, width);
    memcpy(elm2, tmp, width);   
   
}

/*
Function: compare two string

Return  : + for *x > *y, 0 for equal, - for *x < *y
*/
int
compare_str(void const *x, void const *y)
{
    return strcmp((char *)(x), (char *)(y));
}

/*
Function: compare two int

Return  : 1 for *x > *y, 0 for equal, -1 for *x < *y
*/
int
compare_int(void const *x, void const *y)
{
    int i, j;

    i = *(int *)x;
    j = *(int *)y;

    if (i > j)
    {
        return 1;
    }
    else if (i == j)
    {
        return 0;
    }
    else
    {
        return -1;
    }
    
}

/*
Function: selectsort with callback function to deal with type irrelevant array.

Param   : base is the base address of those elements you want to sort.
          num  is the number of all the element
          width is the sizeof of element
          compare is used to determined relationship between two elements.
*/
void
selectsort(void *base, size_t num, size_t width,
           int (*compare)(char const *, char const *))
{
    size_t i, j;

    size_t k;      //for min 

    for (i = 0; i < num; i++)
    {
        k = i;
        
        for (j = i+1; j < num; j++)
        {
            if (compare((char *)((char *)base + k * width), 
                        (char *)((char *)base + j * width)
                        ) > 0)
            {
                k   = j;
            }
        }

        //exchange((void *)&base[i], &base[k]);     
        exchange((char *)((char *)base + i * width),
                (char *)((char *)base + k * width),
                width);
    }
}


/*
    Test for callback with selectsort, can deal with int, strings
*/
int
main(void)
{
    int iary[MAX]     = {8, 7, 3, 1, 10, 4, 2, 5, 6, 9};
    char *strary[MAX] = {
        "abcd", "abc", "bcda", "cd", "ca", "ad", "ac", "abcd", "bcda", "d"
    };
    
    selectsort((void *)iary, sizeof(iary) / sizeof(iary[0]), sizeof(iary[0]), compare_int);

    //bug when dealing with string
    selectsort((void *)strary, sizeof(strary) / sizeof(strary[0]), sizeof(strary[0]), compare_str);


    return 0;
}