#include <stdio.h>

int const g_nTest = 0x11223344;

void
test_const(void)
{
//#define NORMAL
#ifdef NORMAL
    int i   = 0x1234;
    int *pi = NULL;

    pi = &i;
    *pi++ = 0;

#endif

//#define CONST_POINTER
#ifdef CONST_POINTER
    int const i = 0x1234;
    int const *pci = NULL;

    pci = &i;

    //pci++;       //ok, pci is a variable
    *pci = 0;    //error C2166: l-value specifies const object
                 //what pci points to, *pci is a const, cannot be changed.
#elifdef TEST
    int const i = 0x1234;
    int *pci = NULL;

    pci = &i;

    *pci = 0;       //this is ok, but not for global const, like case below GLOBAL


#endif

//#define POINTER_CONST
#ifdef POINTER_CONST
    int i = 0x1234;
    int * const cpi = &i;

    *cpi = 0;   //what cpi points to, *cpi is a variable
    cpi++;      //cpi is a const, cannot be changed  
                //error C2166: l-value specifies const object

#endif

#define GLOBAL
#ifdef GLOBAL
    int *pci = &g_nTest;   //cause warning in c, 
                            //int const g_nTest
                            //int const *pci = &g_nTest; is ok

    *pci = 0;               //this will cause 0xc0000005  
                            //but we can change the characteristics in .rdata

    
#endif



    

}

int
main(void)
{
    test_const();

    return 0;
}