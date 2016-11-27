@ECHO OFF
IF EXIST "%CD%\cmd_find.txt" DEL /Q /A "%CD%\cmd_find.txt" > nul
IF EXIST "%CD%\cmd_list.txt" DEL /Q /A "%CD%\cmd_list.txt" > nul
FOR /F "tokens=*" %%s IN ('DIR /S /B /A "%CD%\*.inc"') DO FIND "CMD:" "%%s" >> "%CD%\cmd_find.txt"
FIND "CMD:" "..\..\..\gamemodes\3dit.pwn" >> "%CD%\cmd_find.txt"

FOR /F "tokens=*" %%s IN (cmd_find.txt) DO CALL :CMDR "%%s"

GOTO :eof

:CMDR
SET BUFFER=%~1
IF "%BUFFER:~0,4%" == "CMD:" ECHO %BUFFER:~4,-1% >> "%CD%\cmd_list.txt"
GOTO :eof
