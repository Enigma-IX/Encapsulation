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
	winnerText->setPosition(posX, posY);
	std::string string = " Win !";
	winnerText->loadText(string);
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
	GameManager::Instance().getWindow()->drawText(*winnerText);
}

void Winner::SetWinner(const std::string& winner)
{
	winnerPlayer = winner;
}


