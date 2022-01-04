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

	FVector CurrentLocation = GetActorLocation();
	FVector Gravity = { 0,0, -1.0f }; //0.098f * DeltaTime};
	FVector NewLocation = CurrentLocation + Gravity;
	// Standard way to log to console.
	UE_LOG(LogTemp, Warning, TEXT("I just started running"));

	// Log to Screen
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("TICK"));

	FVector MyVector = FVector(200, 100, 900);

	// log vector
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, FString::Printf(TEXT("My CUR Location is: %s"), *CurrentLocation.ToString()));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, FString::Printf(TEXT("My NEW Location is: %s"), *NewLocation.ToString()));

	// translate position accd. to gravity -> 9.8m/s
	SetActorLocation(NewLocation, true);



}

