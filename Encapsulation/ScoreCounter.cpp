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
	if (!scoreText->loadFont("Montserrat-Regular.ttf", 28)) {
		std::cerr << "Failed to load Font text Score!" << std::endl;
		delete scoreText;
		return;
	}

	std::string string = "Score : 0";
	scoreText->loadText(string);

	int centerX = scoreText->getCenterX(posX*2);
	scoreText->setPosition(centerX, posY);
}

ScoreCounter::~ScoreCounter()
{
	delete scoreText;
}

void ScoreCounter::Update()
{
	std::string string = "Score : " + std::to_string(static_cast<int>(score));
	scoreText->loadText(string);
}

void ScoreCounter::Draw()
{
	GameManager::Instance().getWindow()->drawText(*scoreText);
}

void ScoreCounter::AddToScore(int point)
{
	score += point;
}

int ScoreCounter::GetScore()
{
	return static_cast<int>(score);
}

