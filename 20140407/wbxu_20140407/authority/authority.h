#ifndef __AUTHORITY_H
#define __AUTHORITY_H


#define     ADD     1
#define     DEL     2
#define     EDIT    4
#define     QUERY   8

/*
Function: 为现有authority权限增加adjust权限
*/
void
addauthority(char *authority, int adjust);

/*
Function: 将现有authority权限中的ajust权限删除。
*/
void
delauthority(char *authority, int adjust);

#endif