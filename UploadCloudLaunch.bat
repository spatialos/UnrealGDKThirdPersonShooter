pushd spatial
spatial cloud upload TPS_AAA_Dev --force
spatial cloud launch TPS_AAA_Dev one_worker_test.json tps_aaa_dev --snapshot=snapshots/default.snapshot
popd