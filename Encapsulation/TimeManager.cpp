#include "TimeManager.h"


TimeManager::TimeManager()
{
	lastTimePoint = std::chrono::high_resolution_clock::now();
	deltaTime = 0.0;
}

TimeManager& TimeManager::Instance()
{
	static TimeManager instance;
	return instance;
}

void TimeManager::Update()
{
	auto currentTimePoint = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsedTime = currentTimePoint - lastTimePoint;
	deltaTime = elapsedTime.count();
	lastTimePoint = currentTimePoint;
}