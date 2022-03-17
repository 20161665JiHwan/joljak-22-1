using UnrealBuildTool;

public class ForTheKing : ModuleRules
{
	public ForTheKing(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "UMG" });

		PrivateIncludePaths.Add("ForTheKing");
	}
}
