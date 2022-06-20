// Course Project


#include "Player/CPBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"

// Sets default values
ACPBaseCharacter::ACPBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = CreateAbstractDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(GetRootComponent());

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

}

void ACPBaseCharacter::MoveForward(float Amount) 
{
    AddMovementInput(GetActorForwardVector(), Amount);
}

void ACPBaseCharacter::MoveRight(float Amount) 
{
    AddMovementInput(GetActorRightVector(), Amount);
}

