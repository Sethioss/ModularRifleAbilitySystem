// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_Entity.generated.h"

/**
 * 
 */
UCLASS()
class ABILITYSYSTEM2_API UDA_Entity : public UDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float Health;

	UPROPERTY(EditAnywhere)
	float Speed;
};
