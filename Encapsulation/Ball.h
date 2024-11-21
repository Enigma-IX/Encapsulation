#pragma once
#include "Sprite.h"
#include "Window.h"
#include "Player.h"

class Ball
{
public:
	Ball(int posX, int posY);
	void Init(int posX, int posY);
	~Ball();

	void Update();
	bool CheckCollisionWithLeftWall();
	bool CheckCollisionWithRightWall();
	bool CheckCollisionWithTopOrBottomWall();
	void Draw() const;
	bool CheckCollisionWithPlayer(Player* player);
	void InvertDirectionX();
	void SetRandomDirection();
	void InvertDirectionY();
	void Reset();
	void Stop();

private:
	Sprite* spriteBall;
	float dirX, dirY;
	float startPosX, startPosY;
	float speed;
	float radius;
};

