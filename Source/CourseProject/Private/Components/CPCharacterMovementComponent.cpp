// Course Project


#include "Components/CPCharacterMovementComponent.h"
#include "Player/CPBaseCharacter.h"

float UCPCharacterMovementComponent::GetMaxSpeed() const
{
    const float MaxSpeed = Super::GetMaxSpeed();
    const ACPBaseCharacter* Player = Cast<ACPBaseCharacter>(GetPawnOwner());
    return Player && Player->IsRunning() ? MaxSpeed * RunModifier : MaxSpeed;
}
