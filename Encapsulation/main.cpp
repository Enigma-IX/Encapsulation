#include <iostream>

#include "GameManager.h"


int main() 
{
	GameManager::Instance().InitGame();
	GameManager::Instance().StartMainLoop();
    return 0;
}
