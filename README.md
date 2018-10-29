# SpatialOS GDK Third-Person Shooter game

* **LICENSE:** Use of the contents of this repository is subject to the [Improbable license](LICENSE.md)
* **REPOSITORY:** github.com/spatialos/UnrealGDKStarterProject


This project is a sample third-person shooter deathmatch game which uses the [SpatialOS GDK for Unreal](github.com/spatialos/unrealGDK). 

It is both a reference project and a starting point for those building games on SpatialOS and Unreal Engine 4. In the game, you can join a team, run around, shoot characters on other teams, and spawn "test cubes" (which are cubes you can shoot around).


For setup instructions, follow the [Get started](https://docs.improbable.io/unreal/latest/get-started/introduction) guide in the GDK for Unreal documentation. This guide uses the [GDK for Unreal Starter Project](https://github.com/spatialos/UnrealGDKStarterProject) as an example. When you follow the installation instructions, you need to replace the "Starter Project" repository with this one.

For more information, see the [SpatialOS GDK for Unreal documentation]((https://docs.improbable.io/unreal/latest/).

####  Helper scripts

This repository contains a set of helper scripts to get you started.

| Helper script | Description |
| --- | --- |
| LaunchSpatial.bat | Starts a local SpatialOS deployment with the default launch configuration. |
| LaunchServer.bat | Starts an Unreal server-worker, and connects it to the local deployment. |
| LaunchClient.bat | Starts an Unreal client-worker, and connects it to the local deployment. |
| ProjectPaths.bat | Used by the `LaunchClient.bat`, `LaunchServer.bat` and `LaunchSpatial.bat` to specify the project environment when those scripts are run |


#### Game Controls

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

#### Give us feedback
We have released the GDK for Unreal this early in development because we want your feedback. Please come and talk to us about the software and the documentation via: [Discord](https://discordapp.com/channels/311273633307951114/339471548647866368) - [Forums](https://forums.improbable.io/) - [GitHub issues in this repository](https://github.com/spatialos/UnrealGDK/issues).

#### Where to get the GDK and example projects
The GDK and its starter projects are available on GitHub.
* [GDK: github.com/spatialos/UnrealGDK](https://github.com/spatialos/UnrealGDK)
* [Starter Project](https://github.com/spatialos/UnrealGDKStarterProject)
* [Third-Person Shooter Game](https://github.com/spatialos/UnrealGDKThirdPersonShooter) (Not actively developed)
* [The Test Suite](https://github.com/spatialos/UnrealGDKTestSuite)
* [The SpatialOS Unreal Engine](https://github.com/improbableio/UnrealEngine/tree/4.20-SpatialOSUnrealGDK)

#### Public contributors
We are not currently accepting public contributions. However, we are accepting issues and we do want your feedback.

#### Known issues

* The character currently fires without animations while mid-jump.
* The character sometimes rotates very quickly when running and looking in different directions.
* The scoreboard occasionally does not initialize properly.

&copy; 2018 Improbable


