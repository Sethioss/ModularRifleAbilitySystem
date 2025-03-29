// Fill out your copyright notice in the Description page of Project Settings.


#include "ModularWeaponComponent.h"
#include "ModularRifle.h"
#include "EmbarkedDataSet.h"
#include "Ability.h"

void UTP_ModularWeaponComponent::Fire()
{
	Super::Fire();

	for (int i = 0; i < GunParts.Num(); i++)
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

