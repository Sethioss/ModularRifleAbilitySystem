// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Bullet.h"
#include "DamageEffect.generated.h"

UENUM()
enum class EEffectType : uint8
{
	Burn,
	Stun,
	Freeze
};

/**
 * 
 */
UCLASS()
class ABILITYSYSTEM2_API UDamageEffect : public UObject
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere)
	TObjectPtr<UDataAsset> RelevantStats;

	UPROPERTY(EditAnywhere)
	EEffectType EffectType;

	void PassStatsToBullet(TObjectPtr<ABullet> Bullet);
	void ApplyEffects();
	
};
