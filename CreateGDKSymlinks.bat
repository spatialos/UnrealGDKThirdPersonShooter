@echo off

if "%~1" == "" (
	set /p UNREALGDK_PATH=Please specify the path to the UnrealGDK directory: 
) else (
	set UNREALGDK_PATH=%~1
)

set UNREALGDK_PLUGINSPATH="%UNREALGDK_PATH%\Plugins\SpatialGDK"
set UNREALGDK_MODULEPATH="%UNREALGDK_PATH%\Source\SpatialGDK"
set UNREALGDK_SCRIPTSPATH="%UNREALGDK_PATH%\Scripts"
set UNREALGDK_BINARIESPATH="%UNREALGDK_PATH%\Binaries\ThirdParty\Improbable"
set UNREALGDK_SCHEMAPATH="%UNREALGDK_PATH%\schema\improbable\unreal\gdk"

if not exist "%UNREALGDK_PATH%\" (
	echo Error: UnrealGDK path "%UNREALGDK_PATH%" does not exist.
	if not defined TEAMCITY_CAPTURE_ENV pause
	exit /b 1
)

set PATH_VALID=true
if not exist %UNREALGDK_PLUGINSPATH% set PATH_VALID=false
if not exist %UNREALGDK_MODULEPATH% set PATH_VALID=false
if not exist %UNREALGDK_SCHEMAPATH% set PATH_VALID=false
if not exist %UNREALGDK_SCRIPTSPATH% set PATH_VALID=false

if %PATH_VALID% == false (
	echo Error: UnrealGDK path "%UNREALGDK_PATH%" is invalid. Provide path to cloned UnrealGDK git repository.
	if not defined TEAMCITY_CAPTURE_ENV pause
	exit /b 1
)

set REPO_PREPARED=true
if not exist %UNREALGDK_BINARIESPATH% set REPO_PREPARED=false

if %REPO_PREPARED% == false (
	echo Error: The specified UnrealGDK directory has not been prepared. Please run BuildGDK.bat in that directory.
	if not defined TEAMCITY_CAPTURE_ENV pause
	exit /b 1
)

call "%~dp0ProjectPaths.bat"

rem Cleanup old symlinks
rd "%~dp0%PROJECT_PATH%\Plugins\SpatialGDK" 2>nul
rd "%~dp0%PROJECT_PATH%\Source\SpatialGDK" 2>nul
rd "%~dp0%PROJECT_PATH%\Scripts" 2>nul
rd "%~dp0%PROJECT_PATH%\Binaries\ThirdParty\Improbable" 2>nul
rd "%~dp0spatial\schema\improbable\unreal\gdk" 2>nul

rem Ensure plugins folder exists, mklink doesn't recursively create
if not exist "%~dp0%PROJECT_PATH%\Plugins\" (
	md "%~dp0%PROJECT_PATH%\Plugins\"
)

rem Ensure codegen folder exists, mklink doesn't recursively create
if not exist "%~dp0%PROJECT_PATH%\Binaries\ThirdParty\" (
	md "%~dp0%PROJECT_PATH%\Binaries\ThirdParty\"
)

rem Ensure schema folder exists, mklink doesn't recursively create
if not exist "%~dp0spatial\schema\improbable\unreal\" (
	md "%~dp0spatial\schema\improbable\unreal\"
)

rem Make new symlinks
mklink /J "%~dp0%PROJECT_PATH%\Plugins\SpatialGDK" %UNREALGDK_PLUGINSPATH%
mklink /J "%~dp0%PROJECT_PATH%\Source\SpatialGDK" %UNREALGDK_MODULEPATH%
mklink /J "%~dp0%PROJECT_PATH%\Scripts" %UNREALGDK_SCRIPTSPATH%
mklink /J "%~dp0%PROJECT_PATH%\Binaries\ThirdParty\Improbable" %UNREALGDK_BINARIESPATH%
mklink /J "%~dp0spatial\schema\improbable\unreal\gdk" %UNREALGDK_SCHEMAPATH%

echo Successfully created symlinks to "%UNREALGDK_PATH%"
if not defined TEAMCITY_CAPTURE_ENV pause
exit /b 0
