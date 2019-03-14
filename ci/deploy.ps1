. "$PSScriptRoot\common.ps1"

Start-Event "deploy-game" "build-gdk-third-person-shooter-:windows:"
    # Use the shortened commit hash gathered during GDK plugin clone 
    $deployment_name = "shooter_$($gdk_commit_hash)"
    $assembly_name = "$($deployment_name)_asm"

    pushd "spatial"
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
        ) | Tee-Object -FilePath "deploy.log"

        $deployment_url = Select-String -Path "deploy.log" -Pattern 'Console URL:\s*(.*)\\n'
        if (($deployment_url).Matches.Length -gt 0)
        {
            buildkite-agent annotate --style "success" "Deployment URL: $(($deployment_url).Matches[0].Groups[1].Value)"
        }
        else{
            buildkite-agent annotate --style "warning" "Could not parse deployment URL from launch log."
        }
    popd
Finish-Event "deploy-game" "build-gdk-third-person-shooter-:windows:"