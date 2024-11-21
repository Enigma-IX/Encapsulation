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
	ball = new Ball();
	scoreCounter = new ScoreCounter();

	player1 = new Player(1, WIN_WIDTH - 70.0f, WIN_HEIGHT / 2 - 50.0f);

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
		ball->InvertDirectionX();
	}

}

void BrickGameMode::EndGameMode()
{
	delete ball;
	delete fpsCounter;
	delete scoreCounter;

	delete player1;
}

