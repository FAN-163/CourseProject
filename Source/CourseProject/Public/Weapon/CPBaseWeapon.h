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

    virtual void Fire();

protected:
    UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "Components")
    USkeletalMeshComponent* WeaponMesh;

    virtual void BeginPlay() override;
};
