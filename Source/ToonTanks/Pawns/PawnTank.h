// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTank.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class TOONTANKS_API APawnTank : public APawnBase
{
	GENERATED_BODY()

	private: 

		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		USpringArmComponent* SpringArm;
		
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UCameraComponent* Camera;

		FVector MoveDirection;
		FQuat RotationDirection;

		float MoveSpeed = 100.0f;
		float RotateSpeed = 100.0f;

		//Bound to movment function (Forward = 1, Backward = -1) axis binding input
		void CalculateMoveInput(float Value);

		//Bound to rotation axis binding input
		void CalculateRotateInput(float Value);

		// called on the run tick for moving or rotation based on the calculate functions 
		void Move();
		void Rotate();

	public:

		// Sets default values for this pawn's properties
		APawnTank();
		// Called every frame
		virtual void Tick(float DeltaTime) override;

		// Called to bind functionality to input
		virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;
	
};
