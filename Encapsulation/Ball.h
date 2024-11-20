#pragma once
#include "Sprite.h"
#include "Window.h"
class Ball
{
public:
	Ball(Sprite* sprite, float radius, float dx, float dy);
	~Ball();

	void Update(float deltaTime, float windowWidth, float windowHeight);
	void Draw(Window& window) const;
	void Destroy();
private:
	Sprite* spriteBall;
	float dirX, dirY;
	float radius;
};

