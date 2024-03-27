// Fill out your copyright notice in the Description page of Project Settings.

// All code is the work of Bjorn Haugen, unless otherwise is specified

#include "CPP_Church.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ACPP_Church::ACPP_Church()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	BoxCollider->SetBoxExtent(FVector(500.f, 500.f, 500.f));
	BoxCollider->SetupAttachment(GetRootComponent());



}

// Called when the game starts or when spawned
void ACPP_Church::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_Church::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_Church::TakeDamage(float Damage)
{
	Health -= Damage;

	ChurchUpdateHealthDelegate.Broadcast(Health, MaxHealth);
}

void ACPP_Church::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	return;
}
