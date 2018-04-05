@ECHO OFF

set SPATIALGDK_PATH="%1"
set SPATIALGDK_PLUGINSPATH="%1\Plugins\SpatialGDK"
set SPATIALGDK_MODULEPATH="%1\SpatialGDK"

if %SPATIALGDK_PATH% == "" (
	echo Error: Please specify the SpatialGDK path.
	pause > nul
	exit 1
)

if not exist %SPATIALGDK_PATH%\ (
	echo Error: SpatialGDK path %SPATIALGDK_PATH% does not exist.
	exit 1
)

set PATH_VALID=true
if not exist %SPATIALGDK_PLUGINSPATH% set PATH_VALID=false
if not exist %SPATIALGDK_MODULEPATH% set PATH_VALID=false

if %PATH_VALID%==false (
 	echo Error: SpatialGDK path %SPATIALGDK_PATH% is invalid. Provide path to cloned SpatialGDK git repository.
	exit 1
)

REM Cleanup old symlinks
rmdir "%~dp0\workers\unreal\Game\Plugins\SpatialGDK" 2>NUL
rmdir "%~dp0\workers\unreal\Game\Source\SpatialGDK" 2>NUL

REM Ensure plugins folder exists, mklink doesn't recursively create
if not exist %~dp0\workers\unreal\Game\Plugins\ (
	mkdir %~dp0\workers\unreal\Game\Plugins\
)

REM Make new symlinks
mklink /J "%~dp0\workers\unreal\Game\Plugins\SpatialGDK" %SPATIALGDK_PLUGINSPATH%
mklink /J "%~dp0\workers\unreal\Game\Source\SpatialGDK" %SPATIALGDK_MODULEPATH%

echo Successfully created symlinks to %SPATIALGDK_PATH%

exit 0