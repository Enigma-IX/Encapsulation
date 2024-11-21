#pragma once
#include "Sprite.h"
#include "Window.h"
#include "Player.h"

class Ball
{
public:
	Ball();
	void Init();
	~Ball();

	void Update();
	bool CheckCollisionWithLeftWall();
	bool CheckCollisionWithRightWall();
	bool CheckCollisionWithTopOrBottomWall();
	void Draw() const;
	bool CheckCollisionWithPlayer(Player* player);
	void InvertDirectionX();
	void InvertDirectionY();

private:
	Sprite* spriteBall;
	float dirX, dirY;
	float radius;
};

