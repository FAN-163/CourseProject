// Course Project

#include "Weapon/CPLauncherWeapon.h"
#include "Weapon/CPProjectile.h"
#include "Kismet/GameplayStatics.h"

void ACPLauncherWeapon::StartFire()
{
    MakeShot();
}

void ACPLauncherWeapon::MakeShot()
{
    const FTransform SpawnTransform(FRotator::ZeroRotator, GetMuzzleWorldLocation());
    auto Projectile = UGameplayStatics::BeginDeferredActorSpawnFromClass(GetWorld(), ProjectileClass, SpawnTransform);
    // set projectile params

    UGameplayStatics::FinishSpawningActor(Projectile, SpawnTransform);

}
