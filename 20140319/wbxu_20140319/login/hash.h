/*
Function: calculate hash for string[length], with >>m | >>n
*/
unsigned long 
ror_hash(const char string[], size_t length, int m, int n);

/*
Function: decode the key code

  Param   : length = strlen(szInput);
*/
char
algorithm(char szIput[], int length, char code, int i);
