// Course Project

#include "AI/CPAICharacter.h"
#include "AI/CPAIController.h"

ACPAICharacter::ACPAICharacter(const FObjectInitializer& ObjInit):Super(ObjInit)
{
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
    AIControllerClass = ACPAIController::StaticClass();
}
