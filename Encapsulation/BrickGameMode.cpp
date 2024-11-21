#include "BrickGameMode.h"

BrickGameMode::BrickGameMode()
{
}

BrickGameMode::~BrickGameMode()
{

}

bool BrickGameMode::InitGameMode()
{
	fpsCounter = new FPSCounter();
  
	scoreCounter = new ScoreCounter(WIN_WIDTH / 4, WIN_HEIGHT);
	ball = new Ball(WIN_WIDTH / 2, WIN_HEIGHT / 2);

	player1 = new Player(1, WIN_WIDTH / 2, WIN_HEIGHT - 50, false);

	return true;
}

void BrickGameMode::UpdateGameMode()
{
	ball->Update();
	fpsCounter->Update();
	scoreCounter->Update();

	player1->Update();

}

void BrickGameMode::Draw()
{
	ball->Draw();
	fpsCounter->Draw();
	scoreCounter->Draw();

	player1->Draw();
}

void BrickGameMode::CheckCollision()
{
	if (ball->CheckCollisionWithPlayer(player1))
	{
		ball->InvertDirectionY();
	}

	if (ball->CheckCollisionWithTopWall() || ball->CheckCollisionWithBottomWall()) {
		ball->InvertDirectionY();
	}

	if (ball->CheckCollisionWithLeftWall() || ball->CheckCollisionWithRightWall()) {
		ball->InvertDirectionX();
	}
}

void BrickGameMode::EndGameMode()
{
	//TO DO: Logique de cleanup avant de Wipe
	WipeGameMode();
}

void BrickGameMode::WipeGameMode()
{
	delete ball;
	delete fpsCounter;
	delete scoreCounter;

	delete player1;

}

