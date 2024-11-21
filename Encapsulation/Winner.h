#pragma once
#include "Text.h"
#include "Window.h"

class Winner
{
public:
	Winner(float posX, float posY, const std::string& winner = " Win !");
	void Init(float posX, float posY, const std::string& winner);
	~Winner();

	void Update();
	void Draw();
	void SetWinner(const std::string& winner);

private:
	Text* winnerText;
	std::string winnerPlayer = "";
};

