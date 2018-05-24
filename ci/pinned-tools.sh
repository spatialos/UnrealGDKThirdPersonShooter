#!/usr/bin/env bash

# Function declarations
if [ -z "$IMPROBABLE_TOOLS" ]; then
    echo "The internal tools share is not set up correctly on this machine. Please follow the setup instructions here before running build.sh: https://brevi.link/internal-tools-share"
    exit 1
fi

function isLinux() {
  [[ "$(uname -s)" == "Linux" ]];
}

function isMacOS() {
  [[ "$(uname -s)" == "Darwin" ]];
}

function isWindows() {
  ! ( isLinux || isMacOS );
}

function getPlatformName() {
  if isLinux; then
    echo "linux"
  elif isMacOS; then
    echo "mac"
  elif isWindows; then
    echo "windows"
  else
    echo "ERROR: Unknown platform." >&2
    exit 1
  fi
}

# The current version of Unreal.
if [ -z "${UNREAL_HOME+x}" ]; then
  UNREAL_VERSION="419-SpatialGDK"
  export UNREAL_HOME="C:/Unreal/UnrealEngine-${UNREAL_VERSION}"
fi

# LINUX_MULTIARCH_ROOT is used by Unreal when cross compiling Linux workers
# as Unreal only builds on Windows otherwise. The Linux cross compiling tools
# should be automatically installed by puppet as part of the Unreal Engine
# installation.
if [ -z "${LINUX_MULTIARCH_ROOT+x}" ]; then
  export LINUX_MULTIARCH_ROOT="${UNREAL_HOME}/ClangToolchain"
fi
