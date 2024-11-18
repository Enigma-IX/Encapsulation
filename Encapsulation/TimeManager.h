#include <chrono>

class TimeManager {
public:
	// Singleton instance access
	static TimeManager& Instance()
	{
		static TimeManager instance;
		return instance;
	}

	// Delete copy/move constructors
	TimeManager(const TimeManager&) = delete;
	TimeManager& operator=(const TimeManager&) = delete;

	// Update delta time
	void Update()
	{
		auto currentTimePoint = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsedTime = currentTimePoint - lastTimePoint;
		deltaTime = elapsedTime.count();
		lastTimePoint = currentTimePoint;
	}

	// Get delta time
	double GetDeltaTime() const
	{
		return deltaTime;
	}

private:
	// Private constructor for Singleton
	TimeManager()
	{
		lastTimePoint = std::chrono::high_resolution_clock::now();
		deltaTime = 0.0;
	}

	std::chrono::high_resolution_clock::time_point lastTimePoint;
	double deltaTime;
};

