#pragma once
#include "Core/Resource/WindowManager.h"
#include <SFML/Graphics.hpp>
class FpsCounter;
class GameTimer;

class Game
{
	GameTimer *gameTimer = nullptr;
	FpsCounter *fpsCounter = nullptr;
	WindowManager* windowManager = nullptr;
	sf::RenderWindow *window = nullptr;
	UniquePtr<sf::Event> event = nullptr;
	void Run();
public:
	~Game();

	void Initialize();
};