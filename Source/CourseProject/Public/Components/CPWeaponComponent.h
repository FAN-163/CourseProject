// Course Project

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CPCoreTypes.h"
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
    void NextWeapon();
    void Reload();

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TArray<FWeaponData> WeaponData;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    FName WeaponEquipSocketName = "WeaponSocket";

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    FName WeaponArmorySocketName = "ArmorySocket";

    UPROPERTY(EditDefaultsOnly, Category = "Animation")
    UAnimMontage* EquipAnimMontage;

    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
    UPROPERTY()
    ACPBaseWeapon* CurrentWeapon = nullptr;

    UPROPERTY()
    TArray<ACPBaseWeapon*> Weapons;

    UPROPERTY()
    UAnimMontage* CurrentReloadAnimMontage = nullptr;

    int32 CurrentWeaponIndex = 0;
    bool EquipAnimInProgress = false;
    bool ReloadAnimProgress = false;

    void InitAnimations();
    void SpawnWeapons();
    void AttachWeaponToSocket(ACPBaseWeapon* Weapon, USceneComponent* SceneComponent, const FName& SocketName);
    void EquipWeapon(int32 WeaponIndex);

    void PlayAnimMontage(UAnimMontage* Animation);

    void OnEquipFinished(USkeletalMeshComponent* MeshComponent);
    void OnReloadFinished(USkeletalMeshComponent* MeshComponent);

    bool CanFire() const;
    bool CanEquip() const;
    bool CanReload() const;

    void OnEmptyClip();
    void ChangeClip();

    
};
