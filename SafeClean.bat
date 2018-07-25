@echo off

call "%~dp0ProjectPaths.bat"

set SPATIALGDK_PLUGINSPATH="%~dp0%PROJECT_PATH%\Plugins\SpatialGDK"
set SPATIALGDK_MODULEPATH="%~dp0%PROJECT_PATH%\Source\SpatialGDK"
set SPATIALGDK_SCRIPTSPATH="%~dp0%PROJECT_PATH%\Scripts"
set SPATIALGDK_BINARIESPATH="%~dp0%PROJECT_PATH%\Binaries\ThirdParty\Improbable"
set SPATIALGDK_SCHEMAPATH="%~dp0spatial\schema\improbable\unreal\gdk"
rem This var is only used for the automated process which is run with the '-a' command line argument. Users should change this accordingly.
set SPATIALGDK_UNREALGDKPATH="%~dp0..\unreal-gdk" 

rem If '-a' argument is specified, clean all without prompt 
if /I "%1" == "-a" (
    call :CleanAllSymlinks
    call :GitClean
    echo Creating symlinks with known path in this script %SPATIALGDK_UNREALGDKPATH%
    call CreateGDKSymlinks.bat %SPATIALGDK_UNREALGDKPATH%
) else (
    goto Main
)
exit /b 0

rem First section is for cleaning known UnrealGDK symlinks and running git clean.
:Main
set /p NUKE=Would you like to clean all symlinks, uncommitted changes and all built files (git clean -xdf)?[Y/N]: 
if /I "%NUKE%" == "Y" (
    call :CleanAllSymlinks
    call :GitClean
    call :BuildSymlinks
)

echo %0 has completed successfully^!
pause
exit /b 0

rem Second section is for rebuilding these symlinks.
:BuildSymlinks
set /p BUILDBRIDGES=Would you like to remake symlinks to your Unreal GDK?[Y/N]: 
if /I "%BUILDBRIDGES%" == "Y" (
    set /p GDKPATH=Please provide the path to your Unreal GDK: 
    call :MakeSymlinks
)
exit /b 0

rem All helper methods are below.
:MakeSymlinks
call CreateGDKSymlinks.bat "%GDKPATH%"
exit /b 0

:CleanAllSymlinks
echo Cleaning old symlinks
call :CleanPath %SPATIALGDK_PLUGINSPATH%
call :CleanPath %SPATIALGDK_MODULEPATH%
call :CleanPath %SPATIALGDK_SCRIPTSPATH%
call :CleanPath %SPATIALGDK_BINARIESPATH%
call :CleanPath %SPATIALGDK_SCHEMAPATH%
echo Finished cleaning up old symlinks
exit /b 0

:CleanPath
if exist "%~1" (
    rd /s /q "%~1"
    echo The symlink "%~1" removed
) else (
    echo "%~1" did not exist when performing the clean
)
exit /b 0

:GitClean
echo Performing git clean
git clean -xdf
echo Finished git clean
exit /b 0
