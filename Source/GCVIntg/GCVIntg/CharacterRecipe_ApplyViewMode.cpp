// Copyright (C) 2024 owoDra

#include "CharacterRecipe_ApplyViewMode.h"

#include "GCVIntgLogs.h"

#include "ViewerComponent.h"
#include "Mode/ViewMode.h"

#include "CharacterInitStateComponent.h"

#include "GameFramework/Pawn.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterRecipe_ApplyViewMode)


UCharacterRecipe_ApplyViewMode::UCharacterRecipe_ApplyViewMode()
{
	InstancingPolicy = ECharacterRecipeInstancingPolicy::NonInstanced;
	NetExecutionPolicy = ECharacterRecipeNetExecutionPolicy::ClientOnly;
}


void UCharacterRecipe_ApplyViewMode::StartSetupNonInstanced_Implementation(FCharacterRecipePawnInfo Info) const
{
	auto* Pawn{ Info.Pawn.Get() };

	if (auto* VC{ Pawn->FindComponentByClass<UViewerComponent>() })
	{
		auto* LoadedViewModeClass
		{
			ViewMode.IsNull() ? nullptr :
			ViewMode.IsValid() ? ViewMode.Get() : ViewMode.LoadSynchronous()
		};

		UE_LOG(LogGCVI, Log, TEXT("++ViewMode (Name: %s)"), *GetNameSafe(LoadedViewModeClass));

		auto ViewModeClass{ TSubclassOf<UViewMode>(LoadedViewModeClass) };

		VC->InitializeViewMode(ViewModeClass);
	}
}
