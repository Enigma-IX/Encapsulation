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
	ball = new Ball();
	scoreCounter = new ScoreCounter(WIN_WIDTH / 4, WIN_HEIGHT);
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

}

void DemoGameMode::EndGameMode()
{
	//TO DO: Logique de cleanup avant de Wipe

	WipeGameMode();
}

void DemoGameMode::WipeGameMode()
{
	delete ball;
	delete fpsCounter;
	delete scoreCounter;
}
