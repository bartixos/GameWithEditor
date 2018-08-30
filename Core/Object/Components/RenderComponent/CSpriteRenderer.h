#pragma once
#include "CARenderer.h"
#include "Core/Resource/TextureManager.h"
namespace sf
{
	class Sprite;
	class Texture;
}

class CSpriteRenderer :public CARenderer
{
	UniquePtr<sf::Sprite> sprite;
	SharedPtr<sf::Texture> texture;

	TextureManager *textureManager;
public:
	CSpriteRenderer(GameObject * owner);

	void LoadTexture(const std::string &name, const std::string& path) noexcept;
	void SetTexture(const sf::Texture& tex) noexcept;

	sf::Texture *GetTexture()const noexcept;

	virtual void Initialize() override;
	// Inherited via CARenderer
	virtual void Draw(sf::RenderWindow & window) override;

	virtual void Update(float delta) override;
};