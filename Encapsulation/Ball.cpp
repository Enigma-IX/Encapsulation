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

    if (x - radius /2 < 0 || x + radius * 2 > windowWidth) vitesseX = -vitesseX;
    if (y - radius /2 < 0 || y + radius * 2 > windowHeight) vitesseY = -vitesseY;

    spriteBall->SetPosition(x, y);

    std::cout << "Position: (" << x << ", " << y << "), DeltaTime: " << deltaTime << std::endl;
}

void Ball::Draw(Window& window) const
{
    window.drawSprite(*spriteBall);
}
