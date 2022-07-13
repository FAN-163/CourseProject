// Course Project

#pragma once

#include "CoreMinimal.h"
#include "Weapon/CPBaseWeapon.h"
#include "CPRifleWeapon.generated.h"

class UCPWeaponFXComponent;
UCLASS()
class COURSEPROJECT_API ACPRifleWeapon : public ACPBaseWeapon
{
    GENERATED_BODY()
public:
    ACPRifleWeapon();

    virtual void StartFire() override;
    virtual void StopFire() override;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
    float TimeBetweenShots = 0.1f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
    float BulletSpread = 1.5f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
    float DamageAmount = 10.0f;

    UPROPERTY(VisibleAnywhere, Category = "VFX")
    UCPWeaponFXComponent* WeaponFXComponent;

    virtual void BeginPlay() override;
    virtual void MakeShot() override;
    virtual bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const override;

private:
    FTimerHandle ShotTimerHandle;

    void MakeDamage(const FHitResult& HitResult);
};
