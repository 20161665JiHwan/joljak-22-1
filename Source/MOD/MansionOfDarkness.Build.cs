using UnrealBuildTool;

public class MansionOfDarkness : ModuleRules
{
	public MansionOfDarkness(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "UMG" });

		PrivateIncludePaths.Add("MansionOfDarkness");
	}
}
