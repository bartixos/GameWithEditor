#pragma once
#include "Utility/Define.h"
#include <cereal/types/base_class.hpp>
#include <cereal/types/polymorphic.hpp>

enum class ComponentType
{
	_default = 0,

	Renderer = 1,
	Transformable = 2
};

class GameObject;
class AComponent
{
	friend cereal::access;
protected:
	ComponentType componentType = ComponentType::_default;
	GameObject *owner;
	//if true Game object can have multiple component of this type
	bool canBeMultiple = false;
	//std::string name = "";

public:
	AComponent(GameObject *owner);
	AComponent();
	virtual void Initialize() = 0;
	virtual void Update(float delta) {};

	virtual ~AComponent() { owner = nullptr; };

	void SetOwnerIfNull(GameObject *owner) noexcept { if (!this->owner)this->owner = owner; };
	FORCEINLINE GameObject *GetOwner() noexcept { return owner; };
	FORCEINLINE bool CanBeMultiple() noexcept { return canBeMultiple; };
	FORCEINLINE ComponentType GetComponentType() noexcept { return componentType; };
	//FORCEINLINE std::string GetName() noexcept { return name; };

	/*template<typename Archive>
	void load(Archive& archive)
	{
		archive(componentType);
	}
	template<typename Archive>
	void save(Archive& archive) const
	{
		archive(componentType);
	}*/

	template<typename Archive>
	void serialize(Archive &ar)
	{
		ar(CEREAL_NVP_("Component Type", componentType));
	}
};
