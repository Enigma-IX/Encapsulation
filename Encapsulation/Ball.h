#pragma once
#include "Sprite.h"
#include "Window.h"
class Ball
{
public:
	Ball();
	void Init();
	~Ball();

	void Update();
	void Draw() const;

private:
	Sprite* spriteBall;
	float dirX, dirY;
	float radius;
};

