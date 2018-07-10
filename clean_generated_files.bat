@ECHO OFF

:: When flexible project structure is implemented we can gather this information from the project structure descriptor file.
SET GENERATED_SCHEMA="%~dp0spatial\schema\improbable\unreal\generated"
SET GENERATED_TYPE_BINDINGS="%~dp0Game\Source\SampleGame\Generated"
SET GENERATED_WORKER_FILES="%~dp0Game\Source\SpatialGDK\Generated"

:: If '-a' argument is specified, clean all without prompt 
IF /I "%1"=="-a" (
   CALL :clean_path %GENERATED_SCHEMA%
   CALL :clean_path %GENERATED_TYPE_BINDINGS%
   CALL :clean_path %GENERATED_WORKER_FILES%
   ECHO Running Game/Scripts/Codegen.bat
   CALL %~dp0Game/Scripts/Codegen.bat
) ELSE (
    GOTO main
)
EXIT /B 0

:: If '-a' does not exist, prompt the user
:main
ECHO This script is intended to clean SampleGame generated files and therefore assumes its project structure.

SET /p CLEAN_SCHEMA=Clean generated schema?[Y/N]: 
IF /I %CLEAN_SCHEMA% == Y (
    CALL :clean_path %GENERATED_SCHEMA%
)

set /p CLEAN_TYPE_BINDINGS=Clean generated type bindings?[Y/N]: 
IF /I %CLEAN_TYPE_BINDINGS% == Y (
    CALL :clean_path %GENERATED_TYPE_BINDINGS%
)

set /p CLEAN_WORKER_FILES=Clean generated worker code?[Y/N]: 
IF /I %CLEAN_WORKER_FILES% == Y (
    CALL :clean_worker_files
)
EXIT /B 0

:clean_worker_files
CALL :clean_path %GENERATED_WORKER_FILES%
ECHO After removing generated worker code it is recommended to run Codegen.bat
CALL :worker_codegen    
EXIT /B 0

:clean_path
IF EXIST "%~1" (
    RMDIR /s /q "%~1"
    ECHO The folder "%~1" removed.
) ELSE (
    ECHO "%~1" did not exist when performing the clean.
)
EXIT /B 0

:worker_codegen
SET /p WORKER_CODEGEN=Run Codegen.bat?[Y/N]: 
IF /I %WORKER_CODEGEN% == Y (
    %~dp0Game/Scripts/Codegen.bat
) 
EXIT /B 0
