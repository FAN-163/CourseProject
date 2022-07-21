// Course Project

#pragma once

#include "CoreMinimal.h"
#include "Components/CPWeaponComponent.h"
#include "CPAIWeaponComponent.generated.h"

UCLASS()
class COURSEPROJECT_API UCPAIWeaponComponent : public UCPWeaponComponent
{
    GENERATED_BODY()

public:
    virtual void StartFire() override;
    virtual void NextWeapon() override;
};
