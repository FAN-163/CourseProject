// Course Project

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CPGameHUD.generated.h"

UCLASS()
class COURSEPROJECT_API ACPGameHUD : public AHUD
{
    GENERATED_BODY()

public:
    virtual void DrawHUD() override;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> PlayerHUDWidgetClass;

    virtual void BeginPlay() override;

private:
    void DrawCrossHair();
};
