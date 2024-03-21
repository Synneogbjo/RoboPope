// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Weapon.h"
#include "Kismet/GameplayStatics.h"


UCPP_Weapon::UCPP_Weapon()
{
	World = GetWorld();
}

void UCPP_Weapon::DoOnPurchase()
{
	//Set up player character 
	// S
	//Player = Cast<ACPP_Player>(UGameplayStatics::GetPlayerCharacter(World, 0));
	//Alternatively: Have Store/Player purchase function do this. It works the same but it's more adaptable probably.
	
}

void UCPP_Weapon::PrimaryFire()
{
	if (UCPP_Weapon::CanTrigger() == 0) {
		FTimerHandle Handle;
		World->GetTimerManager().SetTimer(Handle, this, &UCPP_Weapon::ResetFireState, FireInterval, false);
	}
}

void UCPP_Weapon::SecondaryFire()
{
}

void UCPP_Weapon::Reload()
{
}

void UCPP_Weapon::ResetFireState() {
	bCanFire = true;
};

int UCPP_Weapon::CanTrigger() {
	if (bCanFire == true && bIsReloading == false) {
		return 0;
	}
	else if (Ammo <= 0) {
		if (NoAmmoSound != nullptr) {
			UGameplayStatics::PlaySoundAtLocation(this, NoAmmoSound, Player->GetActorLocation());
		}
		return 0;
	}
	else return 1;
}

void UCPP_Weapon::BeginPlay(){

}