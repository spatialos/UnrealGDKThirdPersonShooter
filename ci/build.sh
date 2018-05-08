#!/usr/bin/env bash

set -e -u -x -o pipefail

cd "$(dirname "$0")/../"

source ci/force_spatial_cli_structure.sh
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

markEndOfBlock "Clean gdk build directory"

markStartOfBlock "Make gdk build directory"

mkdir -p "build/"

markEndOfBlock "Make gdk build directory"

markStartOfBlock "Clone the GDK from github"

pushd "build/"

git clone git@github.com:improbable/unreal-gdk.git -b ${UNREAL_GDK_BRANCH}

popd

markEndOfBlock "Clone the GDK from github"

markStartOfBlock "Run the GDK setup script"

pushd "build/unreal-gdk"

# Run the setup script with the root of the SampleGame as the install path.
./setup.sh ../../

popd

markEndOfBlock "Run the GDK setup script"

markStartOfBlock "Build the SampleGame"

runSpatial build --target=local

markEndOfBlock "Build the SampleGame"

markEndOfBlock "$0"
