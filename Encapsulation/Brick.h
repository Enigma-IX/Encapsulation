#pragma once
#include "Sprite.h"

class Brick {
public:
    Brick(float x, float y, float width, float height);
    ~Brick();

    void Init(float x, float y, float width, float height);
    void Draw() const;
    bool CheckCollisionWithBall(Sprite* ball);
    bool IsDestroyed() const;

    void Destroy();

private:
    Sprite* spriteBrick;
    bool destroyed;
};