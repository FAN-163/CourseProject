// Course Project

using UnrealBuildTool;

public class CourseProject : ModuleRules
{
    public CourseProject(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "Niagara",
            "PhysicsCore",
            "GameplayTasks",
            "NavigationSystem"
        });

        PrivateDependencyModuleNames.AddRange(new string[] { });

        PublicIncludePaths.AddRange(new string[] 
        { 
            "CourseProject/Public/Player", 
            "CourseProject/Public/Components", 
            "CourseProject/Public/Dev",
            "CourseProject/Public/Weapon",
            "CourseProject/Public/UI",
            "CourseProject/Public/Animation",
            "CourseProject/Public/Pickups",
            "CourseProject/Public/Weapon/Components",
            "CourseProject/Public/AI",
            "CourseProject/Public/AI/Tasks"
        });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
