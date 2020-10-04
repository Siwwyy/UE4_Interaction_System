
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actor_Interface.h"
#include "Interactable_Light.generated.h"

class APointLight;

UCLASS()
class INTERACTION_API AInteractable_Light : public AActor, public IActor_Interface
{
	GENERATED_BODY()
	
public:	
	AInteractable_Light();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void Action();
	virtual void Action_Implementation() override;

private:	
	UPROPERTY(EditAnywhere, Category = "Light")
	TArray<APointLight*> Lights;

	bool bLight_condition;

};
