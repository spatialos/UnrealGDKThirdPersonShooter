#!/bin/sh
sleep 5

chmod +x WorkerCoordinator.exe
chmod +x StartWorker.sh
chmod +x ThirdPersonShooter.sh

mono WorkerCoordinator.exe $@ 2> /improbable/logs/CoordinatorErrors.log