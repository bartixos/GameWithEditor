#pragma once

#include "Define.h"
#include "ASingleton.h"
namespace sf
{
	class RenderWindow;
	class Text;
	class Font;
	class Clock;
}

class FpsCounter : public ASingleton<FpsCounter>
{
public:
	//Update FPS Counter
	void Update();
	//Draw Fps text
	void Draw(sf::RenderWindow & window);
	//Initialize FPS Counter
	void Initialize();

	FpsCounter();
private:

	UniquePtr<sf::Text> text;
	sf::Font* font;

	UniquePtr<sf::Clock> delayTimer;
	UniquePtr<sf::Clock> fpsTimer;

	float fps = 0;

	float frameCount;
};
