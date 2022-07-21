// Course Project

#include "AI/CPAICharacter.h"
#include "AI/CPAIController.h"
#include "GameFramework/CharacterMovementComponent.h"

ACPAICharacter::ACPAICharacter(const FObjectInitializer& ObjInit):Super(ObjInit)
{
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
    AIControllerClass = ACPAIController::StaticClass();

    bUseControllerRotationYaw = false;
    if (GetCharacterMovement())
    {
        GetCharacterMovement()->bUseControllerDesiredRotation = true;
        GetCharacterMovement()->RotationRate = FRotator(0.0f, 200.0f, 0.0f);
    }
}
