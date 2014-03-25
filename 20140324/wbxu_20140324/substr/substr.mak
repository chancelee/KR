# Microsoft Developer Studio Generated NMAKE File, Based on substr.dsp
!IF "$(CFG)" == ""
CFG=substr - Win32 Debug
!MESSAGE No configuration specified. Defaulting to substr - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "substr - Win32 Release" && "$(CFG)" != "substr - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "substr.mak" CFG="substr - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "substr - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "substr - Win32 Debug" (based on "Win32 (x86) Console Application")
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

!IF  "$(CFG)" == "substr - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\substr.exe"


CLEAN :
	-@erase "$(INTDIR)\substr.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\substr.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\substr.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\substr.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\substr.pdb" /machine:I386 /out:"$(OUTDIR)\substr.exe" 
LINK32_OBJS= \
	"$(INTDIR)\substr.obj"

"$(OUTDIR)\substr.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "substr - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\substr.exe" "$(OUTDIR)\substr.bsc"


CLEAN :
	-@erase "$(INTDIR)\substr.obj"
	-@erase "$(INTDIR)\substr.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\substr.bsc"
	-@erase "$(OUTDIR)\substr.exe"
	-@erase "$(OUTDIR)\substr.ilk"
	-@erase "$(OUTDIR)\substr.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\substr.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ  /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\substr.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\substr.sbr"

"$(OUTDIR)\substr.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\substr.pdb" /debug /machine:I386 /out:"$(OUTDIR)\substr.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\substr.obj"

"$(OUTDIR)\substr.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("substr.dep")
!INCLUDE "substr.dep"
!ELSE 
!MESSAGE Warning: cannot find "substr.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "substr - Win32 Release" || "$(CFG)" == "substr - Win32 Debug"
SOURCE=.\substr.c

!IF  "$(CFG)" == "substr - Win32 Release"


"$(INTDIR)\substr.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "substr - Win32 Debug"


"$(INTDIR)\substr.obj"	"$(INTDIR)\substr.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 


!ENDIF 

