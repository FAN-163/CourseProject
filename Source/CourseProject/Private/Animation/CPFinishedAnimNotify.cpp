// Course Project

#include "Animation/CPFinishedAnimNotify.h"

void UCPFinishedAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
    OnNotified.Broadcast(MeshComp);

    Super::Notify(MeshComp, Animation);
}