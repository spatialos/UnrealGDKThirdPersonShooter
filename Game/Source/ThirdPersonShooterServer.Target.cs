// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

using UnrealBuildTool;
using System.Collections.Generic;

public class ThirdPersonShooterServerTarget : TargetRules
{
	public ThirdPersonShooterServerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Server;
		ExtraModuleNames.Add("ThirdPersonShooter");
	}
}
