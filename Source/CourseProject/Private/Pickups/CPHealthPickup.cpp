// Course Project


#include "Pickups/CPHealthPickup.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthPickup, All, All)

bool ACPHealthPickup::GivePickupTo(APawn* PlayerPawn)
{
    UE_LOG(LogHealthPickup, Display, TEXT("Health was taken"))
    return true;
}