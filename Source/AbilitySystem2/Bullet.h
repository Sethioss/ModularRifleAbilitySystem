// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ability.h"
#include "AbilitySystem2Projectile.h"
#include "Engine/HitResult.h"
#include "EmbarkedDataSet.h"
#include "GunPartDataAsset.h"
#include "Bullet.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBulletTraversalSignature);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnHitSignature, AActor*, Instigator, AActor*, Bullet, FHitResult, HitResult);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHitWallSignature, AActor*, Bullet, FHitResult, HitResult);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMissSignature, AActor*, Bullet);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnApplyEffectsSignature);


UCLASS()
class ABILITYSYSTEM2_API ABullet : public AAbilitySystem2Projectile
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<UEmbarkedDataSet*> EmbarkedData;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UGunPartDataAsset> RelevantStats;

	// Sets default values for this actor's properties
	ABullet();
	ABullet(TObjectPtr<UAbility> SpawnAbility);

	FOnBulletTraversalSignature OnTraversalDelegate;

	UPROPERTY(BlueprintCallable)
	FOnHitSignature OnHitDelegate;
	UPROPERTY(BlueprintCallable)
	FOnHitWallSignature OnHitWallDelegate;
	UPROPERTY(BlueprintCallable)
	FOnMissSignature OnMissDelegate;
	UPROPERTY(BlueprintCallable)
	FOnApplyEffectsSignature OnApplyEffectsDelegate;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TMap<FString, float> PassedStats;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<AActor> BulletSource = nullptr;

	UFUNCTION(BlueprintCallable)
	UGunPartDataAsset* FindDataAssetByName(FName Name);

};
