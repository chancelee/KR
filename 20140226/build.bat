del *.exe

cl /c /WX /W3 %1.c
cl /c /WX  /W3 %2.c

link %1.obj %2.obj
del *.obj

pause