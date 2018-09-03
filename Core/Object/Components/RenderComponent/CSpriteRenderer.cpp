#include "CSpriteRenderer.h"
#include "Core/Object/GameObject.h"
#include <SFML/Graphics.hpp>
#include <cereal/types/polymorphic.hpp>
CSpriteRenderer::CSpriteRenderer(GameObject * owner) :
	CARenderer(owner)

{
	textureManager = &*TextureManager::GetInstance();
	sprite = std::make_unique<sf::Sprite>();
	//name = "Sprite_Renderer";
}

void CSpriteRenderer::LoadTexture(const std::string & name, const std::string & path) noexcept
{
	texture = textureManager->LoadResource(name, path);
	if (texture)
	{
		texName = std::move(name);
		texPath = std::move(path);
		SetTexture(*texture);
	}
}

void CSpriteRenderer::SetTexture(const sf::Texture & tex) noexcept
{
	sprite->setTexture(tex);
}

sf::Texture * CSpriteRenderer::GetTexture() const noexcept
{
	return texture;
}

void CSpriteRenderer::Initialize()
{
	textureManager = &*TextureManager::GetInstance();
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