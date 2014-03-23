#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <locale.h>

void
test_printf()
{
    //works well
    printf("printf 1�������\r\n");

    getchar();
    
    //failed, if we set locale to 437 (America)
    system("chcp 437");
    printf("print 2�������\r\n");

    getchar();

    //ok, recover into 936 (Simple Chinese)
    system("chcp 936");
    printf("print 3�������\r\n");

    getchar();

    //So, we can see that the chcp matters
}

void
test_wprintf()
{
    //this never works 
    wprintf(L"wprint 0 �������\r\n");

    getchar();

    //now ok, by setting the locale
    setlocale(LC_ALL, "chs");
    wprintf(L"wprint 1�������\r\n");

    getchar();

    //again, failed, if we change the language set to 437 (America)
    system("chcp 437");
    setlocale(LC_ALL, "chs");
    wprintf(L"wprint 2�������\r\n");

    getchar();

    //ok now, if we change the language set to 936 (Simple Chinese)
    system("chcp 936");
    setlocale(LC_ALL, "chs");
    wprintf(L"wprint 3�������\r\n");

    getchar();

    //not now, if we change the locale to english
    setlocale(LC_ALL, "english");
    wprintf(L"wprint 4�������\r\n");

    getchar();

    //not now, if we change the locale to english
    setlocale(LC_ALL, "chs");
    wprintf(L"wprint 5�������\r\n");

    //so, setlocale and chcp xx both matters

}

int
main(void)
{
    //test_printf();

    test_wprintf();

    return 0;
}