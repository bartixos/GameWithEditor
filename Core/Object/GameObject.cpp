#include "GameObject.h"

GameObject::GameObject()
{
	transform = std::make_unique<CTransform>(this);
	AddComponent(&*transform);
	transform->Move({ 200,200 });

	sprite = std::make_unique<CSpriteRenderer>(this);
	AddComponent(&*sprite);
}

GameObject::~GameObject()
{
	renderer = nullptr;
}

AComponent * GameObject::AddComponent(AComponent * component)
{
	if (!component->CanBeMultiple())
	{
		for (auto& comp : componentList)
		{
			if (!comp)
				continue;
			else
			{
				if (comp->GetComponentType() == component->GetComponentType())
				{
					delete component;
					component = nullptr;
					LOG("Cannot add This component with this type becouse can only be one Component with this type ");
					return nullptr;
				}
			}
		}
	}

	for (auto& comp : componentList)
	{
		if (!comp)
		{
			if (component->GetComponentType() == ComponentType::Renderer)
			{
				renderer = dynamic_cast<CARenderer*>(component);
			}
			comp = component;
			component->Initialize();
			return comp;
		}
	}

	delete component;
	component = nullptr;

	LOG("Cannot Add component");
	return nullptr;
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
			comp->Initialize();
		}
	}
}

void GameObject::Draw(sf::RenderWindow & window)
{
	if (renderer)
	{
		renderer->Draw(window);
	}
}

void GameObject::Initialize()
{
	sprite->LoadTexture("Player", "statek.png");
}

void GameObject::Update(float delta)
{
	transform->Move(0, 100 * delta);
	LOG(GetPosition().ToString());
}