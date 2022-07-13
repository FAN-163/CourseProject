// Course Project

#include "Weapon/Components/CPWeaponFXComponent.h"
#include "NiagaraFunctionLibrary.h"

UCPWeaponFXComponent::UCPWeaponFXComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UCPWeaponFXComponent::PlayImpactFX(const FHitResult& Hit)
{
    UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), Effect, Hit.ImpactPoint, Hit.ImpactNormal.Rotation());
}