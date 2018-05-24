@ECHO OFF

set SPATIALGDK_PLUGINSPATH="%~dp0\Game\Plugins\SpatialGDK"
set SPATIALGDK_MODULEPATH="%~dp0\Game\Source\SpatialGDK"
set SPATIALGDK_SCRIPTSPATH="%~dp0\Game\Scripts"
set SPATIALGDK_BINARIESPATH="%~dp0\Game\Binaries\ThirdParty\Improbable"
set SPATIALGDK_SCHEMAPATH="%~dp0\schema\improbable\unreal\gdk"

ECHO Cleaning old symlinks
CALL :clean_path %SPATIALGDK_PLUGINSPATH%
CALL :clean_path %SPATIALGDK_MODULEPATH%
CALL :clean_path %SPATIALGDK_SCRIPTSPATH%
CALL :clean_path %SPATIALGDK_BINARIESPATH%
CALL :clean_path %SPATIALGDK_SCHEMAPATH%
ECHO Finished cleaning up old symlinks

ECHO Performing git clean
git clean -xdf
ECHO Finished git clean

EXIT /B 0

:clean_path
IF EXIST "%~1" (
    rmdir /s /q "%~1"
    echo The symlink "%~1" removed
) ELSE (
    echo "%~1" did not exist when performing the clean
)
