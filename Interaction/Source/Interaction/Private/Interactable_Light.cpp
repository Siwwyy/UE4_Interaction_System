
#include "Interactable_Light.h"

#include "Engine/PointLight.h"

AInteractable_Light::AInteractable_Light():
	Lights(),
	bLight_condition(true)
{
	PrimaryActorTick.bCanEverTick = false;
}

void AInteractable_Light::Action_Implementation()
{
	bLight_condition = !bLight_condition;
	for (const auto& Light : Lights)
	{
		if (!Light)
		{
			continue;
		}
		Light->SetBrightness(bLight_condition ? 10.f : 0.f);
	}
}