#include <iostream>

#include "GameManager.h"


int main(int argc, char* argv[])
{
	GameManager::Instance().InitGame(argc, argv);
	GameManager::Instance().StartMainLoop();
    return 0;
}
