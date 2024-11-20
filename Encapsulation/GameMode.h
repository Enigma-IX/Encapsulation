#pragma once

#include "framework.h"
#include "config.h"

#include "TimeManager.h"

#include "SDLText.h"
#include "RaylibText.h"
#include "Ball.h"

class GameMode
{

private:	

public:
	GameMode() = default;
	~GameMode() = default;

	virtual bool InitGameMode() = 0;
	virtual void UpdateGameMode() = 0;
	virtual void Draw() = 0;
	virtual void EndGameMode() = 0;
};
