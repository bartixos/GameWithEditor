#include "CSpriteRenderer.h"
#include "Core/Object/GameObject.h"
#include <SFML/Graphics.hpp>
CSpriteRenderer::CSpriteRenderer(GameObject * owner) :
	CARenderer(owner)
{
	textureManager = &*TextureManager::GetInstance();
	//name = "Sprite_Renderer";
}

void CSpriteRenderer::LoadTexture(const std::string & name, const std::string & path) noexcept
{
	texture = TextureManager::GetInstance()->LoadResource(name, path);
	if (texture)
	{
		SetTexture(*texture);
	}
}

void CSpriteRenderer::SetTexture(const sf::Texture & tex) noexcept
{
	sprite->setTexture(tex);
}

sf::Texture * CSpriteRenderer::GetTexture() const noexcept
{
	return &*texture;
}

void CSpriteRenderer::Initialize()
{
	sprite = std::make_unique<sf::Sprite>();
}

void CSpriteRenderer::Draw(sf::RenderWindow & window)
{
	if (sprite)
	{
		window.draw(*sprite);
	}
}

void CSpriteRenderer::Update(float delta)
{
	sprite->setPosition(static_cast<sf::Vector2f>(owner->GetPosition() + positionOffest));
}