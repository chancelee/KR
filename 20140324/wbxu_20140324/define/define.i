#line 1 "e:\\programming\\git\\kr\\ph1\\n20140324\\wbxu_20140324\\define\\define.c"
#line 1 "e:\\program\\vc98\\include\\stdio.h"















#pragma once
#line 18 "e:\\program\\vc98\\include\\stdio.h"






#line 25 "e:\\program\\vc98\\include\\stdio.h"







#pragma pack(push,8)
#line 34 "e:\\program\\vc98\\include\\stdio.h"














#line 49 "e:\\program\\vc98\\include\\stdio.h"
#line 50 "e:\\program\\vc98\\include\\stdio.h"






#line 57 "e:\\program\\vc98\\include\\stdio.h"








#line 66 "e:\\program\\vc98\\include\\stdio.h"
#line 67 "e:\\program\\vc98\\include\\stdio.h"



typedef unsigned int size_t;

#line 73 "e:\\program\\vc98\\include\\stdio.h"




typedef unsigned short wchar_t;

#line 80 "e:\\program\\vc98\\include\\stdio.h"



typedef wchar_t wint_t;
typedef wchar_t wctype_t;

#line 87 "e:\\program\\vc98\\include\\stdio.h"
#line 88 "e:\\program\\vc98\\include\\stdio.h"









typedef char *  va_list;
#line 99 "e:\\program\\vc98\\include\\stdio.h"

#line 101 "e:\\program\\vc98\\include\\stdio.h"






#line 108 "e:\\program\\vc98\\include\\stdio.h"

#line 110 "e:\\program\\vc98\\include\\stdio.h"






























#line 141 "e:\\program\\vc98\\include\\stdio.h"





struct _iobuf {
        char *_ptr;
        int   _cnt;
        char *_base;
        int   _flag;
        int   _file;
        int   _charbuf;
        int   _bufsiz;
        char *_tmpfname;
        };
typedef struct _iobuf FILE;

#line 159 "e:\\program\\vc98\\include\\stdio.h"












#line 172 "e:\\program\\vc98\\include\\stdio.h"












#line 185 "e:\\program\\vc98\\include\\stdio.h"




























#line 214 "e:\\program\\vc98\\include\\stdio.h"
#line 215 "e:\\program\\vc98\\include\\stdio.h"





 extern FILE _iob[];
#line 222 "e:\\program\\vc98\\include\\stdio.h"









#line 232 "e:\\program\\vc98\\include\\stdio.h"


typedef __int64 fpos_t;







#line 243 "e:\\program\\vc98\\include\\stdio.h"
#line 244 "e:\\program\\vc98\\include\\stdio.h"


#line 247 "e:\\program\\vc98\\include\\stdio.h"




























 int __cdecl _filbuf(FILE *);
 int __cdecl _flsbuf(int, FILE *);




 FILE * __cdecl _fsopen(const char *, const char *, int);
#line 283 "e:\\program\\vc98\\include\\stdio.h"

 void __cdecl clearerr(FILE *);
 int __cdecl fclose(FILE *);
 int __cdecl _fcloseall(void);




 FILE * __cdecl _fdopen(int, const char *);
#line 293 "e:\\program\\vc98\\include\\stdio.h"

 int __cdecl feof(FILE *);
 int __cdecl ferror(FILE *);
 int __cdecl fflush(FILE *);
 int __cdecl fgetc(FILE *);
 int __cdecl _fgetchar(void);
 int __cdecl fgetpos(FILE *, fpos_t *);
 char * __cdecl fgets(char *, int, FILE *);




 int __cdecl _fileno(FILE *);
#line 307 "e:\\program\\vc98\\include\\stdio.h"

 int __cdecl _flushall(void);
 FILE * __cdecl fopen(const char *, const char *);
 int __cdecl fprintf(FILE *, const char *, ...);
 int __cdecl fputc(int, FILE *);
 int __cdecl _fputchar(int);
 int __cdecl fputs(const char *, FILE *);
 size_t __cdecl fread(void *, size_t, size_t, FILE *);
 FILE * __cdecl freopen(const char *, const char *, FILE *);
 int __cdecl fscanf(FILE *, const char *, ...);
 int __cdecl fsetpos(FILE *, const fpos_t *);
 int __cdecl fseek(FILE *, long, int);
 long __cdecl ftell(FILE *);
 size_t __cdecl fwrite(const void *, size_t, size_t, FILE *);
 int __cdecl getc(FILE *);
 int __cdecl getchar(void);
 int __cdecl _getmaxstdio(void);
 char * __cdecl gets(char *);
 int __cdecl _getw(FILE *);
 void __cdecl perror(const char *);
 int __cdecl _pclose(FILE *);
 FILE * __cdecl _popen(const char *, const char *);
 int __cdecl printf(const char *, ...);
 int __cdecl putc(int, FILE *);
 int __cdecl putchar(int);
 int __cdecl puts(const char *);
 int __cdecl _putw(int, FILE *);
 int __cdecl remove(const char *);
 int __cdecl rename(const char *, const char *);
 void __cdecl rewind(FILE *);
 int __cdecl _rmtmp(void);
 int __cdecl scanf(const char *, ...);
 void __cdecl setbuf(FILE *, char *);
 int __cdecl _setmaxstdio(int);
 int __cdecl setvbuf(FILE *, char *, int, size_t);
 int __cdecl _snprintf(char *, size_t, const char *, ...);
 int __cdecl sprintf(char *, const char *, ...);
 int __cdecl sscanf(const char *, const char *, ...);
 char * __cdecl _tempnam(const char *, const char *);
 FILE * __cdecl tmpfile(void);
 char * __cdecl tmpnam(char *);
 int __cdecl ungetc(int, FILE *);
 int __cdecl _unlink(const char *);
 int __cdecl vfprintf(FILE *, const char *, va_list);
 int __cdecl vprintf(const char *, va_list);
 int __cdecl _vsnprintf(char *, size_t, const char *, va_list);
 int __cdecl vsprintf(char *, const char *, va_list);








