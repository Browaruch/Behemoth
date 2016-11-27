@ECHO OFF
TITLE %~n0
COLOR 9F

SET VERSION=..\pawno\include\PTS\meta\version.inc

SET f_COMPILEDATE=%DATE:~8,2%.%DATE:~5,2%.%DATE:~0,4%
SET f_COMPILETIME=%TIME:~0,2%:%TIME:~3,2%:%TIME:~6,2%

FOR /F "tokens=*" %%s IN (revision) DO SET REVISION=%%s
SET /A REVISION=%REVISION%+1

set USER=%username%
set GDZIE=%userdomain%

echo /* Version */ > "%VERSION%"

REM echo #define ENABLE_PROTECTION_VARIABLES >> "%VERSION%"
echo #define GMVERSION "2.0.%REVISION%" >> "%VERSION%"
echo #define GMCOMPILED "skompilowana %f_COMPILEDATE% %f_COMPILETIME% przez %USER%@%GDZIE%" >> "%VERSION%"

echo Please wait...
ECHO.
..\pawno\pawncc.exe -r "%CD%\3dit.pwn" -i"..\\pawno\\include" -(+ -;+ -d3
IF EXIST "%CD%\3dit.xml" DEL /Q /A "%CD%\3dit.xml" > nul
IF EXIST "%CD%\3dit.amx" ECHO %REVISION% > revision
ECHO.
pause