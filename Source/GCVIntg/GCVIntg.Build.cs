// Copyright (C) 2023 owoDra

using UnrealBuildTool;

public class GCVIntg : ModuleRules
{
	public GCVIntg(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
           new string[]
           {
                ModuleDirectory,
                ModuleDirectory + "/GCVIntg",
           }
       );


        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "GameplayTags",
            }
        );


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "GCExt",
                "GVExt",
            }
        );

        SetupIrisSupport(Target);
    }
}
