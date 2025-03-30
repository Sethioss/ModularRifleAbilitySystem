// Fill out your copyright notice in the Description page of Project Settings.


#include "ModularWeaponComponent.h"
#include "ModularRifle.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMeshActor.h"
#include "Ability.h"

void UTP_ModularWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	UpdateWeaponParts();
}

void UTP_ModularWeaponComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void UTP_ModularWeaponComponent::Fire()
{
	Super::Fire();

	for (int i = 0; i < GunParts.Num(); i++)
	{
		if (GunParts[i])
		{
			UGunPart* GunPart = Cast<UGunPart>(GunParts[i]->GetDefaultObject());

			for (TSubclassOf<UAbility> AbilityClass : GunPart->ShootAbilities)
			{
				UAbility* Ability = NewObject<UAbility>(this, AbilityClass);

				if (Ability)
				{
					//Test to see if on shoot is called
					Ability->OnShoot(nullptr, nullptr);

					UEmbarkedDataSet* DataSet = NewObject<UEmbarkedDataSet>();
					DataSet->AbilityName = Ability->GetName();

					ProjectileThrown->OnTraversalDelegate.AddDynamic(Ability, &UAbility::OnTraversal);
					ProjectileThrown->OnHitDelegate.AddDynamic(Ability, &UAbility::OnHit);
					ProjectileThrown->OnHitWallDelegate.AddDynamic(Ability, &UAbility::OnHitWall);
					ProjectileThrown->OnMissDelegate.AddDynamic(Ability, &UAbility::OnMiss);
					ProjectileThrown->OnApplyEffectsDelegate.AddDynamic(Ability, &UAbility::OnApplyEffects);
				}
			}
		}		
	}
}

void UTP_ModularWeaponComponent::UpdateWeaponParts()
{
	for (int i = 0; i < GunPartComponents.Num(); i++)
	{
		GunPartComponents[i]->DestroyComponent();
	}

	GunPartComponents.Empty();

	for (int i = 0; i < GunParts.Num(); i++)
	{
		if (GunParts[i])
		{
			UGunPart* GunPart = Cast<UGunPart>(GunParts[i]->GetDefaultObject());
			if (GunPart->Mesh)
			{
				UStaticMesh* PartMesh = GunPart->Mesh;

				const UEnum* PartType = StaticEnum<EWpnPartType>();

				FText TextRepresentation = PartType->GetDisplayNameTextByValue((int64)GunPart->WeaponType);
				FName DisplayName = FName(*TextRepresentation.ToString());
				UE_LOG(LogTemp, Log, TEXT("ModularWeaponComponent.cpp:: Weapon Part type: %s"), *TextRepresentation.ToString());

				UStaticMeshComponent* MeshComp = NewObject<UStaticMeshComponent>(GetOwner(), UStaticMeshComponent::StaticClass(), DisplayName);

				if (MeshComp)
				{

					MeshComp->RegisterComponent();
					MeshComp->SetStaticMesh(GunPart->Mesh);
					MeshComp->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
					MeshComp->SetWorldScale3D(GunPart->MeshScale);
					MeshComp->SetWorldRotation(FQuat::MakeFromEuler(GunPart->MeshRotation));

					if (GunPart->Material)
					{
						MeshComp->SetMaterial(0, GunPart->Material);
					}

					ensureMsgf(DoesSocketExist(DisplayName), TEXT("The socket %s for weapon part %s doesn't seem to exist. Please make sure the gun's skeletal mesh has a socket with the appropriate name"), *TextRepresentation.ToString(), *GunPart->GetName());
					MeshComp->AttachToComponent(this, FAttachmentTransformRules::KeepRelativeTransform, DisplayName);

					GunPartComponents.Add(MeshComp);
				}
			}
			else
			{
				ensureMsgf(GunPart->Mesh, TEXT("MeshComp for part %s couldn't be created. Please ensure it actually has a mesh."), *GunPart->GetName());
				continue;
			}
		}		
	}
}