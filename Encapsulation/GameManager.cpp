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

void GameManager::SelectGameMode()
{

}

void GameManager::InitGame()
{	
	if (!window.initialize() || !window.createWindow(WIN_WIDTH, WIN_HEIGHT, TITLE)) {
		std::cerr << "Failed to initialize window!" << std::endl;
		return;
	}
	
	inputManager = window.createInputManager();
	fpsCounter = new FPSCounter();
	ball = new Ball();

	player1 = new Player(1, 50.0f, WIN_HEIGHT / 2 - 50.0f);  
	player2 = new Player(2, WIN_WIDTH - 70.0f, WIN_HEIGHT / 2 - 50.0f);
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

	player1->Update();
	player2->Update();

	ball->Update();
	fpsCounter->Update();

	Draw();
}

void GameManager::Draw()
{
	window.clear();

	ball->Draw();
	fpsCounter->Draw();
	
	window.display();
}

void GameManager::EndGame()
{
	// Logique fin de partie
}

void GameManager::WipeGame()
{
	delete player1;
	delete player2;
	delete ball;
	delete fpsCounter;

	window.close();
}


CurrentWindow* GameManager::getWindow()
{
	return &window;
}

InputManager* GameManager::getInputManager()
{
	return inputManager;
}

GameManager::~GameManager()
{
	WipeGame();
}
