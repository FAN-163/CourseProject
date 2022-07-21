// Course Project

#pragma once

#include "CoreMinimal.h"
#include "Player/CPBaseCharacter.h"
#include "CPAICharacter.generated.h"

class UBehaviorTree;

UCLASS()
class COURSEPROJECT_API ACPAICharacter : public ACPBaseCharacter
{
    GENERATED_BODY()

public:
    ACPAICharacter(const FObjectInitializer& ObjInit);

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
    UBehaviorTree* BehaviorTreeAsset;

protected:
    virtual void OnDeath() override;
};
