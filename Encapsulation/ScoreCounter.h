#pragma once
#include "Text.h"
#include "Window.h"

class ScoreCounter
{
public:
	ScoreCounter(float posX, float posY);
	void Init(float posX, float posY);
	~ScoreCounter();

	void Update();
	void Draw();

private:
	Text* scoreText;
	double score;
	double elapsedTime;
};

