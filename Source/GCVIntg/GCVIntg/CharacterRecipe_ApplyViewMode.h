// Copyright (C) 2024 owoDra

#pragma once

#include "Recipe/CharacterRecipe.h"

#include "CharacterRecipe_ApplyViewMode.generated.h"

class UViewerComponent;
class UViewMode;


/**
 * Modifier class to apply ViewMode to viewer component
 */
UCLASS()
class UCharacterRecipe_ApplyViewMode final : public UCharacterRecipe
{
	GENERATED_BODY()
public:
	UCharacterRecipe_ApplyViewMode();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "ApplyViewMode")
	TSoftClassPtr<UViewMode> ViewMode{ nullptr };

protected:
	virtual void StartSetupNonInstanced_Implementation(FCharacterRecipePawnInfo Info) const override;

};
