#pragma once
#include <array>
#include <cereal/access.hpp>
#include<cereal/types/array.hpp>
#include <cereal/types/polymorphic.hpp>
class GameObject;
class Scene
{
	friend cereal::access;
	static constexpr int maxObjectNumber = 100;

	int nextActorId = 0;

	std::array<GameObject*, maxObjectNumber> actorList;

public:
	std::array<GameObject*, maxObjectNumber>& GetActorList()  noexcept
	{
		return actorList;
	}

	~Scene();

	void AddActor(GameObject *object);
	void RemoveActor(const std::string &name);
	void RemoveActor(int id);

	template<typename Archive>
	void serializa(Archive &ar)
	{
		ar(CEREAL_NVP_("Object List", actorList), CEREAL_NVP_("Next Actor Id", nextActorId));
	}
};
