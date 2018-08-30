#include "AComponent.h"

AComponent::AComponent(GameObject * owner)
{
	if (owner)
	{
		this->owner = owner;
	}
}

AComponent::AComponent(const AComponent & comp)
{
	if (comp.owner)
	{
		this->owner = comp.owner;
	}
	else
		LOG("This copy component doesnt have owner");
	componentType = comp.componentType;
	//name = comp.name;
}

AComponent::AComponent(AComponent && comp)
{
	if (comp.owner)
	{
		this->owner = std::move(comp.owner);
	}
	else
		LOG("This Move component doesnt have owner");
	componentType = std::move(comp.componentType);
	//name = std::move(comp.name);
}