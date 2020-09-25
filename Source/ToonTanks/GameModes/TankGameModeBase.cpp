// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameModeBase.h"
#include "ToonTanks/Pawns/PawnTank.h"
#include "ToonTanks/Pawns/PawnTurret.h"
#include "Kismet/GameplayStatics.h"

void ATankGameModeBase::BeginPlay() 
{
    Super::BeginPlay();

    // how many turret for the player to destroy
    TArray<AActor*> TurretActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), APawnTurret::StaticClass(), TurretActors);
    TargetTurrets = TurretActors.Num();

    PlayerTank = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void ATankGameModeBase::ActorDied(AActor* DeadActor) 
{
    // Check what type of actor died If Turret, tally. If Player -> go to lose condition.
    UE_LOG(LogTemp, Warning, TEXT("A Pawn died"));
}

void ATankGameModeBase::HandleGameStart() 
{
    // Initialise start countdown, turret activation, pawn check etc.
    // Call Blueprint version GameStart();
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon) 
{
    // See if the player has destroyed all the turrets, show win result.
    // else if turret destroyed player, show lose result.
    // Call Blueprint version GameOver(bool)
}



