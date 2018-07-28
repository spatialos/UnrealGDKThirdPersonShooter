# Unreal GDK Third-Person Shooter (pre-alpha)

Use of the contents of this repository is subject to the [Improbable license](LICENSE.md).

Note that this project and the contents of this repository are in a **pre-alpha stage**, meaning that they are meant for evaluation only.

## Introduction

This project is a sample third-person shooter deathmatch game implemented on top of the SpatialOS Unreal GDK. It is meant to be a reference project and/or a starting point for those building games on SpatialOS and Unreal Engine 4. In the game, you can join a team, run around, shoot characters on other teams, and spawn "test cubes" (cubes you can shoot around).

For setup instructions, follow [the guide in the SpatialOS Unreal GDK repository](https://github.com/improbable/UnrealGDK/blob/master/docs/setup-and-installing.md), replacing the "Starter Project" repository with this one.

For more information, see the [SpatialOS Unreal GDK repository](https://github.com/improbable/UnrealGDK) and its [documentation](https://github.com/improbable/UnrealGDK/blob/master/docs/readme.md).

## Helper scripts

This repository contains a set of helper scripts to get you started.

| Helper script | Parameters | Description |
| --- | --- | --- |
| CleanGeneratedFiles.bat | `[-a]` | Cleans generated schema and/or type bindings and/or worker code. Call with `-a` flag to clean everything without prompting. |
| CreateGDKSymlinks.bat | `[Unreal GDK path]` | Creates symlinks to the directories in the Unreal GDK containing the SpatialGDK module, plugins, scripts, binaries, and schema. |
| SafeClean.bat | `[-a]` | Cleans the symlinks, uncommitted changes, and all built files. Call with `-a` flag to clean everything without prompting. Optionally calls `CreateGDKSymlinks.bat` to restore the symlinks. |

## Game Controls

The following controls are bound in-game, for gameplay and testing.

| Key Binding | Function |
| --- | --- |
| W,A,S,D | Standard movement |
| Space | Jump |
| Shift | Sprint |
| Left Click | Fire |
| C | Spawn a "test cube" |
| E | Interact with test cubes |
| Tab | Toggle scoreboard |

## Contributions

**Feedback**<br/>
Please give us your feedback! Please see the Unreal GDK [feedback section](https://github.com/improbable/UnrealGDK#give-us-feedback) for more information.

**Public contributors**<br/>
We are not currently accepting public contributions. However, we are accepting issues and we do want your feedback.

## Known Issues

* The character currently fires without animations while mid-jump.
* The character sometimes rotates very quickly when running and looking in different directions.
* The scoreboard occasionally does not initialize properly.

&copy; 2018 Improbable
