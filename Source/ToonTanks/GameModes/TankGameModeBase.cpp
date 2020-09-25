// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameModeBase.h"

void ATankGameModeBase::BeginPlay() 
{
    // Get ref and game win/loose conditions

    // Call HandleGameStart() to initialise the start countdown, turret activation, pawn check etc. 
}

void ATankGameModeBase::ActorDied(AActor* DeadActor) 
{
    // Check what type of actor died If Turret, tally. If Player -> go to lose condition
}

void ATankGameModeBase::HandleGameStart() 
{
    
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon) 
{
    
}



