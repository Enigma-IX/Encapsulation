#include "Ball.h"
#include "iostream"

Ball::Ball(Sprite* sprite, float radius, float dx, float dy) {
    spriteBall = sprite;
    dirX = dx;
    dirY = dy;
    this->radius = radius;

    spriteBall->SetSize(radius * 2, radius * 2);
}

Ball::~Ball()
{
    delete spriteBall;
}

void Ball::Update(float deltaTime, float windowWidth, float windowHeight)
{
    std::pair<float, float> position = spriteBall->GetPosition();
    float x = position.first;
    float y = position.second;

    x += dirX * deltaTime;
    y += dirY * deltaTime;

    if (x < 0 || x + spriteBall->GetSize().first > windowWidth) dirX = -dirX;
    if (y < 0 || y + spriteBall->GetSize().second > windowHeight) dirY = -dirY;

    spriteBall->SetPosition(x, y);
}

void Ball::Draw(Window& window) const
{
    window.drawSprite(*spriteBall);
}