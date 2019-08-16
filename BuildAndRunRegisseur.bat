call BuildWorkers.bat
pushd spatial\scenarios\utils
call .\linux_line_endings.sh run_test.sh .
popd
pushd spatial\scenarios
.\run.sh basic_test_scenario.pb.json ..\snapshots\default.snapshot aigymtest
popd
