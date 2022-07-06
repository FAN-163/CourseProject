// Course Project

#pragma once

#include "CoreMinimal.h"
#include "Weapon/CPBaseWeapon.h"
#include "CPRifleWeapon.generated.h"

UCLASS()
class COURSEPROJECT_API ACPRifleWeapon : public ACPBaseWeapon
{
    GENERATED_BODY()
public:
    virtual void StartFire() override;
    virtual void StopFire() override;

protected:
    UPROPERTY(VisibleAnyWhere, BlueprintReadWrite)
    float TimeBetweenShots = 0.1f;

    UPROPERTY(VisibleAnyWhere, BlueprintReadWrite)
    float BulletSpread = 1.5f;

    virtual void MakeShot() override;
    virtual bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const override;

private:
    FTimerHandle ShotTimerHandle;
};
