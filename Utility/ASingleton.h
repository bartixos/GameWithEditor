#pragma once
#include "Define.h"
template <typename T>
class ASingleton
{
protected:
	ASingleton()
	{
	}

	static inline SharedPtr<T> instnace = nullptr;

public:

	static SharedPtr<T> GetInstance()
	{
		if (!instnace)
		{
			instnace = SharedPtr<T>(new T);
		}
		return instnace;
	}
};
