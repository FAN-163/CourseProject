// Course Project

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

UCLASS()
class COURSEPROJECT_API ACPProjectile : public AActor
{
    GENERATED_BODY()

public:
    ACPProjectile();

    void SetShotDirection(const FVector& Direction) { ShotDirection = Direction; }

protected:
    UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
    USphereComponent* CollisionComponent;

    UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
    UProjectileMovementComponent* MovementComponent;

    virtual void BeginPlay() override;

private:
    FVector ShotDirection;
};
