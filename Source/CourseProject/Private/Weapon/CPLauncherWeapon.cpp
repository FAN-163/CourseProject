// Course Project

#include "Weapon/CPLauncherWeapon.h"
#include "Weapon/CPProjectile.h"


void ACPLauncherWeapon::StartFire()
{
    MakeShot();
}

void ACPLauncherWeapon::MakeShot()
{
    if (!GetWorld()) return;

    FVector TraceStart, TraceEnd;
    if (!GetTraceData(TraceStart, TraceEnd)) return;

    FHitResult HitResult;
    MakeHit(HitResult, TraceStart, TraceEnd);

    const FVector EndPoint = HitResult.bBlockingHit ? HitResult.ImpactPoint : TraceEnd;
    const FVector Direction = (EndPoint - GetMuzzleWorldLocation()).GetSafeNormal();

    const FTransform SpawnTransform(FRotator::ZeroRotator, GetMuzzleWorldLocation());
    ACPProjectile* Projectile = GetWorld()->SpawnActorDeferred<ACPProjectile>(ProjectileClass, SpawnTransform);
    if (Projectile)
    {
        Projectile->SetShotDirection(Direction);
        Projectile->FinishSpawning(SpawnTransform);
    }
    }
