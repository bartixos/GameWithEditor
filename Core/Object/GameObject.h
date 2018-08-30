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

namespace sf
{
	class RenderWindow;
}

class GameObject
{
	constexpr inline static  int maxComponentNumber = 16;
	std::array<AComponent *, maxComponentNumber> componentList;
protected:
	std::string tag = "";
	std::string name = "GameObject";

	UniquePtr<CTransform> transform;
	CARenderer *renderer;
	//todo: Add RenderComponent and Set it in AddComponent
public:
	GameObject();
	virtual ~GameObject();

	AComponent* AddComponent(AComponent* component);
	const std::string&  GetTag() const noexcept { return tag; };
	const std::string& GetName() const noexcept { return name; };
	void SetName(const std::string& _name) noexcept { name = _name; };
	void SetTag(const std::string &_tag) noexcept { tag = _tag; };

	CTransform *GetTransform() const noexcept { return transform.get(); };
	Vector2 GetPosition() const noexcept { return transform->GetPosition(); };
	//todo: ADD GetComponent
	void ComponentUpdate(float delta);
	void ComponentInitialize();
	void Draw(sf::RenderWindow& window);
	virtual void Initialize();
	virtual void Update(float delta);

	template<typename T>
	T* GetComponent();

	//////////////////////////////////TEST//////////////////////////////
	UniquePtr<CSpriteRenderer> sprite;
};

template<typename T>
inline T * GameObject::GetComponent()
{
	static std::string name = typeid(T).name();
	for (int i = 0; componentList.size(); i++)
	{
		if (name == typeid(*componentList[i]).name())
		{
			return static_cast<T*>(componentList[i]);
		}
	}
	return nullptr;
}
