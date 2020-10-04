
#include "../Public/PlayerCPP.h"

#include "../Public/Interaction_Component.h"


APlayerCPP::APlayerCPP():
	fBaseTurnRate(45.f),
	fBaseLookUpRate(45.f)
{
	PrimaryActorTick.bCanEverTick = false;
}

void APlayerCPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCPP::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCPP::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &APlayerCPP::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &APlayerCPP::LookUpAtRate);
}

void APlayerCPP::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * fBaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void APlayerCPP::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * fBaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void APlayerCPP::MoveForward(float Value)
{
	if (Controller && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void APlayerCPP::MoveRight(float Value)
{
	if (Controller && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}