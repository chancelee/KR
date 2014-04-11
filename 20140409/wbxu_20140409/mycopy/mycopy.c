#include <stdio.h>

void
usage(void)
{
    printf("e.g mycopy src.txt  dst.txt\r\n");
}

int
mycopy(char *filesrc, char *filedst)
{
    int result       = 1;
    FILE *fpsrc      = NULL;
    FILE *fpdst      = NULL;
    size_t nfsize    =  0;
    unsigned ncount  = 0;
    unsigned nremain = 0;
    char buf[8]      = {0};
    unsigned i       = 0;

    fpsrc = fopen(filesrc, "rb");
    if (NULL == fpsrc)
    {
        result = 0;
        goto ERROR_PROCESS;
    }

    fpdst = fopen(filedst, "wb");
    if (NULL == fpdst)
    {
        result = 0;
        goto ERROR_PROCESS;
    }

    //get file size, 
    fseek(fpsrc, 0, SEEK_END);
    nfsize = ftell(fpsrc);

    fseek(fpsrc, 0, SEEK_SET);

    //read 4 bytes every time.
    ncount  = nfsize / sizeof(int);
    nremain = nfsize % sizeof(int);
    
    //read and write now every 4 bytes
    for (i = 0; i < ncount; i++)
    {
        //这里可以进行函数封装
        if (1 != fread(buf, sizeof(int), 1, fpsrc))
        {
            if (0 == feof(fpsrc))
            {
                printf("Something wrong!\r\n");

                result = 0;
                goto ERROR_PROCESS;
            }
            else
            {
                printf("Come to end of file\r\n");

                result = 0;
                goto ERROR_PROCESS;
            }
        }

        fwrite(buf, sizeof(int), 1, fpdst);        
    }

    //the remaining
    if (1 != fread(buf, nremain, 1, fpsrc))
    {
        if (0 == feof(fpsrc))
        {
            printf("Something wrong!\r\n");

            result = 0;
            goto ERROR_PROCESS;
        }
        else
        {
            printf("Come to end of file\r\n");

            result = 0;
            goto ERROR_PROCESS;
        }
    }
    
    fwrite(buf, nremain, 1, fpdst);

ERROR_PROCESS:
    if (fpsrc)
    {
        fclose(fpsrc);
        fpsrc = NULL;
    }

    if (fpdst)
    {
        fclose(fpdst);
        fpdst = NULL;
    }

    return result;
}

int
main(int argc, char *argv[])
{
    int result = 0;

    if (argc != 3)
    {
        usage();
        return -1;
    }

    result = mycopy(argv[1], argv[2]);
    if (1 == result)
    {
        printf("已成功复制文件\r\n");
    }
    else
    {
        printf("发生错误\r\n");
    }
    
    return 0;
}