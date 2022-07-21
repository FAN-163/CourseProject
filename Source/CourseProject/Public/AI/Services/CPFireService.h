// Course Project

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "CPFireService.generated.h"

UCLASS()
class COURSEPROJECT_API UCPFireService : public UBTService
{
	GENERATED_BODY()
public:
    UCPFireService();

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    FBlackboardKeySelector EnemyActorKey;

    virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
