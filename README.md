# rundll32_thing

Tiny Win32 DLL that can be run with `rundll32`. It can also be loaded into 
programs, export other non-`rundll32` compatible functions, and do anything a 
normal DLL could do.

## Building

If you have Visual Studio: 

Use the provided Solution file.


If not, Visual Studio generates the compile stage's options to something like
this: 

    /Yu"stdafx.h" /GS /GL /analyze- /W3 /Gy /Zc:wchar_t /Zi /Gm- /O2 /sdl 
    /Fd"Release\vc120.pdb" /fp:precise /D "WIN32" /D "NDEBUG" /D "_WINDOWS" 
    /D "_USRDLL" /D "RUNDLL32_THING_EXPORTS" /D "_WINDLL" /D "_UNICODE" 
    /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /Gd /Oy- /Oi /MD 
    /Fa"Release\" /EHsc /nologo /Fo"Release\" /Fp"Release\rundll32_thing.pch"

...and the the linker stage's options to something like this:

    /OUT:"Release\rundll32_thing.dll" /MANIFEST /LTCG /NXCOMPAT 
    /PDB:"Release\rundll32_thing.pdb" /DYNAMICBASE "kernel32.lib" "user32.lib" 
    "gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" 
    "ole32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib" 
    /DEF:"rundll32_thing.def" 
    /IMPLIB:"Release\rundll32_thing.lib" /DEBUG /DLL /MACHINE:X86 /OPT:REF 
    /SAFESEH /INCREMENTAL:NO /PGD:"Release\rundll32_thing.pgd" 
    /SUBSYSTEM:WINDOWS /MANIFESTUAC:"level='asInvoker' uiAccess='false'" 
    /ManifestFile:"Release\rundll32_thing.dll.intermediate.manifest" 
    /OPT:ICF /ERRORREPORT:PROMPT /NOLOGO /TLBID:1 

Uh, anyway. I bet you didn't notice the double `the` just before the above code
block! 

The important thing is that your build system sets the subsystem to Windows, the
build type to DLL and the export definitions file to `rundll32_thing.def`. Oh, 
and built as x86. You should define UNICODE too - I use wide strings for the 
message boxes. (Life lesson: don't simply cast a multibyte string to a wide 
string)

## Meaning

[rundll32][rd] is an interesting interface that allows people to execute 
functions inside DLLs. The functions have to adhere to a specific signature (eg 
they have to use the windows subsystem, have to accept 4 arguments, and other 
things), and can be called with command-line arguments. These functions can be
embedded inside any sort of DLL, and might already be in some DLLs. 

[rd]: https://support.microsoft.com/en-us/kb/164787

