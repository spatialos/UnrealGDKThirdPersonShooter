@ECHO OFF

REM perform git clean excluding symlinked folders
call git clean -xfd -e Game/Plugins/SpatialGDK/ -e Game/Source/SpatialGDK/ -e Game/Scripts/ -e spatial/schema/improbable/unreal/gdk/ %*

exit 0
