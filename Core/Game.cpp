#include "Game.h"
#include "Utility/FPSCounter.h"
#include "Utility/GameTimer.h"
#include "Core/Object/GameObject.h"
#include "cereal/types/memory.hpp"
#include <fstream>
#include <cereal/archives/binary.hpp>
#include<cereal/types/vector.hpp>
#include <cereal/types/polymorphic.hpp>

Game::~Game()
{
	/*gameTimer = nullptr;
	fpsCounter = nullptr;
	window = nullptr;
	windowManager = nullptr;*/
}
void Game::Initialize()
{
	windowManager = &*WindowManager::GetInstance();
	window = windowManager->CreateWindow();

	fpsCounter = &*FpsCounter::GetInstance();
	fpsCounter->Initialize();

	gameTimer = &*GameTimer::GetInstance();

	currentScene = std::make_unique<Scene>();

	GameObject* object = new GameObject();
	GameObject* object2 = new GameObject();

	currentScene->AddActor(object);
	currentScene->AddActor(object2);

	currentScene->Initialize();

	object->SetName("Object 1");
	object2->SetName("Object 2");
	object->GetTransform()->SetPosition(400, 500);
	object2->GetTransform()->SetPosition(200, 400);

	Run();
}

void Game::LoadSene(const std::string & name, const std::string & path)
{
	if (currentScene)
	{
		currentScene->DestroyScene();
	}
}

void Game::Load(const std::string & name)
{
	currentScene.reset();

	std::string path = "Saves/" + name + ".txt";
	std::ifstream load(path);
	cereal::BinaryInputArchive archive(load);
	archive(currentScene);
	load.close();
}

void Game::Save(const std::string & name)
{
	std::string path = "Saves/" + name + ".txt";
	std::ofstream save(path);
	cereal::BinaryOutputArchive archive(save);
	archive(currentScene);
	save.close();
}

void Game::Run()
{
	//todo: Dodac cos w stylu Event Manager
	while (window->isOpen())
	{
		while (window->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
			{
				window->close();
			}

			default:
				break;
			}

			if (event.type == sf::Event::KeyReleased &&	event.key.code == sf::Keyboard::S)
			{
				LOG(currentScene->ActorCount());
				Save("save1");
			}

			if (event.type == sf::Event::KeyReleased &&	event.key.code == sf::Keyboard::L)
			{
				Load("save1");
				LOG(currentScene->ActorCount());
			}
		}
		fpsCounter->Update();
		gameTimer->UpdateElapsedTime();

		if (currentScene)
		{
			currentScene->Update(gameTimer->GetElapsedTime());
		}

		window->clear(sf::Color::Blue);
		if (currentScene)
		{
			currentScene->Draw(*window);
		}
		fpsCounter->Draw(*window);
		window->display();
	}
}