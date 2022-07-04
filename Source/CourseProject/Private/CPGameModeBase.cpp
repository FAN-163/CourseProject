// Course Project


#include "CPGameModeBase.h"
#include "Player/CPPlayerController.h"
#include "Player/CPBaseCharacter.h"
#include "UI/CPGameHUD.h"


ACPGameModeBase::ACPGameModeBase() 
{
    DefaultPawnClass = ACPBaseCharacter::StaticClass();
    PlayerControllerClass = ACPPlayerController::StaticClass();
    HUDClass = ACPGameHUD::StaticClass();
}