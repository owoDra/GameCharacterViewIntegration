// Copyright (C) 2024 owoDra

#pragma once

#include "Recipe/CharacterRecipe.h"

#include "CharacterRecipe_AddViewerComponent.generated.h"

class UViewerComponent;
class UViewMode;


/**
 * Modifier class to add viewer component to Pawn
 */
UCLASS()
class UCharacterRecipe_AddViewerComponent final : public UCharacterRecipe
{
	GENERATED_BODY()
public:
	UCharacterRecipe_AddViewerComponent();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "AddViewerComponent")
	TSoftClassPtr<UViewerComponent> ComponentClass{ nullptr };

	UPROPERTY(EditDefaultsOnly, Category = "AddViewerComponent")
	TSoftClassPtr<UViewMode> ViewMode{ nullptr };

protected:
	virtual void StartSetupNonInstanced_Implementation(FCharacterRecipePawnInfo Info) const override;

};
