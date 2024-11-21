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

bool GameManager::SetWindowType(int argc, char* argv[])
{
	bool useRuntime = false;
	#if defined(USE_SDL)
		std::cout << "Compiled with SDL by default." << std::endl;
		window = new SDLWindow;
		title = "SDL (compilation)";
	#elif defined(USE_RAYLIB)
		std::cout << "Compiled with Raylib by default." << std::endl;
		window = new RaylibWindow;
		title = "Raylib (compilation)";
	#else
		useRuntime = true;
	#endif

	// Override la compilation avec un argument runtime
	if (argc > 1) {
		std::string windowType = argv[1];
		if (windowType == "-SDL") {
			std::cout << "Runtime override: Using SDL" << std::endl;
			delete window;
			window = new SDLWindow;
			title = "SDL (runtime)";
		}
		else if (windowType == "-Raylib") {
			std::cout << "Runtime override: Using Raylib" << std::endl;
			delete window;
			window = new RaylibWindow;
			title = "Raylib (runtime)";
		}
		else {
			std::cerr << "Invalid argument(s). Valid options are: -SDL or -Raylib" << std::endl;
			return false;
		}
	}
	else if (useRuntime) {
		window = new RaylibWindow;
		title = "DEFAULT is Raylib (runtime)";
	}
	return true;
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
		gameMode = new PongGameMode();
		break;
	case GameMode::BRICK:
		gameMode = new BrickGameMode();
		break;
	default:
		std::cerr << "Invalid choice, defaulting to Demo Game Mode.\n";
		gameMode = new DemoGameMode();
		break;
	}	
}

bool GameManager::SetGameMode(int argc, char* argv[])
{
	if (argc > 2) {
		std::string gameModeArg = argv[2];
		if (gameModeArg.rfind("-Mode=", 0) == 0) {
			std::string mode = gameModeArg.substr(6); 
			if (mode == "DEMO") {
				SelectGameMode(GameMode::DEMO);
			}
			else if (mode == "PONG") {
				SelectGameMode(GameMode::PONG);
			}
			else if (mode == "BRICK") {
				SelectGameMode(GameMode::BRICK);
			}
			else {
				std::cerr << "Invalid game mode. Valid options are: DEMO, PONG, or BRICK." << std::endl;
				return false;
			}
			return true;
		}
		else {
			std::cerr << "Invalid argument for game mode. Use -Mode=<ModeName>." << std::endl;
			return false;
		}
	}

	// Mode de jeu par d�faut si aucun argument n'est fourni
	SelectGameMode(GameMode::DEMO);
	return true;
}

void GameManager::InitGame(int argc, char* argv[])
{	
	if (!SetWindowType(argc, argv))
		return;
	
	if (!SetGameMode(argc, argv))
		return;

	if (!window->initialize() || !window->createWindow(WIN_WIDTH, WIN_HEIGHT, title)) {
		std::cerr << "Failed to initialize window!" << std::endl;
		return;
	}
	
	inputManager = window->createInputManager();
 
	//SelectGameMode(GameMode::BRICK);
	gameMode->InitGameMode();
}

void GameManager::StartMainLoop()
{
	while (window->isOpen()) 
	{
		Update();
	}
}

void GameManager::Update()
{
	Draw();

	TimeManager::Instance().Update();
	
	gameMode->UpdateGameMode();

	inputManager->Update();	
}

void GameManager::Draw()
{

	window->clear();
	
	CheckCollisions();
	gameMode->Draw();
	
	window->display();
}

void GameManager::CheckCollisions() 
{
	gameMode->CheckCollision();
}


void GameManager::EndGame()
{
	// Logique fin de partie
	gameMode->EndGameMode();
}

void GameManager::WipeGame()
{

	gameMode->WipeGameMode();
	window->close();
}


Window* GameManager::getWindow()
{
	return window;
}

InputManager* GameManager::getInputManager()
{
	return inputManager;
}

GameManager::~GameManager()
{
	WipeGame();
}
