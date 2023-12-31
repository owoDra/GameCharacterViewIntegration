// Copyright (C) 2023 owoDra

#pragma once

#include "CharacterModifier.h"

#include "CharacterModifier_AddViewerComponent.generated.h"

class UViewerComponent;
class UViewMode;


/**
 * Modifier class to add viewer component to Pawn
 */
UCLASS(meta = (DisplayName = "CM Add Playable Component"))
class UCharacterModifier_AddViewerComponent final : public UCharacterModifier
{
	GENERATED_BODY()
public:
	UCharacterModifier_AddViewerComponent();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "AddPlayableComponent")
	TSoftClassPtr<UViewerComponent> ComponentClass{ nullptr };

	UPROPERTY(EditDefaultsOnly, Category = "AddPlayableComponent")
	TSoftClassPtr<UViewMode> ViewMode{ nullptr };

protected:
	virtual bool OnApply(APawn* Pawn) const override;

};
