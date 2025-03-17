// Fill out your copyright notice in the Description page of Project Settings.


#include "ModularWeaponComponent.h"
#include "ModularRifle.h"
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
					Ability->OnShoot(nullptr, nullptr);

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
