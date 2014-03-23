# Microsoft Developer Studio Generated NMAKE File, Based on setlocale.dsp
!IF "$(CFG)" == ""
CFG=setlocale - Win32 Debug
!MESSAGE No configuration specified. Defaulting to setlocale - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "setlocale - Win32 Release" && "$(CFG)" != "setlocale - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "setlocale.mak" CFG="setlocale - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "setlocale - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "setlocale - Win32 Debug" (based on "Win32 (x86) Console Application")
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

!IF  "$(CFG)" == "setlocale - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\setlocale.exe"


CLEAN :
	-@erase "$(INTDIR)\setlocale.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\setlocale.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\setlocale.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\setlocale.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\setlocale.pdb" /machine:I386 /out:"$(OUTDIR)\setlocale.exe" 
LINK32_OBJS= \
	"$(INTDIR)\setlocale.obj"

"$(OUTDIR)\setlocale.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "setlocale - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\setlocale.exe" "$(OUTDIR)\setlocale.bsc"


CLEAN :
	-@erase "$(INTDIR)\setlocale.obj"
	-@erase "$(INTDIR)\setlocale.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\setlocale.bsc"
	-@erase "$(OUTDIR)\setlocale.exe"
	-@erase "$(OUTDIR)\setlocale.ilk"
	-@erase "$(OUTDIR)\setlocale.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\setlocale.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ  /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\setlocale.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\setlocale.sbr"

"$(OUTDIR)\setlocale.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\setlocale.pdb" /debug /machine:I386 /out:"$(OUTDIR)\setlocale.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\setlocale.obj"

"$(OUTDIR)\setlocale.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("setlocale.dep")
!INCLUDE "setlocale.dep"
!ELSE 
!MESSAGE Warning: cannot find "setlocale.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "setlocale - Win32 Release" || "$(CFG)" == "setlocale - Win32 Debug"
SOURCE=.\setlocale.c

!IF  "$(CFG)" == "setlocale - Win32 Release"


"$(INTDIR)\setlocale.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "setlocale - Win32 Debug"


"$(INTDIR)\setlocale.obj"	"$(INTDIR)\setlocale.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 


!ENDIF 

