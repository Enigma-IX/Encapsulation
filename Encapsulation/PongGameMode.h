#pragma once
#include "GameMode.h"

#include "Ball.h"
#include "FPSCounter.h"
#include "ScoreCounter.h"

class PongGameMode : public GameMode
{
private:

	Ball* ball;
	FPSCounter* fpsCounter;
	ScoreCounter* scoreCounter;

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
};

