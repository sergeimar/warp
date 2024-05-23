#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ARoom.generated.h"

UCLASS()
class SHTORM_API AARoom : public AActor
{
    GENERATED_BODY()

public:
    // ������������� �������� �� ��������� ��� ������� ����� ������
    AARoom();

protected:
    // ���������� ��� ������� ���� ��� ��� �������� �������
    virtual void BeginPlay() override;

public:
    // ���������� ������ ����
    virtual void Tick(float DeltaTime) override;
};