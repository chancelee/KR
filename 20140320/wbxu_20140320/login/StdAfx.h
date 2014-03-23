// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__E76FD325_69AE_4D91_8CD9_4920B549F0C3__INCLUDED_)
#define AFX_STDAFX_H__E76FD325_69AE_4D91_8CD9_4920B549F0C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#include <stdio.h>
#include <windows.h>

#include "hash.h"

#define MAX_TRY     3

/*deal with ANSI / UNICODE */
#ifdef  UNICODE 

    #define _tprintf    wprintf
    #define _tscanf     wscanf
    #define _tcslen     wcslen

    #define _TCHAR      wchar_t
    #define _T(x)       L##x

    //BASE and SIZE for Key Code
    #define BASE   0x004013D2
    #define SIZE   0x4F

    //hash for verify
    #define HASH_VERIFY 0x00000003
    
    //hash for PASSWORD
    #define HASH_PASSWD 0x163f00a7

#else   //not defined UNICODE

    #define _tprintf    printf
    #define _tscanf     scanf
    #define _tcslen     strlen

    #define _TCHAR      char
    #define _T(x)       x

    //BASE and SIZE for Key Code
    #define  BASE       0x004013D2
    #define  SIZE       0x4D

    //hash for verify
    #define HASH_VERIFY 0x00000003

    //hash for PASSWD
    #define HASH_PASSWD 0xDA9B5D6D       

#endif  //UNICODE

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__E76FD325_69AE_4D91_8CD9_4920B549F0C3__INCLUDED_)
