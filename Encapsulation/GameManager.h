#pragma once

#include <iostream>
#include "framework.h"
#include "config.h"

#include "TimeManager.h"

#include "SDLText.h"
#include "RaylibText.h"
#include "Ball.h"


class GameManager
{
private:
	static GameManager* instance;  // Singleton instance

	CurrentWindow window;
	//Sprite* sprite;
	Text* text;
	Ball* ball;

	GameManager(); // Constructeur privé

	float x = WIN_WIDTH / 2, y = WIN_HEIGHT / 2, dx = 500.0f, dy = 400.0f, radius = 20.0f;

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

