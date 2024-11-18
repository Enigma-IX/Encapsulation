#pragma once
#include "Sprite.h"
class SDLSprite : public Sprite
{
public:
	SDLSprite();
	~SDLSprite();

	void loadSprite() override;
	void getLoadedSprite() override;
};

