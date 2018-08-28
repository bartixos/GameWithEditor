#pragma once
#include "AResourceManager.h"
#include <SFML/Graphics.hpp>
#include "Utility/ASingleton.h"
class TextureManager :public ResourceManager<sf::Texture>,
	public ASingleton<TextureManager>
{
private:

	//static SharedPtr<TextureManager> instnace;

public:
	TextureManager() {};

	/*static SharedPtr<TextureManager> GetInstance()
	{
		if (!instnace)
		{
			instnace = SharedPtr<TextureManager>(new TextureManager);
		}
		return std::move(instnace);
	}*/
};