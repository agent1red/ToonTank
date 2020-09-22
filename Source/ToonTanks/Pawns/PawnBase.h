// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"  

class UCapsuleComponent;

UCLASS()
class TOONTANKS_API APawnBase : public APawn
{
	GENERATED_BODY()

private:

	// root component general collision for pawn - forward declared
	UPROPERTY()
	UCapsuleComponent* CapsuleComp;

	//Base (Or bottom of tank)
	UPROPERTY()
	UStaticMeshComponent* BaseMesh;

	//Turret component
	UPROPERTY()
	UStaticMeshComponent* TurretMesh;

	//Pojectile spawned from where to fire bullets
	UPROPERTY()	
	USceneComponent* ProjectileSpawnPoint;

public:
	// Sets default values for this pawn's properties
	APawnBase();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
