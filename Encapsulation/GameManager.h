#pragma once

#include <iostream>
#include "framework.h"

#include "InputManager.h"
#include "GameMode.h"
#include "DemoGameMode.h"


class GameManager
{
private:
	static GameManager* instance;  // Singleton instance

	InputManager* inputManager;
	Window* window;
	GameMode* gameMode;

	GameManager(); // Constructeur priv�

	const char* title;

public:
	// Singleton instance
	static GameManager& Instance();

	bool SetWindowType(int argc, char* argv[]);

	void SelectGameMode(int gameType);
	void InitGame(int argc, char* argv[]);
	void StartMainLoop();
	void Update();
	void CheckCollisions();
	void Draw();
	void EndGame();
	void WipeGame();

	InputManager* getInputManager();
	Window* getWindow();

	~GameManager();
};

