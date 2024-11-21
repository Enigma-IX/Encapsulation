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
	ball = new Ball(WIN_WIDTH / 2, WIN_HEIGHT / 2);
	scoreCounter = new ScoreCounter();
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

	if (ball->CheckCollisionWithTopOrBottomWall()) {
		ball->InvertDirectionY();
	}
}

void DemoGameMode::EndGameMode()
{
	delete ball;
	delete fpsCounter;
	delete scoreCounter;
}
