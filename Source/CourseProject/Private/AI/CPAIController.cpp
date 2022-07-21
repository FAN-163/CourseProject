// Course Project

#include "AI/CPAIController.h"
#include "AI/CPAICharacter.h"
#include "Components/CPAIPerceptionComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

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
    const auto AimActor = GetFocusOnActor();
    SetFocus(AimActor);
}

AActor* ACPAIController::GetFocusOnActor() const
{
    if (!GetBlackboardComponent()) return nullptr;
    return Cast<AActor>(GetBlackboardComponent()->GetValueAsObject(FocusOnKeyName));
}
