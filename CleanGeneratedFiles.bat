@echo off

rem When flexible project structure is implemented we can gather this information from the project structure descriptor file.
set GENERATED_SCHEMA="%~dp0spatial\schema\improbable\unreal\generated"
set GENERATED_TYPE_BINDINGS="%~dp0Game\Source\SampleGame\Generated"
set GENERATED_WORKER_FILES="%~dp0Game\Source\SpatialGDK\Generated"

rem If '-a' argument is specified, clean all without prompt
if /I "%1" == "-a" (
    call :CleanPath %GENERATED_SCHEMA%
    call :CleanPath %GENERATED_TYPE_BINDINGS%
    call :CleanPath %GENERATED_WORKER_FILES%
    echo Running Game/Scripts/Codegen.bat
    call "%~dp0Game/Scripts/Codegen.bat"
) else (
    goto Main
)
exit /b 0

rem If '-a' does not exist, prompt the user
:Main
echo This script is intended to clean SampleGame generated files and therefore assumes its project structure.

set /p CLEAN_SCHEMA=Clean generated schema?[Y/N]:
if /I "%CLEAN_SCHEMA%" == "Y" (
    call :CleanPath %GENERATED_SCHEMA%
)

set /p CLEAN_TYPE_BINDINGS=Clean generated type bindings?[Y/N]:
if /I "%CLEAN_TYPE_BINDINGS%" == "Y" (
    call :CleanPath %GENERATED_TYPE_BINDINGS%
)

set /p CLEAN_WORKER_FILES=Clean generated worker code?[Y/N]:
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
    call "%~dp0Game/Scripts/Codegen.bat"
)
exit /b 0
