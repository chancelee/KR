# Microsoft Developer Studio Generated NMAKE File, Based on tetris.dsp
!IF "$(CFG)" == ""
CFG=tetris - Win32 Debug
!MESSAGE No configuration specified. Defaulting to tetris - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "tetris - Win32 Release" && "$(CFG)" != "tetris - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "tetris.mak" CFG="tetris - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "tetris - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "tetris - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "tetris - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\tetris.exe"


CLEAN :
	-@erase "$(INTDIR)\logic.obj"
	-@erase "$(INTDIR)\teris.obj"
	-@erase "$(INTDIR)\ui.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\tetris.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\tetris.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\tetris.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\tetris.pdb" /machine:I386 /out:"$(OUTDIR)\tetris.exe" 
LINK32_OBJS= \
	"$(INTDIR)\logic.obj" \
	"$(INTDIR)\teris.obj" \
	"$(INTDIR)\ui.obj"

"$(OUTDIR)\tetris.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "tetris - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\tetris.exe" "$(OUTDIR)\tetris.bsc"


CLEAN :
	-@erase "$(INTDIR)\logic.obj"
	-@erase "$(INTDIR)\logic.sbr"
	-@erase "$(INTDIR)\teris.obj"
	-@erase "$(INTDIR)\teris.sbr"
	-@erase "$(INTDIR)\ui.obj"
	-@erase "$(INTDIR)\ui.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\tetris.bsc"
	-@erase "$(OUTDIR)\tetris.exe"
	-@erase "$(OUTDIR)\tetris.ilk"
	-@erase "$(OUTDIR)\tetris.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\tetris.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\tetris.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\logic.sbr" \
	"$(INTDIR)\teris.sbr" \
	"$(INTDIR)\ui.sbr"

"$(OUTDIR)\tetris.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\tetris.pdb" /debug /machine:I386 /out:"$(OUTDIR)\tetris.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\logic.obj" \
	"$(INTDIR)\teris.obj" \
	"$(INTDIR)\ui.obj"

"$(OUTDIR)\tetris.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("tetris.dep")
!INCLUDE "tetris.dep"
!ELSE 
!MESSAGE Warning: cannot find "tetris.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "tetris - Win32 Release" || "$(CFG)" == "tetris - Win32 Debug"
SOURCE=.\logic.c

!IF  "$(CFG)" == "tetris - Win32 Release"


"$(INTDIR)\logic.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "tetris - Win32 Debug"


"$(INTDIR)\logic.obj"	"$(INTDIR)\logic.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\teris.c

!IF  "$(CFG)" == "tetris - Win32 Release"


"$(INTDIR)\teris.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "tetris - Win32 Debug"


"$(INTDIR)\teris.obj"	"$(INTDIR)\teris.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\ui.c

!IF  "$(CFG)" == "tetris - Win32 Release"


"$(INTDIR)\ui.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "tetris - Win32 Debug"


"$(INTDIR)\ui.obj"	"$(INTDIR)\ui.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 


!ENDIF 

