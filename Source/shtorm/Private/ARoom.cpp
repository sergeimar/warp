#include "ARoom.h"

// ������������� �������� �� ���������
AARoom::AARoom()
{
    // �������������, ����� ���� ����� ������� Tick() ������ ����.
    // �� ������ ��������� ��� ��� ��������� ������������������, ���� �� �����.
    PrimaryActorTick.bCanEverTick = true;
}

// ���������� ��� ������� ���� ��� ��� �������� �������
void AARoom::BeginPlay()
{
    Super::BeginPlay();
}

// ���������� ������ ����
void AARoom::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}