#include "Ball.h"
#include "iostream"
#include "Sprite.h"
#include "GameManager.h"

Ball::Ball() : radius(20.0f), dirX(WIN_WIDTH / 2), dirY(WIN_HEIGHT / 2) {
    
    spriteBall = GameManager::Instance().getWindow().createSprite();
    Init();
}

void Ball::Init()
{
    if (!spriteBall->LoadImage("ball.png")) {
        std::cerr << "Failed to load sprite image!" << std::endl;
        delete spriteBall;
        return;
    }
    spriteBall->SetSize(radius * 2, radius * 2);
    spriteBall->SetPosition(dirX, dirY);
}

Ball::~Ball()
{
    delete spriteBall;
}

void Ball::Update()
{
    std::pair<float, float> position = spriteBall->GetPosition();
    float x = position.first;
    float y = position.second;

    x += dirX * TimeManager::Instance().GetDeltaTime();
    y += dirY * TimeManager::Instance().GetDeltaTime();

    if (x < 0 || x + spriteBall->GetSize().first > WIN_WIDTH) dirX = -dirX;
    if (y < 0 || y + spriteBall->GetSize().second > WIN_HEIGHT) dirY = -dirY;

    spriteBall->SetPosition(x, y);
}

void Ball::Draw() const
{
    GameManager::Instance().getWindow().drawSprite(*spriteBall);
}