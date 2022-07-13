// Course Project


#include "Pickups/CPHealthPickup.h"
#include "Components/CPHealthComponent.h"
#include "CPUtils.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthPickup, All, All)

bool ACPHealthPickup::GivePickupTo(APawn* PlayerPawn)
{
    const auto HealthComponent = CPUtils::GetCPPlayerComponent<UCPHealthComponent>(PlayerPawn);
    if (!HealthComponent) return false;

    return HealthComponent->TryToAddHealth(HealthAmount);
}