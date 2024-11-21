#include "PongGameMode.h"

PongGameMode::PongGameMode()
{

}

PongGameMode::~PongGameMode()
{

}

bool PongGameMode::InitGameMode()
{
	fpsCounter = new FPSCounter();
	ball = new Ball(WIN_WIDTH / 2, WIN_HEIGHT / 2);
	scoreCounter = new ScoreCounter();

	player1 = new Player(1, WIN_WIDTH - 70.0f, WIN_HEIGHT / 2 - 50.0f);
	player2 = new Player(2, 50.0f, WIN_HEIGHT / 2 - 50.0f);

	return true;
}

void PongGameMode::UpdateGameMode()
{
	ball->Update();
	fpsCounter->Update();
	scoreCounter->Update();

	player1->Update();
	player2->Update();

}

void PongGameMode::Draw()
{
	ball->Draw();
	fpsCounter->Draw();
	scoreCounter->Draw();

	player1->Draw();
	player2->Draw();
}

void PongGameMode::CheckCollision()
{
	if (ball->CheckCollisionWithPlayer(player1) || ball->CheckCollisionWithPlayer(player2)) {
		ball->InvertDirectionX();
	}

	if (ball->CheckCollisionWithLeftWall() || ball->CheckCollisionWithRightWall()) {
		// TODO : Logique pour marquer un point ou réinitialiser la balle
	}

	if (ball->CheckCollisionWithTopOrBottomWall()) {
		ball->InvertDirectionY();
	}
}

void PongGameMode::EndGameMode()
{
	delete ball;
	delete fpsCounter;
	delete scoreCounter;

	delete player1;
	delete player2;
}

