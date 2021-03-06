# Microsoft Developer Studio Generated NMAKE File, Based on login.dsp
!IF "$(CFG)" == ""
CFG=login - Win32 Debug
!MESSAGE No configuration specified. Defaulting to login - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "login - Win32 Release" && "$(CFG)" != "login - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "login.mak" CFG="login - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "login - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "login - Win32 Debug" (based on "Win32 (x86) Console Application")
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

!IF  "$(CFG)" == "login - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\login.exe"


CLEAN :
	-@erase "$(INTDIR)\hash.obj"
	-@erase "$(INTDIR)\login.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\login.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\login.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\login.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\login.pdb" /machine:I386 /out:"$(OUTDIR)\login.exe" 
LINK32_OBJS= \
	"$(INTDIR)\hash.obj" \
	"$(INTDIR)\login.obj"

"$(OUTDIR)\login.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "login - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\login.exe" "$(OUTDIR)\login.bsc"


CLEAN :
	-@erase "$(INTDIR)\hash.obj"
	-@erase "$(INTDIR)\hash.sbr"
	-@erase "$(INTDIR)\login.obj"
	-@erase "$(INTDIR)\login.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\login.bsc"
	-@erase "$(OUTDIR)\login.exe"
	-@erase "$(OUTDIR)\login.ilk"
	-@erase "$(OUTDIR)\login.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\login.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\login.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\hash.sbr" \
	"$(INTDIR)\login.sbr"

"$(OUTDIR)\login.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\login.pdb" /debug /machine:I386 /out:"$(OUTDIR)\login.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\hash.obj" \
	"$(INTDIR)\login.obj"

"$(OUTDIR)\login.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("login.dep")
!INCLUDE "login.dep"
!ELSE 
!MESSAGE Warning: cannot find "login.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "login - Win32 Release" || "$(CFG)" == "login - Win32 Debug"
SOURCE=.\hash.c

!IF  "$(CFG)" == "login - Win32 Release"


"$(INTDIR)\hash.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "login - Win32 Debug"


"$(INTDIR)\hash.obj"	"$(INTDIR)\hash.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\login.c

!IF  "$(CFG)" == "login - Win32 Release"


"$(INTDIR)\login.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "login - Win32 Debug"


"$(INTDIR)\login.obj"	"$(INTDIR)\login.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 


!ENDIF 

