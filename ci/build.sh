#!/usr/bin/env bash

set -e -u -x -o pipefail

cd "$(dirname "$0")/../"

source ci/pinned-tools.sh
source ci/profiling.sh

if ! isWindows ; then
  echo "SampleGame can only be built on Windows."
  exit 0
fi

if [ -z "${UNREAL_GDK_BRANCH+x}" ]; then
  echo "The UNREAL_GDK_BRANCH variable was not set, using master as default."
  UNREAL_GDK_BRANCH="master"
fi

markStartOfBlock "$0"

markStartOfBlock "Clean gdk build directory"
  rm -rf build/unreal-gdk/
  mkdir -p build
markEndOfBlock "Clean gdk build directory"

markStartOfBlock "Clone the GDK from github"
  git clone git@github.com:improbable/unreal-gdk.git -b ${UNREAL_GDK_BRANCH} --single-branch "build/unreal-gdk"
markEndOfBlock "Clone the GDK from github"

markStartOfBlock "Run the GDK setup script"
  pushd "build/unreal-gdk"
    ci/build.sh
  popd
  ./create_gdk_symlink.bat "build/unreal-gdk"
markEndOfBlock "Run the GDK setup script"

markStartOfBlock "Build the SampleGame"
  # Build each target to ensure scripts are correct, skipping code generation on all but the first to save some time.
  Game/Scripts/Build.bat "SampleGameEditor" "Win64" "Development" "Game/SampleGame.uproject"
  if [[ ! -f "spatial/build/assembly/worker/UnrealEditor@Windows.zip" ]]; then
    echo "Editor was not properly built."
    exit 1
  fi

  # UNR-276 - This is disabled until TC agents have UE4.19 properly configured.
  # Game/Scripts/Build.bat "SampleGameServer" "Linux" "Development" "Game/SampleGame.uproject" --skip-codegen
  # if [[ ! -f "spatial/build/assembly/worker/UnrealWorker@Linux.zip" ]]; then
  #   echo "Linux Server was not properly built."
  #   exit 1
  # fi

  Game/Scripts/Build.bat "SampleGame" "Win64" "Development" "Game/SampleGame.uproject" --skip-codegen
  if [[ ! -f "spatial/build/assembly/worker/UnrealClient@Windows.zip" ]]; then
     echo "Client was not properly built."
     exit 1
  fi
markEndOfBlock "Build the SampleGame"

markEndOfBlock "$0"
