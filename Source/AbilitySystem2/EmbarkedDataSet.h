// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GunPartDataAsset.h"
#include "EmbarkedDataSet.generated.h"

/**
 * 
 */
UCLASS()
class ABILITYSYSTEM2_API UEmbarkedDataSet : public UObject
{
	GENERATED_BODY()

public:

	UEmbarkedDataSet();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "EmbarkedData")
	FString AbilityName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "EmbarkedData")
	TObjectPtr<UGunPartDataAsset> DataAsset;
};
