// Copyright (C) 2024 owoDra

#pragma once

#include "CharacterModifier.h"

#include "CharacterModifier_ApplyViewMode.generated.h"

class UViewerComponent;
class UViewMode;


/**
 * Modifier class to apply ViewMode to viewer component
 */
UCLASS(meta = (DisplayName = "CM Apply View Mode"))
class UCharacterModifier_ApplyViewMode final : public UCharacterModifier
{
	GENERATED_BODY()
public:
	UCharacterModifier_ApplyViewMode();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "ApplyViewMode")
	TSoftClassPtr<UViewMode> ViewMode{ nullptr };

protected:
	virtual bool OnApply(APawn* Pawn) const override;

};
