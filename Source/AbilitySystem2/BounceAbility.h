// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "BounceDataAsset.h"
#include "BounceAbility.generated.h"

/**
 * 
 */
UCLASS()
class ABILITYSYSTEM2_API UBounceAbility : public UAbility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UBounceDataAsset> BounceDataAsset;
	
};
