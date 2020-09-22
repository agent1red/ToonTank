// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"


APawnTurret::APawnTurret()
{

}

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();
	
    //Implement timers to bind and control tiemr handler 
    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void APawnTurret::CheckFireCondition() 
{
    //If Player == null || is dead then stop firing 

    // Of Player IS in range Then fire 

    UE_LOG(LogTemp, Warning, TEXT("Fire Condition Checked"));
}
