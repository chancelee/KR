cls
cl /c /WX /W3 %1.c
link %1.obj
del *.obj
pause