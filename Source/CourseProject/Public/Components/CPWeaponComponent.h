// Course Project

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CPWeaponComponent.generated.h"

class ACPBaseWeapon;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class COURSEPROJECT_API UCPWeaponComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UCPWeaponComponent();

    void StartFire();
    void StopFire();

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TSubclassOf<ACPBaseWeapon> WeaponClass;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    FName WeaponAttachPointName = "WeaponSocket";

    virtual void BeginPlay() override;

private:
    UPROPERTY()
    ACPBaseWeapon* CurrentWeapon = nullptr;

    void SpawnWeapon();
};
