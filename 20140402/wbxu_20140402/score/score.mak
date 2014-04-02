# Microsoft Developer Studio Generated NMAKE File, Based on score.dsp
!IF "$(CFG)" == ""
CFG=score - Win32 Debug
!MESSAGE No configuration specified. Defaulting to score - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "score - Win32 Release" && "$(CFG)" != "score - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "score.mak" CFG="score - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "score - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "score - Win32 Debug" (based on "Win32 (x86) Console Application")
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

!IF  "$(CFG)" == "score - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\score.exe"


CLEAN :
	-@erase "$(INTDIR)\score.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\score.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\score.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\score.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\score.pdb" /machine:I386 /out:"$(OUTDIR)\score.exe" 
LINK32_OBJS= \
	"$(INTDIR)\score.obj"

"$(OUTDIR)\score.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "score - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\score.exe" "$(OUTDIR)\score.bsc"


CLEAN :
	-@erase "$(INTDIR)\score.obj"
	-@erase "$(INTDIR)\score.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\score.bsc"
	-@erase "$(OUTDIR)\score.exe"
	-@erase "$(OUTDIR)\score.ilk"
	-@erase "$(OUTDIR)\score.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\score.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ  /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\score.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\score.sbr"

"$(OUTDIR)\score.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\score.pdb" /debug /machine:I386 /out:"$(OUTDIR)\score.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\score.obj"

"$(OUTDIR)\score.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("score.dep")
!INCLUDE "score.dep"
!ELSE 
!MESSAGE Warning: cannot find "score.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "score - Win32 Release" || "$(CFG)" == "score - Win32 Debug"
SOURCE=.\score.c

!IF  "$(CFG)" == "score - Win32 Release"


"$(INTDIR)\score.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "score - Win32 Debug"


"$(INTDIR)\score.obj"	"$(INTDIR)\score.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 


!ENDIF 

