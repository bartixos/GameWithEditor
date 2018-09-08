#pragma once
#include "Core/Resource/WindowManager.h"
#include "Utility/Define.h"
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include <cereal/access.hpp>
class FpsCounter;
class GameTimer;

class Game
{
	friend cereal::access;
	GameTimer *gameTimer = nullptr;
	FpsCounter *fpsCounter = nullptr;
	WindowManager* windowManager = nullptr;
	sf::RenderWindow *window = nullptr;
	sf::Event event;
	void Run();

public:
	UniquePtr<Scene> currentScene = nullptr;
	~Game();

	void Initialize();
	void LoadSene(const std::string &name, const std::string& path);
	void Load(const std::string& name);
	void Save(const std::string& name);
};
