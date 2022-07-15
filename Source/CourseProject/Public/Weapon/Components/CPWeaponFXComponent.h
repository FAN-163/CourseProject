// Course Project

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CPCoreTypes.h"
#include "CPWeaponFXComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class COURSEPROJECT_API UCPWeaponFXComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UCPWeaponFXComponent();

    void PlayImpactFX(const FHitResult& Hit);

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
    FImpactData DefaultImpactData;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
    TMap<UPhysicalMaterial*, FImpactData> ImpactDataMap;
};
