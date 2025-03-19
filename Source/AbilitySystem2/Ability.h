// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
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
	TObjectPtr<UDataAsset> RelevantStats;

	UFUNCTION(BlueprintNativeEvent)
	void OnShoot(AActor* Instigator, AActor* HitActor);

	UFUNCTION(BlueprintNativeEvent)
	void OnTraversal();

	UFUNCTION(BlueprintNativeEvent)
	void OnHit(AActor* Instigator, AActor* Bullet, AActor* HitActor);

	UFUNCTION(BlueprintNativeEvent)
	void OnHitWall(AActor* Instigator, AActor* HitActor);

	UFUNCTION(BlueprintNativeEvent)
	void OnMiss(AActor* Instigator);

	UFUNCTION(BlueprintNativeEvent)
	void OnApplyEffects();

	void PassStatsToBullet();
};
