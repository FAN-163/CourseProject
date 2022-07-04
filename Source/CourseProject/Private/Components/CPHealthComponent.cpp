// Course Project

#include "Components/CPHealthComponent.h"

UCPHealthComponent::UCPHealthComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UCPHealthComponent::BeginPlay()
{
    Super::BeginPlay();

    Health = MaxHealth;
}
