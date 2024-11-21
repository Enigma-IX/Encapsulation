#include "ScoreCounter.h"
#include "GameManager.h"
#include "framework.h"


ScoreCounter::ScoreCounter()
{
	scoreText = GameManager::Instance().getWindow()->createText();
	Init();
}

void ScoreCounter::Init()
{
	if (!scoreText->loadFont("Montserrat-Regular.ttf", 18)) {
		std::cerr << "Failed to load Font text Score!" << std::endl;
		delete scoreText;
		return;
	}
	scoreText->setPosition(WIN_WIDTH / 2, 0);
	std::string fpsString = "Score : 0";
	scoreText->loadText(fpsString);
}

ScoreCounter::~ScoreCounter()
{
	delete scoreText;
}

void ScoreCounter::Update()
{
	elapsedTime += TimeManager::Instance().GetDeltaTime();

	if (elapsedTime >= 1)
	{
		score = TimeManager::Instance().GetTotalTime();
		elapsedTime = 0;

		std::string fpsString = "Score : " + std::to_string(static_cast<int>(score));
		scoreText->loadText(fpsString);
	}
}

void ScoreCounter::Draw()
{
	GameManager::Instance().getWindow()->drawText(*scoreText);
}
