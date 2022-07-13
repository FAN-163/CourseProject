// Course Project

#include "Pickups/CPAmmoPickup.h"
#include "Components/CPHealthComponent.h"
#include "Components/CPWeaponComponent.h"
#include "CPUtils.h"

DEFINE_LOG_CATEGORY_STATIC(LogAmmoPickup, All, All)

bool ACPAmmoPickup::GivePickupTo(APawn* PlayerPawn)
{
    const auto HealthComponent = CPUtils::GetCPPlayerComponent<UCPHealthComponent>(PlayerPawn);
    if (!HealthComponent || HealthComponent->IsDead()) return false;

    const auto WeaponComponent = CPUtils::GetCPPlayerComponent<UCPWeaponComponent>(PlayerPawn);
    if (!WeaponComponent) return false;

    return WeaponComponent->TryToAddAmmo(WeaponType, ClipsAmount);
}