#line 363 "e:\\program\\vc98\\include\\stdio.h"




 FILE * __cdecl _wfsopen(const wchar_t *, const wchar_t *, int);
#line 369 "e:\\program\\vc98\\include\\stdio.h"

 wint_t __cdecl fgetwc(FILE *);
 wint_t __cdecl _fgetwchar(void);
 wint_t __cdecl fputwc(wint_t, FILE *);
 wint_t __cdecl _fputwchar(wint_t);
 wint_t __cdecl getwc(FILE *);
 wint_t __cdecl getwchar(void);
 wint_t __cdecl putwc(wint_t, FILE *);
 wint_t __cdecl putwchar(wint_t);
 wint_t __cdecl ungetwc(wint_t, FILE *);

 wchar_t * __cdecl fgetws(wchar_t *, int, FILE *);
 int __cdecl fputws(const wchar_t *, FILE *);
 wchar_t * __cdecl _getws(wchar_t *);
 int __cdecl _putws(const wchar_t *);

 int __cdecl fwprintf(FILE *, const wchar_t *, ...);
 int __cdecl wprintf(const wchar_t *, ...);
 int __cdecl _snwprintf(wchar_t *, size_t, const wchar_t *, ...);
 int __cdecl swprintf(wchar_t *, const wchar_t *, ...);
 int __cdecl vfwprintf(FILE *, const wchar_t *, va_list);
 int __cdecl vwprintf(const wchar_t *, va_list);
 int __cdecl _vsnwprintf(wchar_t *, size_t, const wchar_t *, va_list);
 int __cdecl vswprintf(wchar_t *, const wchar_t *, va_list);
 int __cdecl fwscanf(FILE *, const wchar_t *, ...);
 int __cdecl swscanf(const wchar_t *, const wchar_t *, ...);
 int __cdecl wscanf(const wchar_t *, ...);






 FILE * __cdecl _wfdopen(int, const wchar_t *);
 FILE * __cdecl _wfopen(const wchar_t *, const wchar_t *);
 FILE * __cdecl _wfreopen(const wchar_t *, const wchar_t *, FILE *);
 void __cdecl _wperror(const wchar_t *);
 FILE * __cdecl _wpopen(const wchar_t *, const wchar_t *);
 int __cdecl _wremove(const wchar_t *);
 wchar_t * __cdecl _wtempnam(const wchar_t *, const wchar_t *);
 wchar_t * __cdecl _wtmpnam(wchar_t *);



#line 414 "e:\\program\\vc98\\include\\stdio.h"
#line 415 "e:\\program\\vc98\\include\\stdio.h"


#line 418 "e:\\program\\vc98\\include\\stdio.h"
































 int __cdecl fcloseall(void);
 FILE * __cdecl fdopen(int, const char *);
 int __cdecl fgetchar(void);
 int __cdecl fileno(FILE *);
 int __cdecl flushall(void);
 int __cdecl fputchar(int);
 int __cdecl getw(FILE *);
 int __cdecl putw(int, FILE *);
 int __cdecl rmtmp(void);
 char * __cdecl tempnam(const char *, const char *);
 int __cdecl unlink(const char *);

#line 463 "e:\\program\\vc98\\include\\stdio.h"






#pragma pack(pop)
#line 471 "e:\\program\\vc98\\include\\stdio.h"

#line 473 "e:\\program\\vc98\\include\\stdio.h"
#line 2 "e:\\programming\\git\\kr\\ph1\\n20140324\\wbxu_20140324\\define\\define.c"















void
test_LEAPYEAR(void)
{
    int iresult;

    iresult = ( ( ((2000 + 3) % 4 == 0 && (2000 + 3) % 100 != 0) || ((2000 + 3) % 400 == 0) ) ? 1 : 0 );
}

void
test_Isupper(void)
{
    int iresult;

    iresult = ((('a' + 1) >= 'A' && ('a' + 1) <= 'Z') ? 1: 0)
}

void
test_MAX(void)
{
    int iresult;

    iresult = ((1) > (100) ? (1) : (100));

}

void
test_MIN(void)
{

}

void
test_ABS(void)
{
    int iresult;

    iresult = ((-(9 - 5)) > 0 ? (-(9 - 5)) : (-(-(9 - 5))));

}

int
main(void)
{
    test_MAX();

    test_MIN();

    test_ABS();

    test_LEAPYEAR();

    test_Isupper();

    return 0;
}
