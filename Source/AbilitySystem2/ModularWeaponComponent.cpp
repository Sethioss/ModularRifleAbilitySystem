// Fill out your copyright notice in the Description page of Project Settings.


#include "ModularWeaponComponent.h"
#include "ModularRifle.h"
#include "EmbarkedDataSet.h"
#include "Ability.h"

void UTP_ModularWeaponComponent::Fire()
{
	Super::Fire();

	AModularRifle* Rifle = Cast<AModularRifle>(GetOwner());
	if (Rifle)
	{
		TArray<UGunPartComponent*> GunCompList = Rifle->GetModularWeaponParts();
		for (int i = 0; i < GunCompList.Num(); ++i)
		{
			for (TSubclassOf<UAbility> AbilityClass : GunCompList[i]->ShootAbilities)
			{
				UAbility* Ability = NewObject<UAbility>(this, AbilityClass);

				if (Ability)
				{
					//Test to see if on shoot is called
					Ability->OnShoot(nullptr, nullptr);

					UEmbarkedDataSet* DataSet = NewObject<UEmbarkedDataSet>();
					DataSet->AbilityName = Ability->GetName();
					DataSet->DataAsset = NewObject<UGunPartDataAsset>(Ability->RelevantStats);
					DataSet->DataAsset = Ability->RelevantStats;
					ProjectileThrown->EmbarkedData.Add(DataSet);
					
					//ProjectileThrown->RelevantStats = NewObject<UGunPartDataAsset>(Ability->RelevantStats);
					//ProjectileThrown->RelevantStats = Ability->RelevantStats;

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

void UTP_ModularWeaponComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

