// Course Project

#pragma once

#include "CoreMinimal.h"
#include "Weapon/CPBaseWeapon.h"
#include "CPLauncherWeapon.generated.h"

class ACPProjectile;

UCLASS()
class COURSEPROJECT_API ACPLauncherWeapon : public ACPBaseWeapon
{
    GENERATED_BODY()

public:
    virtual void StartFire() override;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
    TSubclassOf<ACPProjectile> ProjectileClass;

    virtual void MakeShot() override;
};
