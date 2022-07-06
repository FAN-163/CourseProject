// Course Project

#include "Components/CPWeaponComponent.h"
#include "Weapon/CPBaseWeapon.h"
#include "GameFramework/Character.h"

UCPWeaponComponent::UCPWeaponComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UCPWeaponComponent::BeginPlay()
{
    Super::BeginPlay();

    SpawnWeapon();
}

void UCPWeaponComponent::SpawnWeapon()
{
    if (!GetWorld()) return;

    ACharacter* Character = Cast<ACharacter>(GetOwner());
    if (!Character) return;

    CurrentWeapon = GetWorld()->SpawnActor<ACPBaseWeapon>(WeaponClass);
    if (!CurrentWeapon) return;

    FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, false);
    CurrentWeapon->AttachToComponent(Character->GetMesh(), AttachmentRules, WeaponAttachPointName);
    CurrentWeapon->SetOwner(Character);
}

void UCPWeaponComponent::StartFire()
{
    if (!CurrentWeapon) return;
    CurrentWeapon->StartFire();
}
void UCPWeaponComponent::StopFire()
{
    if (!CurrentWeapon) return;
    CurrentWeapon->StopFire();
}
