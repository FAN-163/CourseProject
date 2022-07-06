// Course Project

#include "Weapon/CPProjectile.h"
#include "Components/SphereComponent.h"

ACPProjectile::ACPProjectile()
{
    PrimaryActorTick.bCanEverTick = false;

    CollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
    CollisionComponent->InitSphereRadius(5.0f);
    SetRootComponent(CollisionComponent);
}

void ACPProjectile::BeginPlay()
{
    Super::BeginPlay();
}
