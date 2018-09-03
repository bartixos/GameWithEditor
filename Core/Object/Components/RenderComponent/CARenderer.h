#pragma once
#include "../AComponent.h"
#include <cereal/types/polymorphic.hpp>
#include "Core/Math/Vector2.h"
namespace sf
{
	class RenderWindow;
}

class CARenderer : public AComponent
{
protected:
	Vector2 positionOffest;
	friend cereal::access;
public:
	CARenderer(GameObject * owner);
	CARenderer()
	{
		componentType = ComponentType::Renderer;
	}
	Vector2 GetOffsetPosition() const noexcept
	{
		return positionOffest;
	}

	void SetOffsetPosition(const Vector2& _offset) noexcept
	{
		positionOffest = _offset;
	}

	void SetOffsetPosition(float x, float y)noexcept
	{
		positionOffest.x = x;
		positionOffest.y = y;
	}

	// Inherited via AComponent
	virtual void Initialize() override;

	virtual void Draw(sf::RenderWindow &window) = 0;

	//template<typename Archive>
	//void save(Archive& archive) const
	//{
	//	archive(cereal::virtual_base_class<AComponent>(this), CEREAL_NVP_("Offset", positionOffest));
	//}
	//template<typename Archive>
	//void load(Archive& archive)
	//{
	//	//archive(cereal::virtual_base_class<AComponent>(this), CEREAL_NVP_("Offset", positionOffest));
	//	archive(cereal::virtual_base_class<AComponent>(this), positionOffest);
	//}
	template<typename Archive>
	void serialize(Archive &ar)
	{
		ar(cereal::base_class<AComponent>(this), CEREAL_NVP_("Position offset", positionOffest));
	}
};
CEREAL_REGISTER_TYPE(CARenderer);
CEREAL_REGISTER_POLYMORPHIC_RELATION(AComponent, CARenderer);