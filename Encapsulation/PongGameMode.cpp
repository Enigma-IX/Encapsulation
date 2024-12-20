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
  
	timer = new GameTimer(WIN_WIDTH / 2, 0, 60);

	scoreCounterP1 = new ScoreCounter(WIN_WIDTH / 8, WIN_HEIGHT - 50);
	scoreCounterP2 = new ScoreCounter(7 * WIN_WIDTH / 8, WIN_HEIGHT - 50);

	ball = new Ball(WIN_WIDTH / 2, WIN_HEIGHT / 2);

	player1 = new Player(1, WIN_WIDTH - 70.0f, WIN_HEIGHT / 2 - 50.0f, true);
	player2 = new Player(2, 50.0f, WIN_HEIGHT / 2 - 50.0f, true);

	winner = new Winner(WIN_WIDTH / 2, 2 * WIN_HEIGHT / 3);

	return true;

}

void PongGameMode::UpdateGameMode()
{
	ball->Update();
	fpsCounter->Update();
	timer->Update();

	scoreCounterP1->Update();
	scoreCounterP2->Update();

	player1->Update();
	player2->Update();

	winner->Update();

}

void PongGameMode::Draw()
{
	ball->Draw();
	fpsCounter->Draw();
	timer->Draw();

	scoreCounterP1->Draw();
	scoreCounterP2->Draw();

	player1->Draw();
	player2->Draw();


	winner->Draw();
}

void PongGameMode::CheckCollision()
{
	if (ball->CheckCollisionWithPlayer(player1) || ball->CheckCollisionWithPlayer(player2)) {
		ball->InvertDirectionX();
	}

	if (ball->CheckCollisionWithRightWall()) {
		ball->Reset();
		scoreCounterP1->AddToScore(1);
	}

	if (ball->CheckCollisionWithLeftWall()) {
		ball->Reset();
		scoreCounterP2->AddToScore(1);
	}	

	if (ball->CheckCollisionWithTopWall() || ball->CheckCollisionWithBottomWall()) {
		ball->InvertDirectionY();
	}

}

void PongGameMode::EndGameMode()
{
	ball->Stop();
	if (scoreCounterP1->GetScore() > scoreCounterP2->GetScore())
		winner->SetWinner("Player 1");
	else if (scoreCounterP1->GetScore() < scoreCounterP2->GetScore())
		winner->SetWinner("Player 2");
	else
		winner->SetWinner("Nobody");
	return;
}

void PongGameMode::WipeGameMode()
{
	delete ball;
	delete fpsCounter;
	delete timer;

	delete scoreCounterP1;
	delete scoreCounterP2;

	delete player1;
	delete player2;

	delete winner;
}

