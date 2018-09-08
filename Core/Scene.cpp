#include "Scene.h"
#include "Core/Object/GameObject.h"
#include <string>
#include <SFML/Graphics.hpp>

Scene::Scene()
{
}
Scene::~Scene()
{
	actorList.clear();
}
void Scene::AddActor(GameObject * object)
{
	if (object)
	{
		actorList.push_back(UniquePtr<GameObject>(object));
		object->SetId(nextActorId);
		++nextActorId;
	}
}

void Scene::RemoveActor(const std::string & name)
{
	/*for (auto& actor : actorList)
	{
		if (actor && actor->GetName() == name)
		{
			actor.reset();
		}
	}*/
}

void Scene::RemoveActor(int id)
{
	/*for (auto& actor : actorList)
	{
		if (actor && actor->GetId() == id)
		{
			actor.reset();
		}
	}*/
}

void Scene::DestroyScene()
{
}

void Scene::Initialize()
{
	//for (auto& actor : actorList)
	//{
	//	if (actor)
	//	{
	//		actor->ComponentInitialize();
	//		actor->Initialize();
	//	}
	//}
}

void Scene::Update(float delta)
{
	/*for (auto& actor : actorList)
	{
		if (actor)
		{
			actor->ComponentUpdate(delta);
			actor->Update(delta);
		}
	}*/
}

void Scene::Draw(sf::RenderWindow & window)
{
	for (auto& actor : actorList)
	{
		if (actor)
		{
			actor->Draw(window);
		}
	}
}