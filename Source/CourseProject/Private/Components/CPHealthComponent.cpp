// Course Project

#include "Components/CPHealthComponent.h"
#include "GameFramework/Actor.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthComponent, All, All)

UCPHealthComponent::UCPHealthComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UCPHealthComponent::BeginPlay()
{
    Super::BeginPlay();

    Health = MaxHealth;

    AActor* ComponentOwner = GetOwner();
    if (ComponentOwner)
    {
        ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &UCPHealthComponent::OnTakeAnyDamageHandle);
    }
}

void UCPHealthComponent::OnTakeAnyDamageHandle(
    AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
    Health -= Damage;
    UE_LOG(LogHealthComponent, Display, TEXT("Damage: %f"), Damage);
}
