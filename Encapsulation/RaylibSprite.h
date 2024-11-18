#pragma once

#include "Sprite.h"

class RaylibSprite : public Sprite
{
public:
	RaylibSprite();
	~RaylibSprite();

	void loadSprite() override;
	void getLoadedSprite() override;
};

