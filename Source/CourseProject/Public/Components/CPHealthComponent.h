// Course Project

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CPHealthComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class COURSEPROJECT_API UCPHealthComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UCPHealthComponent();

    float GetHealth() const { return Health; }

protected:
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health", meta = (clampMin = "0.0", ClampMax = "1000.0"))
    float MaxHealth = 100.0f;

    virtual void BeginPlay() override;

private:
    float Health = 0.0f;
};
