#include "DemoGameMode.h"

DemoGameMode::DemoGameMode()
{

}

DemoGameMode::~DemoGameMode()
{

}

bool DemoGameMode::InitGameMode()
{
	fpsCounter = new FPSCounter();
	scoreCounter = new ScoreCounter(WIN_WIDTH / 4, WIN_HEIGHT);
	ball = new Ball(WIN_WIDTH / 2, WIN_HEIGHT / 2);
  
	return true;
}

void DemoGameMode::UpdateGameMode()
{
	ball->Update();
	fpsCounter->Update();
	scoreCounter->Update();
}

void DemoGameMode::Draw()
{
	ball->Draw();
	fpsCounter->Draw();
	scoreCounter->Draw();
}

void DemoGameMode::CheckCollision()
{
	if (ball->CheckCollisionWithLeftWall() || ball->CheckCollisionWithRightWall()) {
		ball->InvertDirectionX();
	}

	if (ball->CheckCollisionWithTopWall() || ball->CheckCollisionWithBottomWall()) {
		ball->InvertDirectionY();
	}
}

void DemoGameMode::EndGameMode()
{
	//TO DO: Logique de fin de partie
}

void DemoGameMode::WipeGameMode()
{
	delete ball;
	delete fpsCounter;
	delete scoreCounter;
}
