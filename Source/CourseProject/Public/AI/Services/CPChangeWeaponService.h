// Course Project

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "CPChangeWeaponService.generated.h"

UCLASS()
class COURSEPROJECT_API UCPChangeWeaponService : public UBTService
{
    GENERATED_BODY()

public:
    UCPChangeWeaponService();

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (ClampMin = "0.0", ClampMax = "1.0"))
    float Probability = 0.5f;

    virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
