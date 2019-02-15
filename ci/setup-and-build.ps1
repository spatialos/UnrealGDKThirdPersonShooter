param(
  [string] $game_home = (get-item "$($PSScriptRoot)").parent.FullName, ## The root of the ThirdPersonShooter repo
  [string] $gdk_repo = "git@github.com:spatialos/UnrealGDK.git",
  [string] $gcs_publish_bucket = "io-internal-infra-unreal-artifacts-production"
)

$ErrorActionPreference = 'Stop'

function Write-Log() {
  param(
    [string] $msg,
    [Parameter(Mandatory=$false)] [bool] $expand = $false
  )
  if ($expand) {
      Write-Output "+++ $($msg)"
  } else {
      Write-Output "--- $($msg)"
  }
}

function Start-Event() {
    param(
        [string] $event_name,
        [string] $event_parent
    )

    # Start this tracing span.
    Start-Process -NoNewWindow "imp-ci" -ArgumentList @(`
        "events", "new", `
        "--name", "$($event_name)", `
        "--child-of", "$($event_parent)"
    ) | Out-Null

    Write-Log "--- $($event_name)"
}

function Finish-Event() {
    param(
        [string] $event_name,
        [string] $event_parent
    )

    # Emit the end marker for this tracing span.
    Start-Process -NoNewWindow "imp-ci"  -ArgumentList @(`
        "events", "new", `
        "--name", "$($event_name)", `
        "--child-of", "$($event_parent)"
    ) | Out-Null
}


# Fetch the version of Unreal Engine we need
pushd "ci"
    $unreal_version = Get-Content -Path "unreal-engine.version" -Raw
    Write-Log "Using Unreal Engine version: $($unreal_version)"
popd

## Create an UnrealEngine directory if it doesn't already exist
New-Item -Name "UnrealEngine" -ItemType Directory -Force

Start-Event "download-unreal-engine" "build-unreal-gdk-:windows:"
pushd "UnrealEngine"
    Write-Log "Downloading the Unreal Engine artifacts from GCS"
    $gcs_unreal_location = "$($unreal_version).zip"

    $gsu_proc = Start-Process -Wait -PassThru -NoNewWindow "gsutil" -ArgumentList @(`
        "cp", `
        "gs://$($gcs_publish_bucket)/$($gcs_unreal_location)", `
        "$($unreal_version).zip" `
    )
    if ($gsu_proc.ExitCode -ne 0) {
        Write-Log "Failed to download Engine artifacts. Error: $($gsu_proc.ExitCode)"
        Throw "Failed to download Engine artifacts"
    }

    Write-Log "Unzipping Unreal Engine"
    $zip_proc = Start-Process -Wait -PassThru -NoNewWindow "7z" -ArgumentList @(`
    "x", `  
    "$($unreal_version).zip" `    
    )   
    if ($zip_proc.ExitCode -ne 0) { 
        Write-Log "Failed to unzip Unreal Engine. Error: $($zip_proc.ExitCode)" 
        Throw "Failed to unzip Unreal Engine."  
    }
popd
Finish-Event "download-unreal-engine" "build-unreal-gdk-:windows:"


pushd "$($game_home)"
    Start-Event "clone-gdk-plugin" "clone-gdk-plugin-:windows:"
    pushd "Game"
        New-Item -Name "Plugins" -ItemType Directory -Force
        pushd "Plugins"
          Start-Process -Wait -PassThru -NoNewWindow -FilePath "git" -ArgumentList @(`
            "clone", `
            "git@github.com:spatialos/UnrealGDK.git", `
            "--depth 1" `
        )
        popd
    popd
    Finish-Event "clone-gdk-plugin" "clone-gdk-plugin-:windows:"

    Start-Event "set-up-gdk-plugin" "set-up-gdk-plugin-:windows:"
    pushd "Game/Plugins/UnrealGDK"
         $setup_gdk_proc = Start-Process -Wait -PassThru -NoNewWindow -FilePath "$($game_home)\Game\Plugins\UnrealGDK\ci\setup-gdk.ps1"
        if ($setup_gdk_proc.ExitCode -ne 0) { 
            Write-Log "Failed to set up the Unreal GDK. Error: $($setup_gdk_proc.ExitCode)" 
            Throw "Failed to set up the Unreal GDK."  
        }
    popd
    Finish-Event "set-up-gdk-plugin" "set-up-gdk-plugin-:windows:"

    Start-Event "build-project" "build-project-:windows:"
        $build_proc = Start-Process -Wait -PassThru -NoNewWindow -FilePath "$($game_home)\Game\Plugins\UnrealGDK\SpatialGDK\Build\Scripts\BuildWorker.bat" -ArgumentList @(`
            "BuildPlugin", `
            " -Plugin=`"$($gdk_home)/SpatialGDK/SpatialGDK.uplugin`"", `
            "-TargetPlatforms=Win64", `
            "-Package=`"$gdk_home/SpatialGDK/Intermediate/BuildPackage/Win64`"" `
        )
        if ($build_proc.ExitCode -ne 0) { 
            Write-Log "Failed to build the Unreal GDK. Error: $($build_proc.ExitCode)" 
            Throw "Failed to build the Unreal GDK."  
        }
    popd
    Finish-Event "build-unreal-gdk" "build-unreal-gdk-:windows:"

popd
