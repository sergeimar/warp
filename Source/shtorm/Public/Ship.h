// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ARoom.h"
#include "Ship.generated.h"

UCLASS()
class SHTORM_API AShip : public AActor
{
    GENERATED_BODY()

public:
    // Устанавливает значения по умолчанию для свойств этого актера
    AShip();

    void AddRoom(AARoom* NewRoom);

protected:
    // Вызывается при запуске игры или при создании объекта
    virtual void BeginPlay() override;

public:
    // Вызывается каждый кадр
    virtual void Tick(float DeltaTime) override;

private:
    TArray<AARoom*> Rooms;
};