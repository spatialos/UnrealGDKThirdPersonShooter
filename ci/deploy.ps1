. "$PSScriptRoot\common.ps1"

Start-Event "deploy-game" "build-gdk-third-person-shooter-:windows:"
pushd "spatial"
    $commit_id = (get-item env:BUILDKITE_BUILD_NUMBER).Value
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

    Write-Log "Executing spatial cloud upload $($assembly_name) --force"

    Start-Process -Wait -PassThru -NoNewWindow -FilePath "spatial" -ArgumentList @(`
        "cloud", `
        "upload", `
        "$($assembly_name)", `
        "--log_level=debug", `
        "--force"
    )

    Write-Log "Executing spatial cloud launch $($assembly_name) $($deployment_launch_configuration) $($deployment_name) --snapshot=$($deployment_snapshot_path) --cluster_region=$($deployment_cluster_region)"
    Start-Process -Wait -PassThru -NoNewWindow -FilePath "spatial" -ArgumentList @(`
        "cloud", `
        "launch", `
        "$($assembly_name)", `
        "$($deployment_launch_configuration)", `
        "$($deployment_name)", `
        "--snapshot=$($deployment_snapshot_path)", `
        "--cluster_region=$($deployment_cluster_region)", `
        "--log_level=debug"
    )
popd
Finish-Event "deploy-game" "build-gdk-third-person-shooter-:windows:"