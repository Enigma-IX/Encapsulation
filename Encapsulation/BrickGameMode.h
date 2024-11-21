#pragma once
#include <vector>
#include "GameMode.h"

#include "Ball.h"
#include "FPSCounter.h"
#include "ScoreCounter.h"
#include "Brick.h"

class BrickGameMode : public GameMode
{
private:

	std::vector<Brick*> bricks;
	Ball* ball;
	FPSCounter* fpsCounter;
	ScoreCounter* scoreCounter;
	void InitBricks();

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



