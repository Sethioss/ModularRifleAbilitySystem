// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "GunPartDataAsset.h"
#include "Ability.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class ABILITYSYSTEM2_API UAbility : public UObject
{
	GENERATED_BODY()

public:
		
	UPROPERTY(EditAnywhere)
	TObjectPtr<UGunPartDataAsset> RelevantStats;

	UFUNCTION(BlueprintNativeEvent)
	void OnShoot(AActor* Instigator, AActor* HitActor);

	UFUNCTION(BlueprintNativeEvent)
	void OnTraversal();

	UFUNCTION(BlueprintNativeEvent)
	void OnHit(AActor* Instigator, AActor* Bullet, FHitResult HitResult);

	UFUNCTION(BlueprintNativeEvent)
	void OnHitWall(AActor* Bullet, FHitResult HitResult);

	UFUNCTION(BlueprintNativeEvent)
	void OnMiss(AActor* Bullet);

	UFUNCTION(BlueprintNativeEvent)
	void OnApplyEffects();

	void PassStatsToBullet();
};
