

using UnrealBuildTool;

public class ActionRPG : ModuleRules
{
	public ActionRPG(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"AnimGraphRuntime"
		});
		
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"HeadMountedDisplay",
			"UMG",
			"Slate",
			"SlateCore",
			"PhysicsCore",
			"AIModule",
			"Niagara",
			"CableComponent",
			"NavigationSystem",
			"GameplayTasks"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
		
		PrivateIncludePaths.Add(ModuleDirectory);
		PublicIncludePaths.Add(ModuleDirectory);
	}
}
