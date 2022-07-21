// Course Project


#include "AI/Services/CPChangeWeaponService.h"
#include "Components/CPWeaponComponent.h"
#include "AIController.h"
#include "CPUtils.h"

UCPChangeWeaponService::UCPChangeWeaponService()
{
    NodeName = "Change Weapon";
}

void UCPChangeWeaponService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    if (const auto Controller = OwnerComp.GetAIOwner())
    {
        const auto WeaponComponent = CPUtils::GetCPPlayerComponent<UCPWeaponComponent>(Controller->GetPawn());
        if (WeaponComponent && Probability > 0 && FMath::FRand() <= Probability)
        {
            WeaponComponent->NextWeapon();
        }
    }

    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}