// Course Project

#include "AI/CPAIController.h"
#include "AI/CPAICharacter.h"

void ACPAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    const auto CPCharacter = Cast<ACPAICharacter>(InPawn);
    if (CPCharacter)
    {
        RunBehaviorTree(CPCharacter->BehaviorTreeAsset);
    }
}
