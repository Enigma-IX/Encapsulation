#include "ScoreCounter.h"
#include "GameManager.h"
#include "framework.h"


ScoreCounter::ScoreCounter(float posX, float posY)
{
	scoreText = GameManager::Instance().getWindow()->createText();
	Init(posX, posY);
}

void ScoreCounter::Init(float posX, float posY)
{
	if (!scoreText->loadFont("Montserrat-Regular.ttf", 18)) {
		std::cerr << "Failed to load Font text Score!" << std::endl;
		delete scoreText;
		return;
	}
	scoreText->setPosition(posX, posY);
	std::string fpsString = "Score : 0";
	scoreText->loadText(fpsString);
}

ScoreCounter::~ScoreCounter()
{
	delete scoreText;
}

void ScoreCounter::Update()
{
	std::string fpsString = "Score : " + std::to_string(static_cast<int>(score));
	scoreText->loadText(fpsString);
}

void ScoreCounter::Draw()
{
	GameManager::Instance().getWindow()->drawText(*scoreText);
}

void ScoreCounter::AddToScore(int point)
{
	score += point;
}