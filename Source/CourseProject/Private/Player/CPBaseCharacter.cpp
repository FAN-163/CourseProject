// Course Project

#include "Player/CPBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "CPBaseCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CPCharacterMovementComponent.h"

ACPBaseCharacter::ACPBaseCharacter(const FObjectInitializer& ObjInit)
    : Super(ObjInit.SetDefaultSubobjectClass<UCPCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
    PrimaryActorTick.bCanEverTick = true;

    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
    SpringArmComponent->SetupAttachment(GetRootComponent());
    SpringArmComponent->bUsePawnControlRotation = true;
    
    CameraComponent = CreateAbstractDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(SpringArmComponent);
}

// Called when the game starts or when spawned
void ACPBaseCharacter::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ACPBaseCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ACPBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &ACPBaseCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ACPBaseCharacter::MoveRight);
    PlayerInputComponent->BindAxis("LookUp", this, &ACPBaseCharacter::AddControllerPitchInput);
    PlayerInputComponent->BindAxis("TurnAround", this, &ACPBaseCharacter::AddControllerYawInput);
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACPBaseCharacter::Jump);
    PlayerInputComponent->BindAction("Run", IE_Pressed, this, &ACPBaseCharacter::OnStartRunning);
    PlayerInputComponent->BindAction("Run", IE_Released, this, &ACPBaseCharacter::OnStopRunning);
}

bool ACPBaseCharacter::IsRunning() const
{
    return WantsToRun && IsMovingForward && !GetVelocity().IsZero();
}

void ACPBaseCharacter::MoveForward(float Amount)
{
    IsMovingForward = Amount > 0.0f;
    AddMovementInput(GetActorForwardVector(), Amount);
}

void ACPBaseCharacter::MoveRight(float Amount)
{
    AddMovementInput(GetActorRightVector(), Amount);
}

void ACPBaseCharacter::OnStartRunning() 
{
    WantsToRun = true;
}

void ACPBaseCharacter::OnStopRunning()
{
    WantsToRun = false;
}

