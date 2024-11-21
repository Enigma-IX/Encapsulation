#include "GameTimer.h"

#include "GameManager.h"
#include "framework.h"


GameTimer::GameTimer(float posX, float posY) : startTime(120)
{
	timerText = GameManager::Instance().getWindow()->createText();
	Init(posX, posY);
}

void GameTimer::Init(float posX, float posY)
{
	if (!timerText->loadFont("Montserrat-Regular.ttf", 18)) {
		std::cerr << "Failed to load Font text Score!" << std::endl;
		delete timerText;
		return;
	}
	
	timerText->setPosition(posX, posY);
	std::string fpsString = "Timer : ";
	timerText->loadText(fpsString);

	int centerX = timerText->getCenterX(WIN_WIDTH);
	timerText->setPosition(centerX, posY);
}

GameTimer::~GameTimer()
{
	delete timerText;
}

void GameTimer::Update()
{
	elapsedTime += TimeManager::Instance().GetDeltaTime();

	if (elapsedTime >= 1)
	{
		timer = startTime - TimeManager::Instance().GetTotalTime();
		elapsedTime = 0;

		std::string fpsString;
		if (timer < 1)
		{
			fpsString = "Timer : Time's Up!";
			timer = 0;
			timerText->loadText(fpsString);

			GameManager::Instance().EndGame();
			return;
		}
		else
		{
			fpsString = "Timer : " + std::to_string(static_cast<int>(timer));
			timerText->loadText(fpsString);
			return;
		}
	}
}

void GameTimer::Draw()
{
	GameManager::Instance().getWindow()->drawText(*timerText);
}
