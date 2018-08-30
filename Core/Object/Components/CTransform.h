#pragma once

#include "AComponent.h"
#include "../../Math/Vector2.h"
class CTransform : public AComponent
{
	Vector2 position;
	float rotation;

public:
	explicit CTransform(GameObject *owner);
	CTransform() = delete;
	CTransform(const AComponent& comp);
	CTransform(AComponent&& comp);

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