// Course Project


#include "Animation/CPAnimNotify.h"

void UCPAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
    OnNotified.Broadcast(MeshComp);

    Super::Notify(MeshComp, Animation);
}