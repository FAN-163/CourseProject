// Course Project

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CPAIController.generated.h"

class UCPAIPerceptionComponent;

UCLASS()
class COURSEPROJECT_API ACPAIController : public AAIController
{
    GENERATED_BODY()

public:
    ACPAIController();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UCPAIPerceptionComponent* CPAIPerceptionComponent;

    virtual void OnPossess(APawn* InPawn) override;
    virtual void Tick(float DeltaTime) override;
};
