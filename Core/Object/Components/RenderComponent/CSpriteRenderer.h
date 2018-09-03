#pragma once
#include "CARenderer.h"
#include "Core/Resource/TextureManager.h"
#include <cereal/types/string.hpp>
namespace sf
{
	class Sprite;
	class Texture;
}

class CSpriteRenderer :public CARenderer
{
	UniquePtr<sf::Sprite> sprite;
	sf::Texture* texture = nullptr;
	friend cereal::access;
	std::string texName = "";
	std::string texPath = "";
	TextureManager *textureManager = nullptr;
public:
	explicit	CSpriteRenderer(GameObject * owner);
	CSpriteRenderer()
	{
		textureManager = &*TextureManager::GetInstance();
		sprite = std::make_unique<sf::Sprite>();
	}
	void LoadTexture(const std::string &name, const std::string& path) noexcept;
	void SetTexture(const sf::Texture& tex) noexcept;

	std::string GetTextureName()noexcept
	{
		return texName;
	}

	std::string GetTexturePath() noexcept
	{
		return texPath;
	}

	sf::Texture *GetTexture()const noexcept;

	virtual void Initialize() override;
	// Inherited via CARenderer
	virtual void Draw(sf::RenderWindow & window) override;

	virtual void Update(float delta) override;
	//template<typename Archive>
	//void save(Archive& archive) const
	//{
	//	archive(cereal::virtual_base_class<CARenderer>(this), CEREAL_NVP_("Texture Name", texName), CEREAL_NVP_("Texture Path", texPath));
	//}
	//template<typename Archive>
	//void load(Archive& archive)
	//{
	//	//archive(cereal::base_class<CARenderer>(this), cereal::base_class<CARenderer>(this), CEREAL_NVP_("Offset", positionOffest), CEREAL_NVP_("Texture Name", texName), CEREAL_NVP_("Texture Path", texPath));
	//	archive(cereal::virtual_base_class<CARenderer>(this), texName, texPath);
	//	//Initialize();
	//	//LoadTexture(texName, texPath);
	//}

	template<typename Archive>
	void serialize(Archive &ar)
	{
		ar(cereal::base_class<CARenderer>(this), CEREAL_NVP_("Texture Name", texName), CEREAL_NVP_("Texture Path", texPath));
	}
};
CEREAL_REGISTER_TYPE(CSpriteRenderer);
CEREAL_REGISTER_POLYMORPHIC_RELATION(AComponent, CSpriteRenderer);
