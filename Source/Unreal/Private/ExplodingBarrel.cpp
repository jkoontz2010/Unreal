// Fill out your copyright notice in the Description page of Project Settings.


#include "ExplodingBarrel.h"

// Sets default values
AExplodingBarrel::AExplodingBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AExplodingBarrel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AExplodingBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

