#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class SHTORM_API APlayerCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    APlayerCharacter();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    // Camera components
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
        class UCameraComponent* PlayerCamera;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
        class USpringArmComponent* CameraBoom;

    // Orbit variables
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
        float OrbitSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
        float OrbitRadius;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
        bool bIsAttachedToShip;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
        AActor* AttachedShip;

    UFUNCTION(BlueprintCallable, Category = "Orbit")
        void AttachToShip(AActor* Ship);

private:
    void FlyAroundShip(float DeltaTime);
    void MoveForward(float Value);
    void MoveRight(float Value);

    float CurrentOrbitAngle; // Current angle for orbit
};
