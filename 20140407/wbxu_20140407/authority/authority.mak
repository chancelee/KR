# Microsoft Developer Studio Generated NMAKE File, Based on authority.dsp
!IF "$(CFG)" == ""
CFG=authority - Win32 Debug
!MESSAGE No configuration specified. Defaulting to authority - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "authority - Win32 Release" && "$(CFG)" != "authority - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "authority.mak" CFG="authority - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "authority - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "authority - Win32 Debug" (based on "Win32 (x86) Console Application")
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

!IF  "$(CFG)" == "authority - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\authority.exe"


CLEAN :
	-@erase "$(INTDIR)\authority.obj"
	-@erase "$(INTDIR)\ui.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\authority.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\authority.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\authority.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\authority.pdb" /machine:I386 /out:"$(OUTDIR)\authority.exe" 
LINK32_OBJS= \
	"$(INTDIR)\authority.obj" \
	"$(INTDIR)\ui.obj"

"$(OUTDIR)\authority.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "authority - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\authority.exe" "$(OUTDIR)\authority.bsc"


CLEAN :
	-@erase "$(INTDIR)\authority.obj"
	-@erase "$(INTDIR)\authority.sbr"
	-@erase "$(INTDIR)\ui.obj"
	-@erase "$(INTDIR)\ui.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\authority.bsc"
	-@erase "$(OUTDIR)\authority.exe"
	-@erase "$(OUTDIR)\authority.ilk"
	-@erase "$(OUTDIR)\authority.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\authority.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ  /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\authority.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\authority.sbr" \
	"$(INTDIR)\ui.sbr"

"$(OUTDIR)\authority.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\authority.pdb" /debug /machine:I386 /out:"$(OUTDIR)\authority.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\authority.obj" \
	"$(INTDIR)\ui.obj"

"$(OUTDIR)\authority.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("authority.dep")
!INCLUDE "authority.dep"
!ELSE 
!MESSAGE Warning: cannot find "authority.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "authority - Win32 Release" || "$(CFG)" == "authority - Win32 Debug"
SOURCE=.\authority.c

!IF  "$(CFG)" == "authority - Win32 Release"


"$(INTDIR)\authority.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "authority - Win32 Debug"


"$(INTDIR)\authority.obj"	"$(INTDIR)\authority.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\ui.c

!IF  "$(CFG)" == "authority - Win32 Release"


"$(INTDIR)\ui.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "authority - Win32 Debug"


"$(INTDIR)\ui.obj"	"$(INTDIR)\ui.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 


!ENDIF 

