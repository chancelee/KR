#ifndef __AUTHORITY_H
#define __AUTHORITY_H


#define     ADD     1
#define     DEL     2
#define     EDIT    4
#define     QUERY   8

/*
Function: Ϊ����authorityȨ������adjustȨ��
*/
void
addauthority(char *authority, int adjust);

/*
Function: ������authorityȨ���е�ajustȨ��ɾ����
*/
void
delauthority(char *authority, int adjust);

#endif