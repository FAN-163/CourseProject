// Course Project

#pragma once

#include "CoreMinimal.h"
#include "Pickups/CPBasePickup.h"
#include "CPAmmoPickup.generated.h"

class ACPBaseWeapon;

UCLASS()
class COURSEPROJECT_API ACPAmmoPickup : public ACPBasePickup
{
    GENERATED_BODY()

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup", meta = (clampMin = "1.0", ClampMax = "10.0"))
    int32 ClipsAmount = 10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
    TSubclassOf<ACPBaseWeapon> WeaponType;

private:
    virtual bool GivePickupTo(APawn* PlayerPawn) override;
};
