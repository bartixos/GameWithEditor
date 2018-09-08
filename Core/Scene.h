#pragma once
#include "Utility/Define.h"
#include <array>
#include <cereal/access.hpp>
#include<cereal/types/vector.hpp>
#include <cereal/types/polymorphic.hpp>
#include "Core/Object/GameObject.h"

namespace sf
{
	class RenderWindow;
}

class Scene
{
	friend cereal::access;
	//static constexpr int maxObjectNumber = 100;

	int nextActorId = 0;

	std::vector<UniquePtr<GameObject>> actorList;

public:
	std::vector<UniquePtr<GameObject>>& GetActorList()  noexcept
	{
		return actorList;
	}
	Scene();

	~Scene();

	void AddActor(GameObject *object);
	void RemoveActor(const std::string &name);
	void RemoveActor(int id);
	void DestroyScene();
	void Initialize();
	void Update(float delta);
	void Draw(sf::RenderWindow &window);
	int ActorCount()noexcept { return actorList.size(); }
	template<typename Archive>
	void load(Archive &ar)
	{
		ar(CEREAL_NVP_("Object List", actorList), CEREAL_NVP_("Next Actor Id", nextActorId));
	}
	template<typename Archive>
	void save(Archive &ar) const
	{
		ar(CEREAL_NVP_("Object List", actorList), CEREAL_NVP_("Next Actor Id", nextActorId));
	}
};
