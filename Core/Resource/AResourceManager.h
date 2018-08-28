#pragma once
#include "Utility/Define.h"
#include <unordered_map>
#include "SFML/Graphics.hpp"
//Resource manager for sfml resources
template<typename T>
class ResourceManager
{
protected:
	using ResourcesMap = std::unordered_map<std::string, SharedPtr<T>>;
	ResourcesMap resourceMap;

	ResourceManager();
	ResourceManager(const ResourceManager&) = delete;
	ResourceManager(ResourceManager&&) = delete;

public:

	virtual ~ResourceManager() { resourceMap.clear(); };

	bool Exist(const std::string &name);

	//Load from file and get resources
	//Path is a from folder "Assets/path"
	SharedPtr<T> LoadResource(const std::string &name, const std::string &path);
	//Get resource if is Loaded else return null
	SharedPtr<T> GetResource(const std::string &name);
};

template<typename T>
inline ResourceManager<T>::ResourceManager()
{
	resourceMap.clear();
}

template<typename T>
inline bool ResourceManager<T>::Exist(const std::string & name)
{
	if (resourceMap[name])
		return true;

	else
		return false;
}

template<typename T>
inline SharedPtr<T> ResourceManager<T>::LoadResource(const std::string & name, const std::string & path)
{
	if (Exist(name))
	{
		return std::move(resourceMap[name]);
	}
	else
	{
		std::string _path("Assets/" + path);

		resourceMap.insert_or_assign(name, std::make_shared<T>());
		if (!resourceMap[name]->loadFromFile(_path))
		{
			LOG("Cannot Load Texture: " + name + " path: " + _path);
		}

		return resourceMap[name];
	}
}

template<typename T>
inline SharedPtr<T> ResourceManager<T>::GetResource(const std::string & name)
{
	if (Exist(name))
	{
		return resourceMap[name];
	}
	else
		return nullptr;
}
