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

	/*text = window.createText();
	if (!text->loadFont("Montserrat-Regular.ttf", 24))
	{
		delete text;
		return;
	}
	text->setPosition(100, 100);
	text->loadText("Bienvenue");*/

	Text* fpsText = window.createText();
	if (fpsText->loadFont("Montserrat-Regular.ttf", 18))
	{
		fpsText->setPosition(100, 100);
		std::string fpsString = "FPS : 0";
		fpsText->loadText(fpsString);
		fpsCounter = new FPSCounter(fpsText);
	}

	Sprite* sprite = window.createSprite();
	if (!sprite->LoadImage("ball.png")) {
		std::cerr << "Failed to load sprite image!" << std::endl;
		delete sprite;
		return;
	}

	ball = new Ball(sprite, 20.0f, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	sprite->SetPosition(WIN_WIDTH / 2, WIN_HEIGHT / 2);
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

	ball->Update(TimeManager::Instance().GetDeltaTime(), WIN_WIDTH, WIN_HEIGHT);
	fpsCounter->Update(TimeManager::Instance().GetDeltaTime());

	Draw();
}

void GameManager::Draw()
{
	window.clear();

	ball->Draw(window);
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

GameManager::~GameManager()
{
	WipeGame();
}
