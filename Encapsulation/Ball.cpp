#include "Ball.h"
#include "iostream"
#include "Sprite.h"
#include "GameManager.h"

#include <random>

Ball::Ball(int posX, int posY) : radius(20.0f), dirX(0), dirY(0), speed(600){
    
    spriteBall = GameManager::Instance().getWindow()->createSprite();
    Init(posX, posY);
}

void Ball::Init(int posX, int posY)
{
    SetRandomDirection();

    if (!spriteBall->LoadImage("ball.png")) {
        std::cerr << "Failed to load sprite image!" << std::endl;
        delete spriteBall;
        return;
    }
    spriteBall->SetSize(radius * 2, radius * 2);
    spriteBall->SetPosition(posX, posY);
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

void Ball::SetRandomDirection() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> distr(-1.0, 1.0);

	float randomX = distr(gen);
	float randomY = distr(gen);

	float magnitude = std::sqrt(randomX * randomX + randomY * randomY);
	dirX = (randomX / magnitude) * speed;
	dirY = (randomY / magnitude) * speed;
}


void Ball::Draw() const
{
    GameManager::Instance().getWindow()->drawSprite(*spriteBall);
}