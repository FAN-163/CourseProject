// Course Project

#include "UI/CPPlayerHUDWidget.h"
#include "Components/CPHealthComponent.h"

float UCPPlayerHUDWidget::GetHealthPercent() const
{
    const auto Player = GetOwningPlayerPawn();
    if (!Player) return 0.0f;

    const auto Component = Player->GetComponentByClass(UCPHealthComponent::StaticClass());
    const auto HealthComponent = Cast<UCPHealthComponent>(Component);
    if (!HealthComponent) return 0.0f;

    return HealthComponent->GetHealthPercent();
}