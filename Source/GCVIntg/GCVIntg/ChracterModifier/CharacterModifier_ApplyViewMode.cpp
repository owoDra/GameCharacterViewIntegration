// Copyright (C) 2024 owoDra

#include "CharacterModifier_ApplyViewMode.h"

#include "GCVIntgLogs.h"

#include "ViewerComponent.h"
#include "Mode/ViewMode.h"

#include "GameFramework/Pawn.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterModifier_ApplyViewMode)


UCharacterModifier_ApplyViewMode::UCharacterModifier_ApplyViewMode()
{
	bOnlyApplyOnLocal = false;
	bApplyOnClient = true;
	bApplyOnServer = true;
}


bool UCharacterModifier_ApplyViewMode::OnApply(APawn* Pawn) const
{
	const auto bCanApply{ Super::OnApply(Pawn) };

	if (bCanApply)
	{
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

	return bCanApply;
}
