#include "GameObject.h"

void GameObject::SetComponentOwner()
{
	for (auto& comp : componentList)
	{
		if (comp && comp->GetOwner())
		{
			comp->SetOwnerIfNull(this);
		}
	}
}

size_t GameObject::GetComponentNumber() noexcept
{
	size_t number = 0;
	for (auto& comp : componentList)
	{
		if (comp)
		{
			number += 1;
		}
	}
	return number;
}

void GameObject::SetComponentsOwner()
{
	for (auto& comp : componentList)
	{
		if (comp)
		{
			comp->SetOwnerIfNull(this);
		}
	}
}

GameObject::GameObject()
{
	transform = new CTransform();
	AddComponent<CTransform>(transform);
	//transform = GetComponent<CTransform>();
	//transform->Move({ 200,200 });
}

GameObject::~GameObject()
{
}

void GameObject::ComponentUpdate(float delta)
{
	for (auto& comp : componentList)
	{
		if (comp)
		{
			comp->Update(delta);
		}
	}
}

void GameObject::ComponentInitialize()
{
	for (auto& comp : componentList)
	{
		if (comp)
		{
			comp->SetOwnerIfNull(this);
			comp->Initialize();
		}
	}
}

void GameObject::Draw(sf::RenderWindow & window)
{
}

void GameObject::Initialize()
{
}

void GameObject::Update(float delta)
{
}