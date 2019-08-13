@echo off
set /p serverip="Enter Server Ip:"
"spatial\build\unreal\WindowsNoEditor\_ThirdPersonShooter.exe" %serverip%:8001 -game -log -stdout -nowrite -unattended -nologtimes -nopause -noin -messaging -NoVerifyGC -OverrideSpatialNetworking=false num_bots 0
