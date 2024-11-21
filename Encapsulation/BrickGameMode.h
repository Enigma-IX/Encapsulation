#pragma once
#include "GameMode.h"

#include "Ball.h"
#include "FPSCounter.h"
#include "ScoreCounter.h"

class BrickGameMode : public GameMode
{
private:

	Ball* ball;
	FPSCounter* fpsCounter;
	ScoreCounter* scoreCounter;

	Player* player1;

public:
	BrickGameMode();
	~BrickGameMode();

	bool InitGameMode() override;
	void UpdateGameMode() override;
	void Draw() override;
	void CheckCollision() override;
	void EndGameMode() override;
	void WipeGameMode() override;

};



