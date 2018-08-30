#pragma once
#include "../AComponent.h"
#include "Core/Math/Vector2.h"
namespace sf
{
	class RenderWindow;
}

class CARenderer : public AComponent
{
protected:
	Vector2 positionOffest;

public:
	CARenderer(GameObject * owner);

	const Vector2& GetOffsetPosition() const noexcept
	{
		return positionOffest;
	}

	void SetOffsetPosition(const Vector2& _offset) noexcept
	{
		positionOffest = _offset;
	}

	// Inherited via AComponent
	virtual void Initialize() override;

	virtual void Draw(sf::RenderWindow &window) = 0;
};