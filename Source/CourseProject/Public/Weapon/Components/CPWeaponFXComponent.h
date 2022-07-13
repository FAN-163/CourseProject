// Course Project

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CPWeaponFXComponent.generated.h"

class UNiagaraSystem;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class COURSEPROJECT_API UCPWeaponFXComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UCPWeaponFXComponent();

    void PlayImpactFX(const FHitResult& Hit);

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
    UNiagaraSystem* Effect;
};
