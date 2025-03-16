// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ability.h"
#include "Bullet.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBulletTraversalSignature);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHitSignature, AActor*, Instigator, AActor*, HitActor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHitWallSignature, AActor*, Instigator, AActor*, HitActor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMissSignature, AActor*, Instigator);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnApplyEffectsSignature);


UCLASS()
class ABILITYSYSTEM2_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();
	ABullet(TObjectPtr<UAbility> SpawnAbility);

	FOnBulletTraversalSignature OnTraversalDelegate;
	
	FOnHitSignature OnHitDelegate;
	
	FOnHitWallSignature OnHitWallDelegate;
	
	FOnMissSignature OnMissDelegate;
	
	FOnApplyEffectsSignature OnApplyEffectsDelegate;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	TMap<FString, float> PassedStats;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
