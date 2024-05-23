#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ARoom.generated.h"

UCLASS()
class SHTORM_API AARoom : public AActor
{
    GENERATED_BODY()

public:
    // Устанавливает значения по умолчанию для свойств этого актера
    AARoom();

protected:
    // Вызывается при запуске игры или при создании объекта
    virtual void BeginPlay() override;

public:
    // Вызывается каждый кадр
    virtual void Tick(float DeltaTime) override;
};