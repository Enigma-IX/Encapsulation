#pragma once

#include <iostream>
#include "framework.h"
#include "config.h"

#include "GameMode.h"
#include "DemoGameMode.h"


class GameManager
{
private:
	static GameManager* instance;  // Singleton instance

	CurrentWindow window;
	GameMode* gameMode;

	GameManager(); // Constructeur privé

public:
	// Singleton instance
	static GameManager& Instance();

	void SelectGameMode(int gameType);
	void InitGame();
	void StartMainLoop();
	void Update();
	void Draw();
	void EndGame();
	void WipeGame();

	CurrentWindow* getWindow();

	~GameManager();
};

