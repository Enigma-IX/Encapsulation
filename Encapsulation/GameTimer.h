#pragma once
#include "Text.h"
#include "Window.h"


class GameTimer
{
public:
	GameTimer(float posX, float posY, int duration = 10);
	void Init(float posX, float posY, int duration);
	~GameTimer();

	void Update();
	void Draw();

private:

	int startTime;

	Text* timerText;
	double timer;
	double elapsedTime;
};

