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

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    FName FocusOnKeyName = "EnemyActor";

    virtual void OnPossess(APawn* InPawn) override;
    virtual void Tick(float DeltaTime) override;

private:
    AActor* GetFocusOnActor() const;
};
