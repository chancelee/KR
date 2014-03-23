# Microsoft Developer Studio Generated NMAKE File, Based on login.dsp
!IF "$(CFG)" == ""
CFG=login - Win32 AsciiDebug
!MESSAGE No configuration specified. Defaulting to login - Win32 AsciiDebug.
!ENDIF 

!IF "$(CFG)" != "login - Win32 UnicodeDebug" && "$(CFG)" != "login - Win32 AsciiDebug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "login.mak" CFG="login - Win32 AsciiDebug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "login - Win32 UnicodeDebug" (based on "Win32 (x86) Console Application")
!MESSAGE "login - Win32 AsciiDebug" (based on "Win32 (x86) Console Application")
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

!IF  "$(CFG)" == "login - Win32 UnicodeDebug"

OUTDIR=.\UnicodeDebug
INTDIR=.\UnicodeDebug
# Begin Custom Macros
OutDir=.\UnicodeDebug
# End Custom Macros

ALL : "$(OUTDIR)\login_unicode.exe" "$(OUTDIR)\login.bsc"


CLEAN :
	-@erase "$(INTDIR)\hash.obj"
	-@erase "$(INTDIR)\hash.sbr"
	-@erase "$(INTDIR)\login.obj"
	-@erase "$(INTDIR)\login.pch"
	-@erase "$(INTDIR)\login.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\login.bsc"
	-@erase "$(OUTDIR)\login_unicode.exe"
	-@erase "$(OUTDIR)\login_unicode.ilk"
	-@erase "$(OUTDIR)\login_unicode.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "UNICODE" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\login.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\login.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\hash.sbr" \
	"$(INTDIR)\login.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\login.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\login_unicode.pdb" /debug /machine:I386 /out:"$(OUTDIR)\login_unicode.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\hash.obj" \
	"$(INTDIR)\login.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\login_unicode.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "login - Win32 AsciiDebug"

OUTDIR=.\AsciiDebug
INTDIR=.\AsciiDebug
# Begin Custom Macros
OutDir=.\AsciiDebug
# End Custom Macros

ALL : "$(OUTDIR)\login_ascii.exe"


CLEAN :
	-@erase "$(INTDIR)\hash.obj"
	-@erase "$(INTDIR)\login.obj"
	-@erase "$(INTDIR)\login.pch"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\login_ascii.exe"
	-@erase "$(OUTDIR)\login_ascii.ilk"
	-@erase "$(OUTDIR)\login_ascii.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\login.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\login.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\login_ascii.pdb" /debug /machine:I386 /out:"$(OUTDIR)\login_ascii.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\hash.obj" \
	"$(INTDIR)\login.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\login_ascii.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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


!IF "$(CFG)" == "login - Win32 UnicodeDebug" || "$(CFG)" == "login - Win32 AsciiDebug"
SOURCE=.\hash.cpp

!IF  "$(CFG)" == "login - Win32 UnicodeDebug"


"$(INTDIR)\hash.obj"	"$(INTDIR)\hash.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\login.pch"


!ELSEIF  "$(CFG)" == "login - Win32 AsciiDebug"


"$(INTDIR)\hash.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\login.pch"


!ENDIF 

SOURCE=.\login.cpp

!IF  "$(CFG)" == "login - Win32 UnicodeDebug"


"$(INTDIR)\login.obj"	"$(INTDIR)\login.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\login.pch"


!ELSEIF  "$(CFG)" == "login - Win32 AsciiDebug"


"$(INTDIR)\login.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\login.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "login - Win32 UnicodeDebug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "UNICODE" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\login.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\login.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "login - Win32 AsciiDebug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\login.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\login.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

