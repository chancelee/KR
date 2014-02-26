#include <stdio.h>
#include <stdlib.h>

#define LENGTH  54

void swap(int *array, int i, int j)
{
	int tmp;

	tmp = array[i];
	array [i] = array[j];
	array[j] = tmp;
}

/*
 we use 2 sets: {unhandled}, {handled}
   1) initially, {unhandled} = {all elements in array},  {handled} = null
   2) every time we select any one of {unhandled}, and move it into handled
   3) until {unhandled}  is empty
   4) as for storage, we treat former part of the array as unhandled,  the remain as handled.
	  we just use one pointer to split them.

   a0 a1 a2 a3 ..... a51 a52 a53
					  p

   then {unhandled} = {a0, a1,..., a50}
	    {handled} = {a52, a53}
	
	now we can select any one of {unhandled}, and swap it with a51, that is ok.
*/
void 
Shuffle(int *array, int length)
{
	int i;			

	int handled;	//to split {unhandled} and {handled}

	handled = length - 1;


	for( ; handled != 0; handled--)
	{
		i = rand() % handled; //select any one of {0,1,2, ..., handled-1}

		swap(array, i, handled);	
	}
	
} 

int 
main(void)
{
	int element[LENGTH];
	int *pi;
	int i;

	//init the element[] = {1,2,3,...,LENGTH}
	for(pi = element, i = 1; pi < element + LENGTH; pi++)
	{
		*pi = i++;
	}

	//The main part
	Shuffle(element, LENGTH);
		
	//output
	for(pi = element, i = 1; pi < element + LENGTH; pi++)
	{
		printf("%d ", *pi);
	}
		
	printf("\n");

	
	return 0;
}