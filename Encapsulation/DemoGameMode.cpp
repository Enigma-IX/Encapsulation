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
	return true;
}

void DemoGameMode::UpdateGameMode()
{
	ball->Update();
	fpsCounter->Update();
}

void DemoGameMode::Draw()
{
	ball->Draw();
	fpsCounter->Draw();
}

void DemoGameMode::EndGameMode()
{
	delete ball;
	delete fpsCounter;
}
