// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GunPartComponent.h"
#include "ModularWeaponComponent.h"
#include "TP_PickUpComponent.h"
#include "GameFramework/Actor.h"
#include "ModularRifle.generated.h"

UCLASS()
class ABILITYSYSTEM2_API AModularRifle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AModularRifle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UTP_ModularWeaponComponent> WeaponComponent = nullptr;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UTP_PickUpComponent> PickUpComponent = nullptr;

	void ChangeWeaponPart();
	
	//UPROPERTY(EditAnywhere, Category = "Parts")
	//TObjectPtr<UGunPartComponent> Magazine = nullptr;
	//
	//UPROPERTY(EditAnywhere, Category = "Parts")
	//TObjectPtr<UGunPartComponent> Cannon = nullptr;
	//
	//UPROPERTY(EditAnywhere, Category = "Parts")
	//TObjectPtr<UGunPartComponent> Handle = nullptr;
	//
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//TObjectPtr<UDataAsset> MagazineStats = nullptr;
	//
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//TObjectPtr<UDataAsset> CannonStats = nullptr;
	//
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//TObjectPtr<UDataAsset> HandleStats = nullptr;
};
