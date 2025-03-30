// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GunPartDataAsset.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class ABILITYSYSTEM2_API UGunPartDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AmmoImprovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ReloadTimeImprovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PowerImprovement;	
};
