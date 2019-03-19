@echo off

call "%~dp0\Game\Plugins\UnrealGDK\SpatialGDK\Build\Scripts\BuildWorker.bat" ThirdPersonShooterServer Linux Development ThirdPersonShooter.uproject

pushd "%~dp0\spatial"

spatial cloud upload %1
spatial cloud launch --snapshot=snapshots/default.snapshot %1 one_worker_test.json %1_dpl --tags ttl_2_hours,ai_perf,unr_1079

exit /b %ERRORLEVEL%