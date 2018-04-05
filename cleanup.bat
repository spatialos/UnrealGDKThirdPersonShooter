@ECHO OFF

REM perform git clean excluding symlinked folders
call git clean -xfd -e workers/unreal/Game/Plugins/SpatialGDK/ -e workers/unreal/Game/Source/SpatialGDK/ %*

exit 0