// Course Project

#include "UI/CPPlayerHUDWidget.h"
#include "Components/CPHealthComponent.h"
#include "Components/CPWeaponComponent.h"


float UCPPlayerHUDWidget::GetHealthPercent() const
{
    
    const auto HealthComponent = GetHealthComponent();
    if (!HealthComponent) return 0.0f;

    return HealthComponent->GetHealthPercent();
}

 bool UCPPlayerHUDWidget::GetCurrentWeaponUIData(FWeaponUIData& UIData) const
{
    
    const auto WeaponComponent = GetWeaponComponent();
    if (!WeaponComponent) return false;

    return WeaponComponent->GetCurrentWeaponUIData(UIData);
}

bool UCPPlayerHUDWidget::GetCurrentWeaponAmmoData(FAmmoData& AmmoData) const
{
    
    const auto WeaponComponent = GetWeaponComponent();
    if (!WeaponComponent) return false;

    return WeaponComponent->GetCurrentWeaponAmmoData(AmmoData);
}

bool UCPPlayerHUDWidget::IsPlayerAlive() const
{
    const auto HealthComponent = GetHealthComponent();
    return HealthComponent && !HealthComponent->IsDead();
}

bool UCPPlayerHUDWidget::IsPlayerSpectating() const
{
    const auto Controller = GetOwningPlayer();
    return Controller && Controller->GetStateName() == NAME_Spectating;
}

UCPWeaponComponent* UCPPlayerHUDWidget::GetWeaponComponent() const
{
    const auto Player = GetOwningPlayerPawn();
    if (!Player) return nullptr;

    const auto Component = Player->GetComponentByClass(UCPWeaponComponent::StaticClass());
    const auto WeaponComponent = Cast<UCPWeaponComponent>(Component);
    return WeaponComponent;
}

UCPHealthComponent* UCPPlayerHUDWidget::GetHealthComponent() const
{
    const auto Player = GetOwningPlayerPawn();
    if (!Player) return nullptr;

    const auto Component = Player->GetComponentByClass(UCPHealthComponent::StaticClass());
    const auto HealthComponent = Cast<UCPHealthComponent>(Component);
    return HealthComponent;
}