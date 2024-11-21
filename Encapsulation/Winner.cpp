#include "Winner.h"
#include "GameManager.h"
#include "framework.h"


Winner::Winner(float posX, float posY, const std::string& winner)
{
	winnerText = GameManager::Instance().getWindow()->createText();
	Init(posX, posY, winner);
}

void Winner::Init(float posX, float posY, const std::string& winner)
{
	if (!winnerText->loadFont("Montserrat-Regular.ttf", 100)) {
		std::cerr << "Failed to load Font text Score!" << std::endl;
		delete winnerText;
		return;
	}
	std::string string = "Nobody Win !";
	winnerText->loadText(string);

	int centerX = winnerText->getCenterX(posX * 2);
	int centerY = winnerText->getCenterY(posY * 2);
	winnerText->setPosition(centerX, centerY);
}

Winner::~Winner()
{
	delete winnerText;
}

void Winner::Update()
{
	std::string string = winnerPlayer + " Win !";
	winnerText->loadText(string);
}

void Winner::Draw()
{
	if (hasToBeDrawn)
		GameManager::Instance().getWindow()->drawText(*winnerText);
}

void Winner::SetWinner(const std::string& winner)
{
	winnerPlayer = winner;
	hasToBeDrawn = true;
}


