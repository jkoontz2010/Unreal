// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PCustomPhysicsSphere.generated.h"

class USphereComponent;

UCLASS()
class UNREAL_API APCustomPhysicsSphere : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APCustomPhysicsSphere();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* SphereComp;

	float Speed;
	bool bHasTicked;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
