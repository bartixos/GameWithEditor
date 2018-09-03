#include "Game.h"
#include "Utility/FPSCounter.h"
#include "Utility/GameTimer.h"
Game::~Game()
{
	gameTimer = nullptr;
	fpsCounter = nullptr;
	window = nullptr;
	windowManager = nullptr;
}
void Game::Initialize()
{
	windowManager = &*WindowManager::GetInstance();
	window = windowManager->CreateWindow();

	fpsCounter = &*FpsCounter::GetInstance();
	fpsCounter->Initialize();
	event = std::make_unique<sf::Event>();

	gameTimer = &*GameTimer::GetInstance();

	Run();
}

void Game::Run()
{
	//todo: Dodac cos w stylu Event Manager
	while (window->isOpen())
	{
		while (window->pollEvent(*event.get()))
		{
			switch (event->type)
			{
			case sf::Event::Closed:
			{
				window->close();
			}

			default:
				break;
			}
		}
		fpsCounter->Update();
		gameTimer->UpdateElapsedTime();

		window->clear(sf::Color::Blue);
		fpsCounter->Draw(*window);
		window->display();
	}
}