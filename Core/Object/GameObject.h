#pragma once
#include "Utility/Define.h"
#include "Components/AComponent.h"
#include <array>
#include "Components/CTransform.h"
#include "Components/RenderComponent/CARenderer.h"
#include "Components/RenderComponent/CSpriteRenderer.h"

#include <cereal/types/polymorphic.hpp>
#include <cereal/types/array.hpp>
#include <cereal/types/string.hpp>
#include "cereal/types/memory.hpp"

namespace sf
{
	class RenderWindow;
}

class GameObject
{
	constexpr inline static  int maxComponentNumber = 16;
	std::array<UniquePtr<AComponent>, maxComponentNumber> componentList;
	void SetComponentOwner();
	friend cereal::access;
protected:
	std::string tag = "";
	std::string name = "GameObject";

	CTransform *transform;

	//todo: Add RenderComponent and Set it in AddComponent
public:

	size_t GetComponentNumber() noexcept;
	void SetComponentsOwner();
	GameObject();
	virtual ~GameObject();
	template<typename T>
	T* AddComponent(T* comp);
	const std::string&  GetTag() const noexcept { return tag; };
	const std::string& GetName() const noexcept { return name; };
	void SetName(const std::string& _name) noexcept { name = _name; };
	void SetTag(const std::string &_tag) noexcept { tag = _tag; };

	CTransform *GetTransform() const noexcept { return transform; };
	Vector2 GetPosition() const noexcept
	{
		return transform->GetPosition();
	};
	//todo: ADD GetComponent
	void ComponentUpdate(float delta);
	void ComponentInitialize();
	virtual	void Draw(sf::RenderWindow& window);
	virtual void Initialize();
	virtual void Update(float delta);

	template<typename T>
	T* GetComponent();

	//////////////////////////////////TEST//////////////////////////////
	CSpriteRenderer *sprite;

	template<typename Archive>
	void load(Archive& archive)
	{
		//archive(CEREAL_NVP_("tag", tag), CEREAL_NVP_("Name", name), CEREAL_NVP_("Component List", componentList));
		//archive(cereal::make_nvp("tag", tag), cereal::make_nvp("name", name)/* componentList*/);
		archive(tag, name, componentList);
	}
	template<typename Archive>
	void save(Archive& archive) const
	{
		archive(CEREAL_NVP_("tag", tag), CEREAL_NVP_("Name", name), CEREAL_NVP_("Component_list", componentList)/* CEREAL_NVP_("Component List", componentList)*/);
	}
};

template<typename T>
inline T * GameObject::GetComponent()
{
	static std::string name = typeid(T).name();
	for (int i = 0; componentList.size(); i++)
	{
		if (name == typeid(*componentList[i]).name())
		{
			return dynamic_cast<T*>(componentList[i].get());
		}
	}
	return nullptr;
}

template <typename T>
T* GameObject::AddComponent(T* component)
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
					//delete component;
					//component = nullptr;
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
			comp = UniquePtr<T>(component);
			comp->SetOwnerIfNull(this);

			return  static_cast<T*>(comp.get());
		}
	}

	//delete component;
	//component = nullptr;

	LOG("Cannot Add component");
	return nullptr;
}
