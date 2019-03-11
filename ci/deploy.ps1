. "$PSScriptRoot\common.ps1"

Start-Event "deploy-game" "build-gdk-third-person-shooter-:windows:"
pushd "spatial"
    # Get the short commit hash of this build
    $commit_id = (get-item env:BUILDKITE_COMMIT).Value.Substring(0, 7)
    $deployment_name = "shooter_$($commit_id)"
    $assembly_name = "$($deployment_name)_asm"

    Start-Process -Wait -PassThru -NoNewWindow -FilePath "spatial" -ArgumentList @(`
        "build", `
        "build-config"
    )

    Start-Process -Wait -PassThru -NoNewWindow -FilePath "spatial" -ArgumentList @(`
        "prepare-for-run", `
        "--log_level=debug"
    )

    Start-Process -Wait -PassThru -NoNewWindow -FilePath "spatial" -ArgumentList @(`
        "cloud", `
        "upload", `
        "$assembly_name", `
        "--log_level=debug", `
        "--force"
    )

    Start-Process -Wait -PassThru -NoNewWindow -FilePath "spatial" -ArgumentList @(`
        "cloud", `
        "launch", `
        "$assembly_name", `
        "$deployment_launch_configuration", `
        "$deployment_name", `
        "--snapshot=$deployment_snapshot_path", `
        "--cluster_region=$deployment_cluster_region", `
        "--log_level=debug"
    )
popd
Finish-Event "deploy-game" "build-gdk-third-person-shooter-:windows:"