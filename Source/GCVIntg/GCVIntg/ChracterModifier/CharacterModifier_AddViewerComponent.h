// Copyright (C) 2023 owoDra

#pragma once

#include "CharacterModifier.h"

#include "CharacterModifier_AddViewerComponent.generated.h"

class UViewerComponent;
class UViewMode;


/**
 * Modifier class to add viewer component to Pawn
 */
UCLASS(meta = (DisplayName = "CM Add Viewer Component"))
class UCharacterModifier_AddViewerComponent final : public UCharacterModifier
{
	GENERATED_BODY()
public:
	UCharacterModifier_AddViewerComponent();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "AddViewerComponent")
	TSoftClassPtr<UViewerComponent> ComponentClass{ nullptr };

	UPROPERTY(EditDefaultsOnly, Category = "AddViewerComponent")
	TSoftClassPtr<UViewMode> ViewMode{ nullptr };

protected:
	virtual bool OnApply(APawn* Pawn) const override;

};
