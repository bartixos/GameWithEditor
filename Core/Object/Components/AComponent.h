#pragma once
#include "Utility/Define.h"
#include <cereal/types/base_class.hpp>
enum class ComponentType
{
	Renderer,
	Transformable
};

class GameObject;
class AComponent
{
protected:
	ComponentType componentType;
	GameObject *owner;
	//if true Game object can have multiple component of this type
	bool canBeMultiple = false;
	//std::string name = "";

public:
	explicit AComponent(GameObject *owner);
	AComponent() = delete;
	AComponent(const AComponent& comp);
	AComponent(AComponent&& comp);

	virtual void Initialize() = 0;
	virtual void Update(float delta) {};

	virtual ~AComponent() { owner = nullptr; };

	void SetOwnerIfNull(GameObject *owner) noexcept { if (this->owner)this->owner = owner; };
	FORCEINLINE GameObject *GetOwner() noexcept { return owner; };
	FORCEINLINE bool CanBeMultiple() noexcept { return canBeMultiple; };
	FORCEINLINE ComponentType GetComponentType() noexcept { return componentType; };
	//FORCEINLINE std::string GetName() noexcept { return name; };
};