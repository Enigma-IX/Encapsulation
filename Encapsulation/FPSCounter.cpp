#include "FPSCounter.h"

FPSCounter::FPSCounter(Text* texte) : frameCount(0), elapsedTime(0.0), FPS(0.0)
{
	fpsText = texte;
}

FPSCounter::~FPSCounter()
{
	delete fpsText;
}

void FPSCounter::Update(double deltaTime)
{
	elapsedTime += deltaTime;
	frameCount++;

	if (elapsedTime >= 1)
	{
		FPS = frameCount / elapsedTime;
		frameCount = 0;
		elapsedTime = 0;

		std::string fpsString = "FPS : " + std::to_string(static_cast<int>(FPS));
	}
}

void FPSCounter::Renderer()
{
	fpsText->render();
}
