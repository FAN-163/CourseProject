// Course Project

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPBaseWeapon.generated.h"

class USkeletalMeshComponent;

UCLASS()
class COURSEPROJECT_API ACPBaseWeapon : public AActor
{
    GENERATED_BODY()

public:
    ACPBaseWeapon();

    virtual void StartFire();
    virtual void StopFire();

protected:
    UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "Components")
    USkeletalMeshComponent* WeaponMesh;

    UPROPERTY(VisibleAnyWhere, BlueprintReadWrite)
    FName MuzzleSocketName = "MuzzleSocket";

    UPROPERTY(VisibleAnyWhere, BlueprintReadWrite)
    float TraceMaxDistance = 1500.0f;

    UPROPERTY(VisibleAnyWhere, BlueprintReadWrite)
    float DamageAmount = 10.0f;

    UPROPERTY(VisibleAnyWhere, BlueprintReadWrite)
    float TimeBetweenShots = 0.1f;

    UPROPERTY(VisibleAnyWhere, BlueprintReadWrite)
    float BulletSpread = 1.5f;

    virtual void BeginPlay() override;

    void MakeShot();
    void MakeHit(FHitResult& HitResult, const FVector& TraceStart, const FVector& TraceEnd);
    void MakeDamage(const FHitResult& HitResult);

    APlayerController* GetPlayerController() const;

    FVector GetMuzzleWorldLocation() const;

    bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const;
    bool GetPlayerViewPoint(FVector& ViewLocation, FRotator& ViewRotation) const;

private:
    FTimerHandle ShotTimerHandle;
};
