#include "Scene.h"
#include "Core/Object/GameObject.h"
#include <string>
Scene::~Scene()
{
	for (auto& actor : actorList)
	{
		if (actor)
		{
			delete actor;
			actor = nullptr;
		}
	}
}
void Scene::AddActor(GameObject * object)
{
	if (object)
	{
		for (auto& actor : actorList)
		{
			if (!actor)
			{
				actor = object;
				actor->SetId(nextActorId);
				++nextActorId;
			}
		}
	}
}

void Scene::RemoveActor(const std::string & name)
{
	for (auto& actor : actorList)
	{
		if (actor && actor->GetName() == name)
		{
			delete actor;
			actor = nullptr;
		}
	}
}

void Scene::RemoveActor(int id)
{
	for (auto& actor : actorList)
	{
		if (actor && actor->GetId() == id)
		{
			delete actor;
			actor = nullptr;
		}
	}
}