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

	UFUNCTION(BlueprintImplementableEvent)
	void OnTraversal();

	UFUNCTION(BlueprintImplementableEvent)
	void OnHit(AActor* Instigator, AActor* HitActor);

	UFUNCTION(BlueprintImplementableEvent)
	void OnHitWall(AActor* Instigator, AActor* HitActor);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMiss(AActor* Instigator);

	UFUNCTION(BlueprintImplementableEvent)
	void OnApplyEffects();

	void PassStatsToBullet();
};
