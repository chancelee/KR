# Microsoft Developer Studio Generated NMAKE File, Based on prirategame.dsp
!IF "$(CFG)" == ""
CFG=prirategame - Win32 Debug
!MESSAGE No configuration specified. Defaulting to prirategame - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "prirategame - Win32 Release" && "$(CFG)" != "prirategame - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "prirategame.mak" CFG="prirategame - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "prirategame - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "prirategame - Win32 Debug" (based on "Win32 (x86) Console Application")
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

!IF  "$(CFG)" == "prirategame - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\prirategame.exe"


CLEAN :
	-@erase "$(INTDIR)\prirategame.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\prirategame.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\prirategame.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\prirategame.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\prirategame.pdb" /machine:I386 /out:"$(OUTDIR)\prirategame.exe" 
LINK32_OBJS= \
	"$(INTDIR)\prirategame.obj"

"$(OUTDIR)\prirategame.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "prirategame - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\prirategame.exe" "$(OUTDIR)\prirategame.bsc"


CLEAN :
	-@erase "$(INTDIR)\prirategame.obj"
	-@erase "$(INTDIR)\prirategame.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\prirategame.bsc"
	-@erase "$(OUTDIR)\prirategame.exe"
	-@erase "$(OUTDIR)\prirategame.ilk"
	-@erase "$(OUTDIR)\prirategame.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\prirategame.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ  /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\prirategame.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\prirategame.sbr"

"$(OUTDIR)\prirategame.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\prirategame.pdb" /debug /machine:I386 /out:"$(OUTDIR)\prirategame.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\prirategame.obj"

"$(OUTDIR)\prirategame.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("prirategame.dep")
!INCLUDE "prirategame.dep"
!ELSE 
!MESSAGE Warning: cannot find "prirategame.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "prirategame - Win32 Release" || "$(CFG)" == "prirategame - Win32 Debug"
SOURCE=.\prirategame.c

!IF  "$(CFG)" == "prirategame - Win32 Release"


"$(INTDIR)\prirategame.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "prirategame - Win32 Debug"


"$(INTDIR)\prirategame.obj"	"$(INTDIR)\prirategame.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 


!ENDIF 

