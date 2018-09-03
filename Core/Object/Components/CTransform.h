#pragma once

#include "AComponent.h"
#include "../../Math/Vector2.h"

class CTransform : public AComponent
{
	Vector2 position;
	float rotation = 0;
	friend cereal::access;
public:
	explicit	CTransform(GameObject *owner);
	CTransform();

	//template<typename Archive>
	//void save(Archive& archive) const
	//{
	//	archive(cereal::virtual_base_class<AComponent>(this), CEREAL_NVP_("position", position), CEREAL_NVP_("rotation", rotation));
	//}
	//template<typename Archive>
	//void load(Archive& archive)
	//{
	//	//archive(cereal::virtual_base_class<AComponent>(this), CEREAL_NVP_("position", position), CEREAL_NVP_("rotation", rotation));
	//	archive(cereal::virtual_base_class<AComponent>(this), position, rotation);
	//}

	template<typename Archive>
	void serialize(Archive &ar)
	{
		ar(cereal::virtual_base_class<AComponent>(this), CEREAL_NVP_("position", position), CEREAL_NVP_("rotation", rotation));
	}

	FORCEINLINE  Vector2 GetPosition() const noexcept
	{
		return position;
	}

	FORCEINLINE float GetRotation() const noexcept
	{
		return rotation;
	}

	//Setting Position
	FORCEINLINE void SetPosition(const Vector2& vec) noexcept
	{
		position = vec;
	}
	FORCEINLINE void SetPosition(float x, float y) noexcept
	{
		position.x = x;
		position.y = y;
	}

	//Add parameter to current position
	FORCEINLINE void Move(const Vector2& move) noexcept
	{
		position += move;
	}
	FORCEINLINE void Move(float x, float y) noexcept
	{
		position.x += x;
		position.y += y;
	}

	//Set Rotation
	FORCEINLINE void SetRotation(float _rotation) noexcept
	{
		rotation = _rotation;
	}
	//Add parameter to current rotation
	FORCEINLINE void Rotate(float _rotate) noexcept
	{
		rotation += _rotate;
	}

	// Inherited via AComponent
	virtual void Initialize() override;
};
CEREAL_REGISTER_TYPE(CTransform);
CEREAL_REGISTER_POLYMORPHIC_RELATION(AComponent, CTransform);