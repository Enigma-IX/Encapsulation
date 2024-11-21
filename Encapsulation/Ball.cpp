#include "Ball.h"
#include "iostream"
#include "Sprite.h"
#include "GameManager.h"

Ball::Ball() : radius(20.0f), dirX(WIN_WIDTH / 2), dirY(WIN_HEIGHT / 2) {
    
    spriteBall = GameManager::Instance().getWindow()->createSprite();
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

    spriteBall->SetPosition(x, y);
}

bool Ball::CheckCollisionWithLeftWall()
{
    std::pair<float, float> position = spriteBall->GetPosition();
    float x = position.first;
    return (x <= 0);
}

bool Ball::CheckCollisionWithRightWall()
{
    std::pair<float, float> position = spriteBall->GetPosition();
    float x = position.first + spriteBall->GetSize().first;
    return (x >= WIN_WIDTH);
}


bool Ball::CheckCollisionWithTopOrBottomWall()
{
    std::pair<float, float> position = spriteBall->GetPosition();
    float y = position.second;

    return (y <= 0 || y + spriteBall->GetSize().second >= WIN_HEIGHT);
}

bool Ball::CheckCollisionWithPlayer(Player* player) {
    std::pair<float, float> ballPosition = spriteBall->GetPosition();
    std::pair<float, float> playerPosition(player->GetX(), player->GetY());

    float ballX = ballPosition.first;
    float ballY = ballPosition.second;
    float ballDiameter = radius * 2;

    float playerX = playerPosition.first;
    float playerY = playerPosition.second;

    // Vérifie si la balle est dans la zone horizontale et verticale du joueur
    bool collisionX = ballX + ballDiameter > playerX && ballX < playerX + player->GetWidth();
    bool collisionY = ballY + ballDiameter > playerY && ballY < playerY + player->GetHeight();

    return collisionX && collisionY;
}

void Ball::InvertDirectionX() {
    dirX = -dirX;
}

void Ball::InvertDirectionY()
{
    dirY = -dirY;
}

void Ball::Draw() const
{
    GameManager::Instance().getWindow()->drawSprite(*spriteBall);
}