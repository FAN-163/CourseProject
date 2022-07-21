// Course Project

#include "AI/CPAIController.h"
#include "AI/CPAICharacter.h"
#include "Components/CPAIPerceptionComponent.h"

ACPAIController::ACPAIController()
{
    CPAIPerceptionComponent = CreateDefaultSubobject<UCPAIPerceptionComponent>("CPAIPerceptionComponent");
    SetPerceptionComponent(*CPAIPerceptionComponent);
}

void ACPAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    const auto CPCharacter = Cast<ACPAICharacter>(InPawn);
    if (CPCharacter)
    {
        RunBehaviorTree(CPCharacter->BehaviorTreeAsset);
    }
}

void ACPAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    const auto AimActor = CPAIPerceptionComponent->GetClosestEnemy();
    SetFocus(AimActor);
}
