// Course Project

#include "Pickups/CPBasePickup.h"
#include "Components/SphereComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogBasePickup, All, All);

ACPBasePickup::ACPBasePickup()
{
    PrimaryActorTick.bCanEverTick = true;

    CollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
    CollisionComponent->InitSphereRadius(50.0f);
    CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
    SetRootComponent(CollisionComponent);
}

void ACPBasePickup::BeginPlay()
{
    Super::BeginPlay();

    check(CollisionComponent);
}

void ACPBasePickup::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ACPBasePickup::NotifyActorBeginOverlap(AActor* OtherActor)
{
    Super::NotifyActorBeginOverlap(OtherActor);

    const auto Pawn = Cast<APawn>(OtherActor);
    if (GivePickupTo(Pawn))
    {
        PickupWasTaken();
    }

    PickupWasTaken();
}

bool ACPBasePickup::GivePickupTo(APawn* PlayerPawn)
{
    return false;
}

void ACPBasePickup::PickupWasTaken()
{
    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
    if (GetRootComponent())
    {
        GetRootComponent()->SetVisibility(false, true);
    }

    FTimerHandle RespawnTimeHandle;
    GetWorldTimerManager().SetTimer(RespawnTimeHandle, this, &ACPBasePickup::Respawn, RespawnTime);
}

void ACPBasePickup::Respawn()
{
    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
    if (GetRootComponent())
    {
        GetRootComponent()->SetVisibility(true, true);
    }
}
