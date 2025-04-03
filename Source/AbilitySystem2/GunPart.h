// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "DamageEffect.h"
#include "GunPart.generated.h"

UENUM()
enum class EWpnPartType : uint8
{
	Handle,
	Cannon,
	Visor,
	GripPoint,
	Clip
};

UCLASS(Blueprintable, BlueprintType)
class ABILITYSYSTEM2_API UGunPart : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visuals")
	TObjectPtr<UStaticMesh> Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visuals")
	TObjectPtr<UMaterial> Material;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visuals")
	FVector MeshScale = FVector(1.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visuals")
	FVector MeshRotation = FVector(0.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modular Gun System")
	EWpnPartType WeaponType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modular Gun System")
	TArray< TSubclassOf<UAbility>> ShootAbilities;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modular Gun System")
	TArray<TSubclassOf<UDamageEffect>> Effects;
};
