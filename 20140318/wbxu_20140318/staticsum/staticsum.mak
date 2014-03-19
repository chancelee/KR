# Microsoft Developer Studio Generated NMAKE File, Based on staticsum.dsp
!IF "$(CFG)" == ""
CFG=staticsum - Win32 Debug
!MESSAGE No configuration specified. Defaulting to staticsum - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "staticsum - Win32 Release" && "$(CFG)" != "staticsum - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "staticsum.mak" CFG="staticsum - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "staticsum - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "staticsum - Win32 Debug" (based on "Win32 (x86) Console Application")
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

!IF  "$(CFG)" == "staticsum - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\staticsum.exe"


CLEAN :
	-@erase "$(INTDIR)\staticsum.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\staticsum.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\staticsum.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\staticsum.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\staticsum.pdb" /machine:I386 /out:"$(OUTDIR)\staticsum.exe" 
LINK32_OBJS= \
	"$(INTDIR)\staticsum.obj"

"$(OUTDIR)\staticsum.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "staticsum - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\staticsum.exe" "$(OUTDIR)\staticsum.bsc"


CLEAN :
	-@erase "$(INTDIR)\staticsum.obj"
	-@erase "$(INTDIR)\staticsum.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\staticsum.bsc"
	-@erase "$(OUTDIR)\staticsum.exe"
	-@erase "$(OUTDIR)\staticsum.ilk"
	-@erase "$(OUTDIR)\staticsum.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\staticsum.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ  /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\staticsum.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\staticsum.sbr"

"$(OUTDIR)\staticsum.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\staticsum.pdb" /debug /machine:I386 /out:"$(OUTDIR)\staticsum.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\staticsum.obj"

"$(OUTDIR)\staticsum.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("staticsum.dep")
!INCLUDE "staticsum.dep"
!ELSE 
!MESSAGE Warning: cannot find "staticsum.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "staticsum - Win32 Release" || "$(CFG)" == "staticsum - Win32 Debug"
SOURCE=.\staticsum.c

!IF  "$(CFG)" == "staticsum - Win32 Release"


"$(INTDIR)\staticsum.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "staticsum - Win32 Debug"


"$(INTDIR)\staticsum.obj"	"$(INTDIR)\staticsum.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 


!ENDIF 

