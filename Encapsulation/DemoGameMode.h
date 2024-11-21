#pragma once
#include "GameMode.h"

#include "Ball.h"
#include "FPSCounter.h"
#include "ScoreCounter.h"


class DemoGameMode : public GameMode
{
private:

	Ball* ball;
	FPSCounter* fpsCounter;
	ScoreCounter* scoreCounter;
	
public:
	DemoGameMode();
	~DemoGameMode();

	bool InitGameMode() override;
	void UpdateGameMode() override;
	void Draw() override;
	void EndGameMode() override;
};

