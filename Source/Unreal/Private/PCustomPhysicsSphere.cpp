// Fill out your copyright notice in the Description page of Project Settings.


#include "PCustomPhysicsSphere.h"
#include "Components/SphereComponent.h"

// Sets default values
APCustomPhysicsSphere::APCustomPhysicsSphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	SphereComp->SetCollisionProfileName("Projectile");
	RootComponent = SphereComp;
	Speed = 0.0f;
	bHasTicked = false;

}

// Called when the game starts or when spawned
void APCustomPhysicsSphere::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APCustomPhysicsSphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// TRY world seconds OR (1 - DeltaTime) as seconds
	FVector CurrentLocation = GetActorLocation();
	float WORLD_SEC = GetWorld()->TimeSeconds;
	float ACCEL = -980.f;
	Speed = Speed + ACCEL * DeltaTime;
	//Speed = Speed + GRAVITY;
	FVector DeltaLocation = { 0,0, DeltaTime*Speed }; //0.098f * DeltaTime};
	FVector NewLocation = CurrentLocation + DeltaLocation;

	
	// translate position accd. to gravity -> 9.8m/s
	SetActorLocation(NewLocation, true);

}

