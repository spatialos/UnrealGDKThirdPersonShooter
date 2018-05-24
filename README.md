# SpatialGDK sample game: Unreal project demonstrating SpatialOS integration
Repository: [github.com/improbable/unreal-gdk-sample-game](https://github.com/improbable/unreal-gdk-sample-game)
By: [improbable.io](https://improbable.io/)
Copyright: TODO [JIRA ticket DEV-2087](https://improbableio.atlassian.net/browse/DEV-2087)

Use the Unreal SpatialGDK sample game to explore how Unreal projects integrate with [SpatialOS](https://improbable.io/games) local deployment.
**Notes**:
* We support this project on Windows version 10. We haven’t tested it on Windows version 7.
* These instructions are for a local deployment only.

## Requirements
To use the Unreal SpatialGDK, you need:

### Software
* The SpatialOS Unreal engine `UnrealEngine419_SpatialGDK` version.
* The Unreal SpatialGDK module and Unreal Editor plugin.
See *How to set up and run the project* below for details of these.

### Operating system
* Windows: 10

### Hardware
* Processor: i7
* Memory: 16GB RAM
* Storage: 12GB available space

## How to set up and run the project
Once you have downloaded the sample game in this repository, follow these instructions:
1. Download and set up the SpatialOS Unreal engine from [https://github.com/improbable/UnrealEngine/tree/UnrealEngine419_SpatialGDK](https://github.com/improbable/UnrealEngine/tree/UnrealEngine419_SpatialGDK).
	* Make sure that you download the `UnrealEngine419_SpatialGDK` branch to get the correct version.
	* Look at the [readme](https://github.com/improbable/UnrealEngine/blob/UnrealEngine419_SpatialGDK/README.md) file for guidance on setting up the SpatialOS Unreal engine and follow steps 1 to 4 in the `UnrealEngine419_SpatialGDK` readme.
2. Download the Unreal SpatialGDK module and Unreal Editor plugin from [https://github.com/improbable/unreal-gdk](https://github.com/improbable/unreal-gdk).
3. Create `UNREAL_HOME` environment variable and set to the location of the SpatialOS Unreal engine you have just downloaded.
4. Initialise the project: from the root directory of your project, run `Game/Scripts/Codegen.bat`.
5. Create a link between your sample game directory and the Unreal SpatialGDK: run `create_spatialGDK_symlink.bat <Unreal SpatialGDK path>`.
6. Locate the Unreal project file for your project. You’ll find this under the project’s root directory in `Game/`.
7. Right-click on `SampleGame.uproject` and select **Switch Unreal Engine version...**
8.  Select the path of the engine version you just downloaded.
9.  Build the SpatialOS Unreal engine for SpatialOS local deployment: in a terminal window, run `Game/Scripts/Build.bat SampleGameEditor Win64 Development Game/SampleGame.uproject`.
10.  Start the SpatialOS local deployment by running `spatial local launch`.
11.  Double-click on the `SampleGame.uproject` to open the Unreal Editor and select the **Play** drop-down menu to see **Modes** and **Multiplayer Options**.
12.  From the drop-down menu, select **New Editor Window (PIE)**. Enter **Number of Players** as `2` and check the box for **Run Dedicated Server**.
13.	 Click **Play** to run.

**NOTES**:

* The interop code and schema generated for marshalling updates and RPCs has been committed directly to the source tree in `Game/Source/SampleGame/Generated` and `schema/improbable/unreal/generated respectively`. This means you only need to re-run the commandlet if you have changed the code generator.
* There are two non-load-balanced launch scripts to assist your development:
    * 'one_worker_test.json' tests that managed workers launch correctly and ensures that entities never cross worker boundaries.
    * 'two_worker_test.json' provides a static non-overlapping worker boundary between two workers to assist your entity migration testing. As worker boundaries don't overlap, workers have no knowledge of an entity which is under the authority of a different worker.

## Helper Scripts
### `Game/Scripts/Codegen.bat`
(No parameters)

Generates code from the project schema.

### `Game/Scripts/BuildWorkerConfig.bat`
(No parameters)

Generates launch configurations for the runtime.

Run this if you change:
* `spatialos.UnrealClient.worker.json`
* `spatialos.UnrealWorker.worker.json`

### `Game/Scripts/Build.bat`
`<target> <platform> <configuration> Game/SampleGame.uproject [--skip-codegen]`

Build, Cook and zip special workers for use with:
* `spatial upload`
* `spatial local launch`

The following `<target>`s will generate zipped workers:
* `SampleGameEditor`
* `SampleGame`
* `SampleGameServer`

> Any other `<target>` will pass all arguments along to `Engine/Build/BatchFiles/Build.bat` - no cooking or zipping will be performed.

## Documentation

## Visit
TODO [JIRA ticket DEV-2087](https://improbableio.atlassian.net/browse/DEV-2087)

## Contribute
TODO [JIRA ticket DEV-2087](https://improbableio.atlassian.net/browse/DEV-2087)

## Support
TODO [JIRA ticket DEV-2087](https://improbableio.atlassian.net/browse/DEV-2087)

