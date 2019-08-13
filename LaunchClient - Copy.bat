@echo off
call "%~dp0ProjectPaths.bat"
"%UNREAL_HOME%\Engine\Binaries\Win64\UE4Editor.exe" "%~dp0%PROJECT_PATH%\%GAME_NAME%.uproject" 35.240.2.80:8001 -game -log -stdout -nowrite -unattended -nologtimes -nopause -noin -messaging -NoVerifyGC -OverrideSpatialNetworking=false num_bots 0
