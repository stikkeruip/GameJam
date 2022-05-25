// Fill out your copyright notice in the Description page of Project Settings.


#include "GameJamController.h"

#include "GhostCharacter.h"

void AGameJamController::BeginPlay()
{
	Super::BeginPlay();

	CharRef = Cast<AGhostCharacter>(this->GetCharacter());
	
	if(InputComponent)
	{
		InputComponent->BindAxis("Left/Right", this, &AGameJamController::MoveRight);
		InputComponent->BindAxis("Up/Down", this, &AGameJamController::MoveUp);
		InputComponent->BindAction("Interact", EInputEvent::IE_Pressed, this, &AGameJamController::Interact);
	}
}

void AGameJamController::MoveRight(float value)
{
	FRotator const ControlSpaceRot = GetControlRotation();

	GetPawn()->AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::X), value);
}

void AGameJamController::MoveUp(float value)
{
	FRotator const ControlSpaceRot = GetControlRotation();

	GetPawn()->AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::Y), value);
}

void AGameJamController::Interact()
{
	CharRef->Interact();
}