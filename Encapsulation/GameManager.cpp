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

	text = window.createText();
	if (!text->loadFont("Montserrat-Regular.ttf", 24))
	{
		delete text;
		return;
	}
	text->setPosition(100, 100);
	text->loadText("Bienvenue");

	sprite = window.createSprite();
	if (!sprite->LoadImage("ball.png")) {
		std::cerr << "Failed to load sprite image!" << std::endl;
		delete sprite;
		return;
	}
	sprite->SetPosition(x, y);
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

	// TO DO: Gerer ca avec dans les classes sprite  (Logique de rebonsissement)
	x += dx * TimeManager::Instance().GetDeltaTime();
	y += dy * TimeManager::Instance().GetDeltaTime();

	/*
	if (x < 0 || x > WIN_WIDTH - 50) dx = -dx;
	if (y < 0 || y > WIN_HEIGHT - 50) dy = -dy;*/
	if (x - radius < 0 || x + radius > WIN_WIDTH) dx = -dx; // Radius a changer
	if (y - radius < 0 || y + radius > WIN_HEIGHT) dy = -dy; // Radius a changer

	sprite->SetPosition(x, y);

	window.clear();

	window.drawText(*text);
	window.drawSprite(*sprite);

	window.display();
}

void GameManager::EndGame()
{
	// Logique fin de partie
}

void GameManager::WipeGame()
{
	delete sprite;
	delete text;
	window.close();
}

GameManager::~GameManager()
{
	WipeGame();
}
