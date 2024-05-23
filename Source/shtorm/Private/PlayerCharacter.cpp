#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
    // Set this character to call Tick() every frame. You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // Create a SpringArmComponent
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character
    CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

    // Create a CameraComponent
    PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
    PlayerCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the spring arm
    PlayerCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

    OrbitSpeed = 50.0f; // Orbit speed in degrees per second
    OrbitRadius = 300.0f;
    bIsAttachedToShip = false;
    AttachedShip = nullptr;
    CurrentOrbitAngle = 0.0f; // Initialize current orbit angle
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
    Super::BeginPlay();

    // Ensure the player possesses this character
    if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
    {
        PlayerController->Possess(this);
    }
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bIsAttachedToShip && AttachedShip)
    {
        FlyAroundShip(DeltaTime);
    }
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Bind camera controls
    PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
    PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

    // Bind movement controls
    PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
}

void APlayerCharacter::MoveForward(float Value)
{
    if ((Controller != nullptr) && (Value != 0.0f))
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        AddMovementInput(Direction, Value);
    }
}

void APlayerCharacter::MoveRight(float Value)
{
    if ((Controller != nullptr) && (Value != 0.0f))
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
        AddMovementInput(Direction, Value);
    }
}

void APlayerCharacter::AttachToShip(AActor* Ship)
{
    if (Ship)
    {
        AttachedShip = Ship;
        bIsAttachedToShip = true;

        // Logging
        if (GEngine)
        {
            FString ActorName = Ship->GetName();
            GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Attached to: %s"), *ActorName));
        }
    }
}

void APlayerCharacter::FlyAroundShip(float DeltaTime)
{
    if (!AttachedShip)
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("No attached ship."));
        }
        return;
    }

    // Update the current orbit angle based on orbit speed (converted to radians)
    CurrentOrbitAngle += FMath::DegreesToRadians(OrbitSpeed) * DeltaTime;

    FVector ShipLocation = AttachedShip->GetActorLocation();

    // Calculate the new location based on the current orbit angle
    float DeltaX = FMath::Cos(CurrentOrbitAngle) * OrbitRadius;
    float DeltaY = FMath::Sin(CurrentOrbitAngle) * OrbitRadius;

    FVector NewLocation = ShipLocation + FVector(DeltaX, DeltaY, 0.0f); // Keep Z constant
    SetActorLocation(NewLocation);

    FRotator LookAtRotation = (ShipLocation - NewLocation).Rotation();
    LookAtRotation.Pitch = 0.0f;
    LookAtRotation.Roll = 0.0f;
    SetActorRotation(LookAtRotation);

 
}
