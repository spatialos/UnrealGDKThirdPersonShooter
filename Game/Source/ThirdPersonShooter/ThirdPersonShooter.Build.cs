// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

using UnrealBuildTool;

public class ThirdPersonShooter : ModuleRules
{
	public ThirdPersonShooter(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"InputCore",
				"Sockets",
				"OnlineSubsystem",
				"OnlineSubsystemUtils",
				"PhysXVehicles",
				"UMG",
				"Slate",
				"SlateCore",
				"Http",
				"Json",
				"JsonUtilities",
				"SpatialGDK"
			});
	}
}
