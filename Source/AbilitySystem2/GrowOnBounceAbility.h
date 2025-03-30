// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "GrowOnBounceDataAsset.h"
#include "GrowOnBounceAbility.generated.h"

/**
 * 
 */
UCLASS()
class ABILITYSYSTEM2_API UGrowOnBounceAbility : public UAbility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UGrowOnBounceDataAsset> BounceDataAsset;
	
};
