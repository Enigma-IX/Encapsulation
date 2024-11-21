#pragma once
#include "InputManager.h"
#include <SDL_events.h>

class SDLInputManager : public InputManager
{
public:
	SDLInputManager();
	~SDLInputManager();

	void Update() override;

private:
	SDL_Event event;
};

