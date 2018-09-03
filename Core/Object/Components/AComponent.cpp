#include "AComponent.h"
#include "RenderComponent/CARenderer.h"
#include "RenderComponent/CSpriteRenderer.h"
AComponent::AComponent(GameObject * owner) :
	owner(nullptr)
{
	if (owner)
	{
		this->owner = owner;
	}
}

AComponent::AComponent() :
	owner(nullptr)
{
}