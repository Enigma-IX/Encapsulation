#pragma once
#include "GameMode.h"

#include "Ball.h"
#include "FPSCounter.h"


class DemoGameMode : public GameMode
{
private:

	Ball* ball;
	FPSCounter* fpsCounter;
	
public:
	DemoGameMode();
	~DemoGameMode();

	bool InitGameMode() override;
	void UpdateGameMode() override;
	void Draw() override;
	void EndGameMode() override;
};

