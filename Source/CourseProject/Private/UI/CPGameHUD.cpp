// Course Project


#include "UI/CPGameHUD.h"
#include "Engine/Canvas.h"


void ACPGameHUD::DrawHUD() 
{
    Super::DrawHUD();

    DrawCrossHair();
}

void ACPGameHUD::DrawCrossHair() 
{
    const TInterval<float> Center(Canvas->SizeX * 0.5f, Canvas->SizeY * 0.5f);

    const float HalfLineSize = 10.0f;
    const float LineThickness = 2.0f;
    const FLinearColor LinerColor = FLinearColor::Green;

    DrawLine(Center.Min - HalfLineSize, Center.Max, Center.Min + HalfLineSize, Center.Max, LinerColor, LineThickness);
    DrawLine(Center.Min, Center.Max - HalfLineSize, Center.Min, Center.Max + HalfLineSize, LinerColor, LineThickness);
}
