// Course Project

#include "UI/CPPlayerHUDWidget.h"
#include "Components/CPHealthComponent.h"
#include "Components/CPWeaponComponent.h"
#include "CPUtils.h"

bool UCPPlayerHUDWidget::Initialize()
{
    const auto HealthComponent = CPUtils::GetCPPlayerComponent<UCPHealthComponent>(GetOwningPlayerPawn());
    if (HealthComponent)
    {
        HealthComponent->OnHealthChanged.AddUObject(this, &UCPPlayerHUDWidget::OnHealthChange);
    }

    return Super::Initialize();
}

void UCPPlayerHUDWidget::OnHealthChange(float Health, float HealthDelta)
{
    if (HealthDelta < 0.0f)
    {
        OnTakeDamage();
    }
}

float UCPPlayerHUDWidget::GetHealthPercent() const
{

    const auto HealthComponent = CPUtils::GetCPPlayerComponent<UCPHealthComponent>(GetOwningPlayerPawn());
    if (!HealthComponent) return 0.0f;

    return HealthComponent->GetHealthPercent();
}

bool UCPPlayerHUDWidget::GetCurrentWeaponUIData(FWeaponUIData& UIData) const
{

    const auto WeaponComponent = CPUtils::GetCPPlayerComponent<UCPWeaponComponent>(GetOwningPlayerPawn());
    if (!WeaponComponent) return false;

    return WeaponComponent->GetCurrentWeaponUIData(UIData);
}

bool UCPPlayerHUDWidget::GetCurrentWeaponAmmoData(FAmmoData& AmmoData) const
{

    const auto WeaponComponent = CPUtils::GetCPPlayerComponent<UCPWeaponComponent>(GetOwningPlayerPawn());
    if (!WeaponComponent) return false;

    return WeaponComponent->GetCurrentWeaponAmmoData(AmmoData);
}

bool UCPPlayerHUDWidget::IsPlayerAlive() const
{
    const auto HealthComponent = CPUtils::GetCPPlayerComponent<UCPHealthComponent>(GetOwningPlayerPawn());
    return HealthComponent && !HealthComponent->IsDead();
}

bool UCPPlayerHUDWidget::IsPlayerSpectating() const
{
    const auto Controller = GetOwningPlayer();
    return Controller && Controller->GetStateName() == NAME_Spectating;
}
