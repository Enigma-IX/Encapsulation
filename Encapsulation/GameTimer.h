#pragma once
#include "Text.h"
#include "Window.h"


class GameTimer
{
public:
	GameTimer(float posX, float posY);
	void Init(float posX, float posY);
	~GameTimer();

	void Update();
	void Draw();

private:

	int startTime;

	Text* timerText;
	double timer;
	double elapsedTime;
};

