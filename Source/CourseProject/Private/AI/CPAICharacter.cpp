// Course Project

#include "AI/CPAICharacter.h"
#include "AI/CPAIController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CPAIWeaponComponent.h"
#include "BrainComponent.h"

ACPAICharacter::ACPAICharacter(const FObjectInitializer& ObjInit)
    : Super(ObjInit.SetDefaultSubobjectClass<UCPAIWeaponComponent>("WeaponComponent"))
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

void ACPAICharacter::OnDeath()
{
    Super::OnDeath();

    const auto CPController = Cast<AAIController>(Controller);
    if (CPController && CPController->BrainComponent)
    {
        CPController->BrainComponent->Cleanup();
    }
}
