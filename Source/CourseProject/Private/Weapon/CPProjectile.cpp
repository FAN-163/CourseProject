// Course Project

#include "Weapon/CPProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

ACPProjectile::ACPProjectile()
{
    PrimaryActorTick.bCanEverTick = false;

    CollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
    CollisionComponent->InitSphereRadius(5.0f);
    SetRootComponent(CollisionComponent);

    MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");
    MovementComponent->InitialSpeed = 2000.0f;
    MovementComponent->ProjectileGravityScale = 0.0f;
}

void ACPProjectile::BeginPlay()
{
    Super::BeginPlay();

    check(MovementComponent);
    MovementComponent->Velocity = ShotDirection * MovementComponent->InitialSpeed;

}
