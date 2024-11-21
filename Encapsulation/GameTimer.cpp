#include "GameTimer.h"

#include "GameManager.h"
#include "framework.h"


GameTimer::GameTimer(float posX, float posY, int duration)
{
	timerText = GameManager::Instance().getWindow()->createText();
	Init(posX, posY, duration);
}

void GameTimer::Init(float posX, float posY, int duration)
{
	startTime = duration;

	if (!timerText->loadFont("Montserrat-Regular.ttf", 28)) {
		std::cerr << "Failed to load Font text Score!" << std::endl;
		delete timerText;
		return;
	}
	
	timerText->setPosition(posX, posY);

	std::string string = "Timer : ";
	timerText->loadText(string);

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

		std::string string;
		if (timer < 1)
		{
			string = "Timer : Time's Up!";
			timer = 0;
			timerText->loadText(string);

			GameManager::Instance().EndGame();
			return;
		}
		else
		{
			string = "Timer : " + std::to_string(static_cast<int>(timer));
			timerText->loadText(string);
			return;
		}
	}
}

void GameTimer::Draw()
{
	GameManager::Instance().getWindow()->drawText(*timerText);
}
