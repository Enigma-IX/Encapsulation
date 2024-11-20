#include "GameManager.h"

GameManager* GameManager::instance = nullptr;


GameManager::GameManager()
{

}

GameManager& GameManager::Instance() {
	if (!instance) {
		instance = new GameManager();
	}
	return *instance;
}

void GameManager::SelectGameMode(int gameType)
{
	if (gameMode) {
		delete gameMode;
		gameMode = nullptr;
	}

	switch (gameType) {
	case GameMode::DEMO:
		gameMode = new DemoGameMode();
		break;
	case GameMode::PONG:
		gameMode = new DemoGameMode();
		break;
	case GameMode::BRICK:
		gameMode = new DemoGameMode();
		break;
	default:
		std::cerr << "Invalid choice, defaulting to Demo Game Mode.\n";
		gameMode = new DemoGameMode();
		break;
	}	
}

void GameManager::InitGame()
{	
	if (!window.initialize() || !window.createWindow(WIN_WIDTH, WIN_HEIGHT, TITLE)) {
		std::cerr << "Failed to initialize window!" << std::endl;
		return;
	}
	
	SelectGameMode(GameMode::DEMO);
	gameMode->InitGameMode();
}

void GameManager::StartMainLoop()
{
	SDL_Event event; // Input Manager
	while (window.isOpen()) {

		// Input Manager
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT)
		{
			WipeGame();
			return;
		}

		Update();
	}
}

void GameManager::Update()
{
	TimeManager::Instance().Update();

	gameMode->UpdateGameMode();

	Draw();
}

void GameManager::Draw()
{
	window.clear();

	gameMode->Draw();
	
	window.display();
}

void GameManager::EndGame()
{
	// Logique fin de partie
	gameMode->EndGameMode();
}

void GameManager::WipeGame()
{
	EndGame();
	window.close();
}


CurrentWindow* GameManager::getWindow()
{
	return &window;
}

GameManager::~GameManager()
{
	WipeGame();
}
