// Course Project

#pragma once

#include "CoreMinimal.h"
#include "Player/CPBaseCharacter.h"
#include "CPAICharacter.generated.h"

UCLASS()
class COURSEPROJECT_API ACPAICharacter : public ACPBaseCharacter
{
    GENERATED_BODY()

public:
    ACPAICharacter(const FObjectInitializer& ObjInit);
};
