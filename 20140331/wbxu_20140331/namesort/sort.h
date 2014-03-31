/*
Function: selectsort with callback function to deal with type irrelevant array.

Param   : base is the base address of those elements you want to sort.
          num  is the number of all the element
          width is the sizeof of element
          compare is used to determined relationship between two elements.
*/
void
selectsort(void *base, size_t num, size_t width,
           int (*compare)(void const *, void const *));
