// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilityStatDataAsset.h"
#include "BounceDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class ABILITYSYSTEM2_API UBounceDataAsset : public UAbilityStatDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector BounceDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BounceStrength;
	
};
