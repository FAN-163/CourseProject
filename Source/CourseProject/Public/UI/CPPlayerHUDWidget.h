// Course Project

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CPCoreTypes.h"
#include "CPPlayerHUDWidget.generated.h"

class UCPWeaponComponent;
class UCPHealthComponent;

UCLASS()
class COURSEPROJECT_API UCPPlayerHUDWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "UI")
    float GetHealthPercent() const;

    UFUNCTION(BlueprintCallable, Category = "UI")
    bool GetCurrentWeaponUIData(FWeaponUIData& UIData) const;

    UFUNCTION(BlueprintCallable, Category = "UI")
    bool GetCurrentWeaponAmmoData(FAmmoData& AmmoData) const;

    UFUNCTION(BlueprintCallable, Category = "UI")
    bool IsPlayerAlive() const;

    UFUNCTION(BlueprintCallable, Category = "UI")
    bool IsPlayerSpectating() const;

private:
    UCPWeaponComponent* GetWeaponComponent() const;
    UCPHealthComponent* GetHealthComponent() const;
};
