// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GunPartDataAsset.generated.h"

UENUM()
enum class EWpnPartType : uint8
{
	Cross,
	Handle,
	Magazine,
	Cannon,
	Hammer
};

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class ABILITYSYSTEM2_API UGunPartDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EWpnPartType WeaponType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMesh> Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UMaterialInstance> Mat;
	
};
