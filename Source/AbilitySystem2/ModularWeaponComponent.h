// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TP_WeaponComponent.h"
#include "Ability.h"
#include "GunPart.h"
#include "ModularWeaponComponent.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class ABILITYSYSTEM2_API UTP_ModularWeaponComponent : public UTP_WeaponComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GunParts")
	TArray<TSubclassOf<UGunPart>> GunParts;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UAbility> ReloadingAbility;

	UPROPERTY()
	TArray<TSubclassOf<UAbility>> ShootAbilities;

	void UpdateWeaponParts();


protected:
	virtual void Fire() override;

	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	TArray<UStaticMeshComponent*> GunPartComponents;
};
