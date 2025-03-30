// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilityStatDataAsset.h"
#include "GrowOnBounceDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class ABILITYSYSTEM2_API UGrowOnBounceDataAsset : public UAbilityStatDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float GrowPercentOnEachBounce = 1.;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MaxSizePercentage = 3.;
	
};
