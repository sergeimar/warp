#include "Ship.h"

// ������������� �������� �� ���������
AShip::AShip()
{
    // �������������, ����� ���� ����� ������� Tick() ������ ����.
    // �� ������ ��������� ��� ��� ��������� ������������������, ���� �� �����.
    PrimaryActorTick.bCanEverTick = true;
}

// ���������� ��� ������� ���� ��� ��� �������� �������
void AShip::BeginPlay()
{
    Super::BeginPlay();
}

// ���������� ������ ����
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