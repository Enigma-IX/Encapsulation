#pragma once

#include <iostream>
#include "framework.h"
#include "config.h"

#include "TimeManager.h"

#include "SDLText.h"
#include "RaylibText.h"
#include "Ball.h"
#include "FPSCounter.h"
#include "InputManager.h"
#include "Player.h"

//#include "GameMode.h"
//#include "DemoGameMode.h"


class GameManager
{
private:
	static GameManager* instance;  // Singleton instance

	CurrentWindow window;
	Ball* ball;
	FPSCounter* fpsCounter;
	InputManager* inputManager;

	Player* player1; // Joueur 1
	Player* player2; // Joueur 2

	GameManager(); // Constructeur privé

public:
	// Singleton instance
	static GameManager& Instance();

	void SelectGameMode();
	void InitGame();
	void StartMainLoop();
	void Update();
	void Draw();
	void EndGame();
	void WipeGame();

	CurrentWindow* getWindow();
	InputManager* getInputManager();

	~GameManager();
};

