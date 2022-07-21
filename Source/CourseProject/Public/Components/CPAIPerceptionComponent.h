// Course Project

#pragma once

#include "CoreMinimal.h"
#include "Perception/AIPerceptionComponent.h"
#include "CPAIPerceptionComponent.generated.h"

UCLASS()
class COURSEPROJECT_API UCPAIPerceptionComponent : public UAIPerceptionComponent
{
    GENERATED_BODY()

public:
    AActor* GetClosestEnemy() const;
};
