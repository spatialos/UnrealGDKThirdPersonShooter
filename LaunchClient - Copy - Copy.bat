@echo off
call "%~dp0ProjectPaths.bat"
"%UNREAL_HOME%\Engine\Binaries\Win64\UE4Editor.exe" "%~dp0%PROJECT_PATH%\%GAME_NAME%.uproject" 127.0.0.1 -game -simulatedplayer -log -stdout -nowrite -unattended -nologtimes -nopause -noin -messaging -NoVerifyGC num_bots 0
