// Course Project

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPBasePickup.generated.h"

class USphereComponent;

UCLASS()
class COURSEPROJECT_API ACPBasePickup : public AActor
{
    GENERATED_BODY()

public:
    ACPBasePickup();

protected:
    UPROPERTY(VisibleAnywhere, Category = "Pickup")
    USphereComponent* CollisionComponent;

    virtual void BeginPlay() override;
    virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

public:
    virtual void Tick(float DeltaTime) override;
};
