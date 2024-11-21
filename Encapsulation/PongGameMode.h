#pragma once
#include "GameMode.h"

#include "Ball.h"
#include "FPSCounter.h"
#include "ScoreCounter.h"
#include "GameTimer.h"

class PongGameMode : public GameMode
{
private:

	Ball* ball;
	FPSCounter* fpsCounter;
	GameTimer* timer;

	ScoreCounter* scoreCounterP1;
	ScoreCounter* scoreCounterP2;

	Player* player1;
	Player* player2;


public:
	PongGameMode();
	~PongGameMode();

	bool InitGameMode() override;
	void UpdateGameMode() override;
	void Draw() override;
	void CheckCollision() override;
	void EndGameMode() override;
	void WipeGameMode() override;

};

