// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GunPartDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class ABILITYSYSTEM2_API UGunPartDataAsset : public UDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	int Priority = 0;

	UPROPERTY(EditAnywhere)
	float DamageBonus = 20.0f;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMesh> Mesh;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UMaterialInstance> Mat;
	
};
