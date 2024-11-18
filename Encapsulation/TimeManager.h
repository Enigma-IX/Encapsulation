#include <chrono>

class TimeManager {
public:
	// Singleton instance
	static TimeManager& Instance()
	{
		static TimeManager instance;
		return instance;
	}

	TimeManager(const TimeManager&) = delete;
	TimeManager& operator=(const TimeManager&) = delete;

	// Update du DeltaTime
	void Update()
	{
		auto currentTimePoint = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsedTime = currentTimePoint - lastTimePoint;
		deltaTime = elapsedTime.count();
		lastTimePoint = currentTimePoint;
	}

	// Get DeltaTime
	double GetDeltaTime() const
	{
		return deltaTime;
	}

private:
	// Constructeur privé pour le Singleton
	TimeManager()
	{
		lastTimePoint = std::chrono::high_resolution_clock::now();
		deltaTime = 0.0;
	}

	std::chrono::high_resolution_clock::time_point lastTimePoint;
	double deltaTime;
};

