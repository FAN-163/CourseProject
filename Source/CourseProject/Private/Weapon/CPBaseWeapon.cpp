// Course Project

#include "Weapon/CPBaseWeapon.h"
#include "Components/SkeletalMeshComponent.h"

ACPBaseWeapon::ACPBaseWeapon()
{
    PrimaryActorTick.bCanEverTick = false;

    WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
    SetRootComponent(WeaponMesh);
}

void ACPBaseWeapon::BeginPlay()
{
    Super::BeginPlay();
}
