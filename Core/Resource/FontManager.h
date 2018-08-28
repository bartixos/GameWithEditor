#pragma once
#include "AResourceManager.h"
#include <SFML/Graphics.hpp>
#include "Utility/ASingleton.h"
class FontManager :public ResourceManager<sf::Font>,
	public ASingleton<FontManager>
{
public:
	FontManager()
	{
	}
};
