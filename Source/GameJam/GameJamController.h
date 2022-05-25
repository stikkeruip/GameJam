// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameJamController.generated.h"

class AGhostCharacter;
/**
 * 
 */
UCLASS()
class GAMEJAM_API AGameJamController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	void MoveRight(float value);

	void MoveUp(float value);

	void Interact();

	AGhostCharacter* CharRef;
};


