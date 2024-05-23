#include "ARoom.h"

// Устанавливает значения по умолчанию
AARoom::AARoom()
{
    // Устанавливает, чтобы этот актер вызывал Tick() каждый кадр.
    // Вы можете отключить это для улучшения производительности, если не нужно.
    PrimaryActorTick.bCanEverTick = true;
}

// Вызывается при запуске игры или при создании объекта
void AARoom::BeginPlay()
{
    Super::BeginPlay();
}

// Вызывается каждый кадр
void AARoom::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}