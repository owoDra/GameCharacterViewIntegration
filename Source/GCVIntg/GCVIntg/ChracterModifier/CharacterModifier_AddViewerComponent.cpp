// Copyright (C) 2024 owoDra

#include "CharacterModifier_AddViewerComponent.h"

#include "GCVIntgLogs.h"

#include "ViewerComponent.h"
#include "Mode/ViewMode.h"

#include "GameFramework/Pawn.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterModifier_AddViewerComponent)


UCharacterModifier_AddViewerComponent::UCharacterModifier_AddViewerComponent()
{
	bOnlyApplyOnLocal = false;
	bApplyOnClient = true;
	bApplyOnServer = true;
}


bool UCharacterModifier_AddViewerComponent::OnApply(APawn* Pawn) const
{
	const auto bCanApply{ Super::OnApply(Pawn) };

	if (bCanApply)
	{
		auto* LoadedComponentClass
		{
			ComponentClass.IsNull() ? nullptr :
			ComponentClass.IsValid() ? ComponentClass.Get() : ComponentClass.LoadSynchronous()
		};

		if (ComponentClass)
		{
			auto* NewVC{ NewObject<UViewerComponent>(Pawn, LoadedComponentClass) };
			NewVC->RegisterComponent();

			UE_LOG(LogGCVI, Log, TEXT("+Component (Name: %s, Class: %s)"), *GetNameSafe(NewVC), *GetNameSafe(LoadedComponentClass));

			auto* LoadedViewModeClass
			{
				ViewMode.IsNull() ? nullptr :
				ViewMode.IsValid() ? ViewMode.Get() : ViewMode.LoadSynchronous()
			};

			UE_LOG(LogGCVI, Log, TEXT("++ViewMode (Name: %s)"), *GetNameSafe(LoadedViewModeClass));

			auto ViewModeClass{ TSubclassOf<UViewMode>(LoadedViewModeClass) };

			NewVC->InitializeViewMode(ViewModeClass);
		}
	}

	return bCanApply;
}
