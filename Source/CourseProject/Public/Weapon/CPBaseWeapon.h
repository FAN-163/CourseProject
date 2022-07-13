// Course Project

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPCoreTypes.h"
#include "CPBaseWeapon.generated.h"


class USkeletalMeshComponent;


UCLASS()
class COURSEPROJECT_API ACPBaseWeapon : public AActor
{
    GENERATED_BODY()

public:
    ACPBaseWeapon();

    FOnClipEmptySignature OnClipEmpty;

    virtual void StartFire();
    virtual void StopFire();

    void ChangeClip();
    bool CanReload() const;

    FWeaponUIData GetUIData() const { return UiData; }
    FAmmoData GetAmmoData() const { return CurrentAmmo; }

    bool TryToAddAmmo(int32 ClipsAmount);

protected:
    UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "Components")
    USkeletalMeshComponent* WeaponMesh;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
    FName MuzzleSocketName = "MuzzleSocket";

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
    float TraceMaxDistance = 1500.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
    FAmmoData DefaultAmmo;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    FWeaponUIData UiData;

    virtual void BeginPlay() override;

    virtual void MakeShot();
    virtual bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const;

    void MakeHit(FHitResult& HitResult, const FVector& TraceStart, const FVector& TraceEnd);

    APlayerController* GetPlayerController() const;

    FVector GetMuzzleWorldLocation() const;

    bool GetPlayerViewPoint(FVector& ViewLocation, FRotator& ViewRotation) const;

    void DecreaseAmmo();
    bool IsAmmoEmpty() const;
    bool IsClipEmpty() const;
    bool IsAmmoFull() const;

    void LogAmmo();

private:
    FAmmoData CurrentAmmo;
};
