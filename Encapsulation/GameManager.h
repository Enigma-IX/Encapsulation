#pragma once

#include <iostream>
#include "framework.h"
#include "config.h"

#include "TimeManager.h"

#include "SDLText.h"
#include "RaylibText.h"
#include "Ball.h"
#include "FPSCounter.h"


class GameManager
{
private:
	static GameManager* instance;  // Singleton instance

	CurrentWindow window;
	Ball* ball;
	FPSCounter* fpsCounter;

	GameManager(); // Constructeur privé

public:
	// Singleton instance
	static GameManager& Instance();

	void SelectGameMode();
	void InitGame();
	void StartMainLoop();
	void Update();
	void EndGame();
	void WipeGame();

	~GameManager();
};

