@echo off

call "%~dp0ProjectPaths.bat"

rem When flexible project structure is implemented we can gather this information from the project structure descriptor file.
set GENERATED_SCHEMA="%~dp0spatial\schema\improbable\unreal\generated"
set GENERATED_TYPE_BINDINGS="%~dp0%PROJECT_PATH%\Source\%GAME_NAME%\Generated"
set GENERATED_WORKER_FILES="%~dp0%PROJECT_PATH%\Source\SpatialGDK\Generated"

rem If '-a' argument is specified, clean all without prompt
if /I "%1" == "-a" (
    call :CleanPath %GENERATED_SCHEMA%
    call :CleanPath %GENERATED_TYPE_BINDINGS%
    call :CleanPath %GENERATED_WORKER_FILES%
    echo Running %PROJECT_PATH%/Scripts/Codegen.bat
    call "%~dp0%PROJECT_PATH%/Scripts/Codegen.bat"
) else (
    goto Main
)
exit /b 0

rem If '-a' does not exist, prompt the user
:Main
echo This script is intended to clean %GAME_NAME% generated files.

set /p CLEAN_SCHEMA=Clean generated schema (%GENERATED_SCHEMA%)?[Y/N]:
if /I "%CLEAN_SCHEMA%" == "Y" (
    call :CleanPath %GENERATED_SCHEMA%
)

set /p CLEAN_TYPE_BINDINGS=Clean generated type bindings (%GENERATED_TYPE_BINDINGS%)?[Y/N]:
if /I "%CLEAN_TYPE_BINDINGS%" == "Y" (
    call :CleanPath %GENERATED_TYPE_BINDINGS%
)

set /p CLEAN_WORKER_FILES=Clean generated worker code (%GENERATED_WORKER_FILES%)?[Y/N]:
if /I "%CLEAN_WORKER_FILES%" == "Y" (
    call :CleanWorkerFiles
)

echo %0 has completed successfully^!
pause
exit /b 0

:CleanWorkerFiles
call :CleanPath %GENERATED_WORKER_FILES%
echo After removing generated worker code it is recommended to run Codegen.bat
call :WorkerCodegen
exit /b 0

:CleanPath
if exist "%~1" (
    rd /s /q "%~1"
    echo The folder "%~1" removed.
) else (
    echo "%~1" did not exist when performing the clean.
)
exit /b 0

:WorkerCodegen
set /p WORKER_CODEGEN=Run Codegen.bat?[Y/N]:
if /I "%WORKER_CODEGEN%" == "Y" (
    call "%~dp0%PROJECT_PATH%/Scripts/Codegen.bat"
)
exit /b 0
