#include "Ball.h"
#include "iostream"

Ball::Ball(Sprite* sprite, float radius, float dx, float dy) {
    spriteBall = sprite;
    vitesseX = dx;
    vitesseY = dy;
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

    x += vitesseX * deltaTime;
    y += vitesseY * deltaTime;

    if (x < 0 || x + spriteBall->GetSize().first > windowWidth) vitesseX = -vitesseX;
    if (y < 0 || y + spriteBall->GetSize().second > windowHeight) vitesseY = -vitesseY;

    spriteBall->SetPosition(x, y);

    std::cout << "Position: (" << x << ", " << y << "), DeltaTime: " << deltaTime << std::endl;
}

void Ball::Draw(Window& window) const
{
    window.drawSprite(*spriteBall);
}
