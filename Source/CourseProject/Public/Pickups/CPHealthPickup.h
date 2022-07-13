// Course Project

#pragma once

#include "CoreMinimal.h"
#include "Pickups/CPBasePickup.h"
#include "CPHealthPickup.generated.h"

UCLASS()
class COURSEPROJECT_API ACPHealthPickup : public ACPBasePickup
{
    GENERATED_BODY()

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup", meta = (clampMin = "1.0", ClampMax = "100.0"))
    float HealthAmount = 100.0f;

private:
    virtual bool GivePickupTo(APawn* PlayerPawn) override;
};
