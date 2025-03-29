// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "ColorizeDataAsset.h"
#include "ColorizeCharacterAbility.generated.h"

/**
 * 
 */
UCLASS()
class ABILITYSYSTEM2_API UColorizeCharacterAbility : public UAbility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UColorizeDataAsset> ColorizeStats;
	
};
