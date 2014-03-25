#include <stdio.h>
#include <string.h>

void
getinput(char *szinput)
{
    printf("Please enter the name u want to search:\r\n");
    scanf("%15s", szinput);
}

void
output(int index)
{
    if (-1 == index)
    {
        printf("Not found\r\n");
    }
    else
    {
        printf("Located at %d\r\n", index);
    }
}

/*
Function: locate index of szinput within name.
Return  : -1 non-exist, otherwise the index
*/
int
locate(char **name, char *szinput)
{
    char **p = NULL;
    int index = -1;

    /*Take care that we add NULL into name to make it easy.*/
    for (p = &name[0]; *p != NULL; p++ )
    {
        if (0 == strcmp(*p, szinput))
        {
            index = p - &name[0];
            break;
        }
    }

    return index;
}

int
main(void)
{
    char *name[] = {"Join", "Mary", "Lily", "Bob", "Williams", "White", NULL};
    char szinput[16] = {0};
    int index;

    getinput(szinput);

    index = locate(name, szinput);

    output(index);

    return 0;
}