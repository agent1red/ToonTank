// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"


APawnTurret::APawnTurret()
{

}

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();
	
    //Implement timers to bind and control tiemr handler 
    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);

    //casting to reference tank class for the PlayerPawn in a method variable PlayerPawn
    PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this,0));

}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void APawnTurret::CheckFireCondition() 
{
    //If Player == null || is dead then stop firing 
    //PlayerPawn from cast APlawnTank in array 0 
    if(!PlayerPawn)
    {
        return;
    }
    // Of Player IS in range Then fire 
    if (ReturnDistanceToPlayer() <= FireRange)
    {
        UE_LOG(LogTemp, Warning, TEXT("Fire Range in range of pawn"));
      
    }
}

float APawnTurret::ReturnDistanceToPlayer() 
{
    // needs a float return of zero when player is not there (to avoid crash)
     if(!PlayerPawn)
    {
        return 0.0f;
    }
    // return distance from the player pawn to the turret location
    return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
    
}
