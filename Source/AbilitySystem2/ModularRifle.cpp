// Fill out your copyright notice in the Description page of Project Settings.


#include "ModularRifle.h"

// Sets default values
AModularRifle::AModularRifle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	WeaponComponent = CreateDefaultSubobject<UTP_ModularWeaponComponent>(TEXT("Modular Weapon Component"));
	RootComponent = WeaponComponent;

	PickUpComponent = CreateDefaultSubobject<UTP_PickUpComponent>(TEXT("PickUpComponent"));
	PickUpComponent->SetupAttachment(WeaponComponent);

	//Magazine = CreateDefaultSubobject<UGunPartComponent>(TEXT("Magazine"));
	//Magazine->SetupAttachment(WeaponComponent);
	//Magazine->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	//
	//Cannon = CreateDefaultSubobject<UGunPartComponent>(TEXT("Cannon"));
	//Cannon->SetupAttachment(WeaponComponent);
	//Cannon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	//
	//Handle = CreateDefaultSubobject<UGunPartComponent>(TEXT("Handle"));
	//Handle->SetupAttachment(WeaponComponent);
	//Handle->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void AModularRifle::BeginPlay()
{
	Super::BeginPlay();
	
}

void AModularRifle::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

// Called every frame
void AModularRifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TArray<UGunPartComponent*> AModularRifle::GetModularWeaponParts()
{
	TArray<UGunPartComponent*> Comps;
	GetComponents<UGunPartComponent>(Comps);
	return Comps;
}

