// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "CPP_Player.h"
#include "CPP_Weapon.generated.h"

/**
 * 
 */
UCLASS()
class ROBOPOPE_API UCPP_Weapon : public USkeletalMeshComponent
{
	GENERATED_BODY()

public:
	UCPP_Weapon();
	virtual void DoOnPurchase();
	virtual void PrimaryFire();
	virtual void SecondaryFire();
	virtual void Reload();
protected:
	//Variables for weapon.

	void ResetFireState();
	int CanTrigger();
	virtual void BeginPlay() override;


	FVector WeaponOffset;

	//Is the weapon fully automatic?
	bool bIsAutomatic;
	//Max ammo.
	unsigned int AmmoMax;
	//Current Ammo.
	unsigned int Ammo;
	//Weapon clip size before reloading.
	unsigned int AmmoClip;
	//Rate of fire as defined by time interval between shots.
	float FireInterval;
	//
	float ReloadTime;

	// Checks for reload and
	bool bIsReloading;
	bool bCanFire;

	UWorld* World;

	

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category="Visual")
	USkeletalMeshComponent* Mesh = nullptr;
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Visual")
	UAnimMontage* TriggerAnimation = nullptr;
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Visual")
	UAnimMontage* AltTriggerAnimation = nullptr;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Audio")
	USoundBase* FireSound = nullptr;
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Audio")
	USoundBase* AltFireSound = nullptr;
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Audio")
	USoundBase* NoAmmoSound = nullptr;


	ACPP_Player* Player = nullptr;
};