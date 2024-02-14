// Copyright Epic Games, Inc. All Rights Reserved.

#include "GardenersRushGameMode.h"
#include "GardenersRushPlayerController.h"
#include "GardenersRushCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGardenersRushGameMode::AGardenersRushGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AGardenersRushPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}