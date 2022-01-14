// Fill out your copyright notice in the Description page of Project Settings.


#include "SDashProjectile.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

ASDashProjectile::ASDashProjectile()
{
	TeleportDelay = .2f;
	DetonateDelay = .2f;

	MoveComp->InitialSpeed = 6000.f;

}

void ASDashProjectile::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(TimeHandle_DelayedDetonate, this, &ASDashProjectile::Explode, DetonateDelay);

}
void ASDashProjectile::Explode_Implementation()
{
	GetWorldTimerManager().ClearTimer(TimeHandle_DelayedDetonate);

	UGameplayStatics::SpawnEmitterAtLocation(this, ImpactVFX, GetActorLocation(), GetActorRotation());

	EffectComp->DeactivateSystem();

	MoveComp->StopMovementImmediately();
	SetActorEnableCollision(false);

	FTimerHandle TimerHandle_DelayedTeleport;
	GetWorldTimerManager().SetTimer(TimerHandle_DelayedTeleport, this, &ASDashProjectile::TeleportInstigator, TeleportDelay);
}

void ASDashProjectile::TeleportInstigator()
{
	AActor* ActorToTeleport = GetInstigator();

	if (ensure(ActorToTeleport)) {
		ActorToTeleport->TeleportTo(GetActorLocation(), ActorToTeleport->GetActorRotation(), false, false);
	}
}

