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

	Text* fpsText = window.createText();
	if (fpsText->loadFont("Montserrat-Regular.ttf", 18))
	{
		fpsText->setPosition(100, 100);
		std::string fpsString = "FPS : 0";
		fpsText->loadText(fpsString);
		fpsCounter = new FPSCounter(fpsText);
	}

	ball = new Ball();
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

	ball->Update();
	fpsCounter->Update(TimeManager::Instance().GetDeltaTime());

	Draw();
}

void GameManager::Draw()
{
	window.clear();

	ball->Draw();
	fpsCounter->Draw(window);
	
	window.display();
}

void GameManager::EndGame()
{
	// Logique fin de partie
}

void GameManager::WipeGame()
{
	delete ball;
	delete fpsCounter;
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
