#include "Ship.h"

// Устанавливает значения по умолчанию
AShip::AShip()
{
    // Устанавливает, чтобы этот актер вызывал Tick() каждый кадр.
    // Вы можете отключить это для улучшения производительности, если не нужно.
    PrimaryActorTick.bCanEverTick = true;
}

// Вызывается при запуске игры или при создании объекта
void AShip::BeginPlay()
{
    Super::BeginPlay();
}

// Вызывается каждый кадр
void AShip::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AShip::AddRoom(AARoom* NewRoom)
{
    if (NewRoom)
    {
        Rooms.Add(NewRoom);
    }
}