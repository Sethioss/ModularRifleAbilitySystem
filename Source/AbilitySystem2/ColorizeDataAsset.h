// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilityStatDataAsset.h"
#include "ColorizeDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class ABILITYSYSTEM2_API UColorizeDataAsset : public UAbilityStatDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor ColorToApply;
	
};
