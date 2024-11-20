#include "FPSCounter.h"
#include "GameManager.h"

FPSCounter::FPSCounter() : frameCount(0), elapsedTime(0.0), FPS(0.0)
{
	fpsText = GameManager::Instance().getWindow()->createText();
	Init();
}

void FPSCounter::Init()
{
	if (!fpsText->loadFont("Montserrat-Regular.ttf", 18)) {
		std::cerr << "Failed to load Font text FPS!" << std::endl;
		delete fpsText;
		return;
	}
		fpsText->setPosition(0, 0);
		std::string fpsString = "FPS : 0";
		fpsText->loadText(fpsString);
}

FPSCounter::~FPSCounter()
{
	delete fpsText;
}

void FPSCounter::Update()
{
	elapsedTime += TimeManager::Instance().GetDeltaTime();
	frameCount++;

	if (elapsedTime >= 1)
	{
		FPS = frameCount / elapsedTime;
		frameCount = 0;
		elapsedTime = 0;

		std::string fpsString = "FPS : " + std::to_string(static_cast<int>(FPS));
		fpsText->loadText(fpsString);
	}
}

void FPSCounter::Draw()
{
	GameManager::Instance().getWindow()->drawText(*fpsText);
}