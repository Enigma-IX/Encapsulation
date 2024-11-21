#pragma once
#include "Text.h"
#include "Window.h"

class ScoreCounter
{
public:
	ScoreCounter();
	void Init();
	~ScoreCounter();

	void Update();
	void Draw();

private:
	Text* scoreText;
	double score;
	double elapsedTime;
};

