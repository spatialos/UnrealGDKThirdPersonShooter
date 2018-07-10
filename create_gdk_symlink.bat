@ECHO OFF

set SPATIALGDK_PATH="%1"
set SPATIALGDK_PLUGINSPATH="%1\Plugins\SpatialGDK"
set SPATIALGDK_MODULEPATH="%1\Source\SpatialGDK"
set SPATIALGDK_SCRIPTSPATH="%1\Scripts"
set SPATIALGDK_BINARIESPATH="%1\Binaries\ThirdParty\Improbable"
set SPATIALGDK_SCHEMAPATH="%1\schema\improbable\unreal\gdk"

if %SPATIALGDK_PATH% == "" (
	echo Error: Please specify the SpatialGDK path.
	pause > nul
	exit /b 1
)

if not exist %SPATIALGDK_PATH%\ (
	echo Error: SpatialGDK path %SPATIALGDK_PATH% does not exist.
	exit /b 1
)

set PATH_VALID=true
if not exist %SPATIALGDK_PLUGINSPATH% set PATH_VALID=false
if not exist %SPATIALGDK_MODULEPATH% set PATH_VALID=false
if not exist %SPATIALGDK_SCHEMAPATH% set PATH_VALID=false

if %PATH_VALID%==false (
	echo Error: SpatialGDK path %SPATIALGDK_PATH% is invalid. Provide path to cloned SpatialGDK git repository.
	exit /b 1
)

set REPO_PREPARED=true
if not exist %SPATIALGDK_SCRIPTSPATH% set REPO_PREPARED=false
if not exist %SPATIALGDK_BINARIESPATH% set REPO_PREPARED=false

if %REPO_PREPARED%==false (
	echo Error: The specified SpatialGDK directory has not been prepared. Please run ci/build.sh in that directory.
	exit /b 1
)

REM Cleanup old symlinks
rmdir "%~dp0\Game\Plugins\SpatialGDK" 2>NUL
rmdir "%~dp0\Game\Source\SpatialGDK" 2>NUL
rmdir "%~dp0\Game\Scripts" 2>NUL
rmdir "%~dp0\Game\Binaries\ThirdParty\Improbable" 2>NUL
rmdir "%~dp0\spatial\schema\improbable\unreal\gdk" 2>NUL

REM Ensure plugins folder exists, mklink doesn't recursively create
if not exist %~dp0\Game\Plugins\ (
	mkdir %~dp0\Game\Plugins\
)

REM Ensure codegen folder exists, mklink doesn't recursively create
if not exist %~dp0\Game\Binaries\ThirdParty\ (
	mkdir %~dp0\Game\Binaries\ThirdParty\
)

REM Ensure schema folder exists, mklink doesn't recursively create
if not exist %~dp0\spatial\schema\improbable\unreal\ (
	mkdir %~dp0\spatial\schema\improbable\unreal\
)

REM Make new symlinks
mklink /J "%~dp0\Game\Plugins\SpatialGDK" %SPATIALGDK_PLUGINSPATH%
mklink /J "%~dp0\Game\Source\SpatialGDK" %SPATIALGDK_MODULEPATH%
mklink /J "%~dp0\Game\Scripts" %SPATIALGDK_SCRIPTSPATH%
mklink /J "%~dp0\Game\Binaries\ThirdParty\Improbable" %SPATIALGDK_BINARIESPATH%
mklink /J "%~dp0\spatial\schema\improbable\unreal\gdk" %SPATIALGDK_SCHEMAPATH%

echo Successfully created symlinks to %SPATIALGDK_PATH%

exit /b 0
