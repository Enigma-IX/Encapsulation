#include <chrono>

class TimeManager {
public:
	// Singleton instance
	static TimeManager& Instance();

	TimeManager(const TimeManager&) = delete;
	TimeManager& operator=(const TimeManager&) = delete;

	void Update();

	double GetDeltaTime() const { return deltaTime; }
	double GetFrameRate() const;
	double GetTotalTime() const;


private:
	// Constructeur privé pour le Singleton
	TimeManager();

	std::chrono::high_resolution_clock::time_point lastTimePoint;
	double deltaTime;
	int totalTime;
};

