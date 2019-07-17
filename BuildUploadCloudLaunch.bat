call BuildWorkers.bat
pushd spatial
spatial cloud upload MY_Offloading --force
spatial cloud launch MY_Offloading offloading_test.json my_offloading --snapshot=snapshots/default.snapshot
popd
