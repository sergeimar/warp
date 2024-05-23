// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/HUD.h"
#include "GameHUD.generated.h"

UCLASS()
class SHTORM_API AGameHUD : public AHUD
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
        TSubclassOf<class UUserWidget> RoomInfoWidgetClass;

    UPROPERTY()
        class UUserWidget* RoomInfoWidget;
};