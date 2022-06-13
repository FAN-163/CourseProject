// Course Project

using UnrealBuildTool;
using System.Collections.Generic;

public class CourseProjectTarget : TargetRules
{
	public CourseProjectTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "CourseProject" } );
	}
}
