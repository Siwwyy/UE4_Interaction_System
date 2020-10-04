
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCPP.generated.h"

UCLASS()
class INTERACTION_API APlayerCPP : public ACharacter
{
	GENERATED_BODY()

public:

	APlayerCPP();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void TurnAtRate(float Rate);

	void LookUpAtRate(float Rate);

	void MoveForward(float Value);

	void MoveRight(float Value);
protected:

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float fBaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float fBaseLookUpRate;
};