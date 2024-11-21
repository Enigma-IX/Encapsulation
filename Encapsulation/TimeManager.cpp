#include "TimeManager.h"


TimeManager::TimeManager()
{
	lastTimePoint = std::chrono::high_resolution_clock::now();
	deltaTime = 0.0;
	totalTime = 0;
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
	totalTime += deltaTime;
	lastTimePoint = currentTimePoint;
}

double TimeManager::GetFrameRate() const
{
	if (deltaTime > 0.0)
		return 1.0 / deltaTime;
	return 0.0;
}

double TimeManager::GetTotalTime() const
{
	return totalTime;
}