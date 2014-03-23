# Microsoft Developer Studio Generated NMAKE File, Based on debugprintf.dsp
!IF "$(CFG)" == ""
CFG=debugprintf - Win32 Debug
!MESSAGE No configuration specified. Defaulting to debugprintf - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "debugprintf - Win32 Release" && "$(CFG)" != "debugprintf - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "debugprintf.mak" CFG="debugprintf - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "debugprintf - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "debugprintf - Win32 Debug" (based on "Win32 (x86) Console Application")
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

!IF  "$(CFG)" == "debugprintf - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\debugprintf.exe"


CLEAN :
	-@erase "$(INTDIR)\debugprintf.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\debugprintf.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\debugprintf.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\debugprintf.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\debugprintf.pdb" /machine:I386 /out:"$(OUTDIR)\debugprintf.exe" 
LINK32_OBJS= \
	"$(INTDIR)\debugprintf.obj"

"$(OUTDIR)\debugprintf.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "debugprintf - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\debugprintf.exe" "$(OUTDIR)\debugprintf.bsc"


CLEAN :
	-@erase "$(INTDIR)\debugprintf.obj"
	-@erase "$(INTDIR)\debugprintf.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\debugprintf.bsc"
	-@erase "$(OUTDIR)\debugprintf.exe"
	-@erase "$(OUTDIR)\debugprintf.ilk"
	-@erase "$(OUTDIR)\debugprintf.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\debugprintf.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ  /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\debugprintf.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\debugprintf.sbr"

"$(OUTDIR)\debugprintf.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\debugprintf.pdb" /debug /machine:I386 /out:"$(OUTDIR)\debugprintf.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\debugprintf.obj"

"$(OUTDIR)\debugprintf.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("debugprintf.dep")
!INCLUDE "debugprintf.dep"
!ELSE 
!MESSAGE Warning: cannot find "debugprintf.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "debugprintf - Win32 Release" || "$(CFG)" == "debugprintf - Win32 Debug"
SOURCE=.\debugprintf.c

!IF  "$(CFG)" == "debugprintf - Win32 Release"


"$(INTDIR)\debugprintf.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "debugprintf - Win32 Debug"


"$(INTDIR)\debugprintf.obj"	"$(INTDIR)\debugprintf.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 


!ENDIF 

