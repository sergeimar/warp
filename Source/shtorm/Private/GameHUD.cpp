#include "GameHUD.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"

void AGameHUD::BeginPlay()
{
    Super::BeginPlay();

    if (RoomInfoWidgetClass)
    {
        RoomInfoWidget = CreateWidget<UUserWidget>(GetWorld(), RoomInfoWidgetClass);
        if (RoomInfoWidget)
        {
            RoomInfoWidget->AddToViewport();
        }
    }
}