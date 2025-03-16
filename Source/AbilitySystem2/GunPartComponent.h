// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Ability.h"
#include "DamageEffect.h"
#include "GunPartDataAsset.h"
#include "GunPartComponent.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class ABILITYSYSTEM2_API UGunPartComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modular Gun System")
	TObjectPtr<UGunPartDataAsset> PartDataAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modular Gun System")
	TArray< TSubclassOf<UAbility>> ShootAbilities;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modular Gun System")
	TArray<TSubclassOf<UDamageEffect>> Effects;
	
};
