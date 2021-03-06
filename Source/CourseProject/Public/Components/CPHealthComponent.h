// Course Project

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CPCoreTypes.h"
#include "CPHealthComponent.generated.h"

class UCameraShakeBase;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class COURSEPROJECT_API UCPHealthComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UCPHealthComponent();

    FOnDead OnDeath;
    FOnHealthChanged OnHealthChanged;

    UFUNCTION(BlueprintCallable, Category = "Health")
    bool IsDead() const { return FMath::IsNearlyZero(Health); }

    UFUNCTION(BlueprintCallable, Category = "Health")
    float GetHealthPercent() const { return Health / MaxHealth; }

    float GetHealth() const { return Health; }

    bool TryToAddHealth(float HealthAmount);
    bool IsHealthFull() const;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health", meta = (clampMin = "0.0", ClampMax = "1000.0"))
    float MaxHealth = 100.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Heal")
    bool AutoHeal = true;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Heal", meta = (EditCondition = "Autoheal"))
    float HealUpdateTime = 1.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Heal", meta = (EditCondition = "Autoheal"))
    float HealDelay = 3.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Heal", meta = (EditCondition = "Autoheal"))
    float HealModifier = 5.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
    TSubclassOf<UCameraShakeBase> CameraShake;

    virtual void BeginPlay() override;

private:
    float Health = 0.0f;
    FTimerHandle HealTimerHandle;

    UFUNCTION()
    void OnTakeAnyDamageHandle(
        AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

    void HealUpdate();
    void SetHealth(float NewHealth);

    void PlayCameraShake();
};
