// Course Project

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPProjectile.generated.h"

class USphereComponent;

UCLASS()
class COURSEPROJECT_API ACPProjectile : public AActor
{
    GENERATED_BODY()

public:
    ACPProjectile();

protected:
    UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
    USphereComponent* CollisionComponent;

    virtual void BeginPlay() override;
};
