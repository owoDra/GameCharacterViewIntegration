// Copyright (C) 2024 owoDra

#include "CharacterRecipe_AddViewerComponent.h"

#include "ViewerComponent.h"
#include "Mode/ViewMode.h"

#include "CharacterInitStateComponent.h"
#include "GCExtLogs.h"

#include "GameFramework/Pawn.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterRecipe_AddViewerComponent)


UCharacterRecipe_AddViewerComponent::UCharacterRecipe_AddViewerComponent()
{
	InstancingPolicy = ECharacterRecipeInstancingPolicy::NonInstanced;
	NetExecutionPolicy = ECharacterRecipeNetExecutionPolicy::ClientOnly;

#if WITH_EDITOR
	StaticClass()->FindPropertyByName(FName{ TEXTVIEW("InstancingPolicy") })->SetPropertyFlags(CPF_DisableEditOnTemplate);
	StaticClass()->FindPropertyByName(FName{ TEXTVIEW("NetExecutionPolicy") })->SetPropertyFlags(CPF_DisableEditOnTemplate);
#endif
}


void UCharacterRecipe_AddViewerComponent::StartSetupNonInstanced_Implementation(FCharacterRecipePawnInfo Info) const
{
	auto* Pawn{ Info.Pawn.Get() };

	auto* LoadedComponentClass
	{
		ComponentClass.IsNull() ? nullptr :
		ComponentClass.IsValid() ? ComponentClass.Get() : ComponentClass.LoadSynchronous()
	};

	if (ComponentClass)
	{
		auto* NewVC{ NewObject<UViewerComponent>(Pawn, LoadedComponentClass) };
		NewVC->RegisterComponent();

		UE_LOG(LogGameExt_CharacterRecipe, Log, TEXT("+Component (Name: %s, Class: %s)"), *GetNameSafe(NewVC), *GetNameSafe(LoadedComponentClass));

		auto* LoadedViewModeClass
		{
			ViewMode.IsNull() ? nullptr :
			ViewMode.IsValid() ? ViewMode.Get() : ViewMode.LoadSynchronous()
		};

		UE_LOG(LogGameExt_CharacterRecipe, Log, TEXT("++ViewMode (Name: %s)"), *GetNameSafe(LoadedViewModeClass));

		auto ViewModeClass{ TSubclassOf<UViewMode>(LoadedViewModeClass) };

		NewVC->InitializeViewMode(ViewModeClass);
	}
}
