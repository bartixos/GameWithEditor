#pragma once
#pragma once
#include <chrono>
#include "Utility/Define.h"
#include "ASingleton.h"
class GameTimer : public ASingleton<GameTimer>
{
private:

	std::chrono::time_point<std::chrono::high_resolution_clock> startFrame;
	std::chrono::time_point<std::chrono::high_resolution_clock> finishFrame;

	static inline float timeScale = 1;
	float elapsedTime = 0;

public:
	GameTimer()
	{
		startFrame = std::chrono::high_resolution_clock::now();
	}

	static	void SetTimeScale(float scale) noexcept
	{
		timeScale = scale;
	}

	static	float GetTimeScale()  noexcept
	{
		return timeScale;
	}

	float GetElapsedTime() const noexcept
	{
		return elapsedTime * timeScale;
	}

	void UpdateElapsedTime()
	{
		finishFrame = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> elapsed = finishFrame - startFrame;
		elapsedTime = elapsed.count();
		startFrame = std::chrono::high_resolution_clock::now();
	}
};
