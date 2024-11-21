#include "Ball.h"
#include "iostream"
#include "Sprite.h"
#include "GameManager.h"

#include <random>

Ball::Ball(int posX, int posY) : radius(15.0f), dirX(0), dirY(0), speed(600){
    
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

    startPosX = posX;
    startPosY = posY;

    spriteBall->SetSize(radius * 2, radius * 2);
    spriteBall->SetPosition(startPosX, startPosY);
}

Ball::~Ball()
{
    delete spriteBall;
}

void Ball::Update()
{
	if (stopTimer > 0) {
		stopTimer -= TimeManager::Instance().GetDeltaTime();
		if (stopTimer <= 0) {
			SetRandomDirection(); // Redémarre la balle après l'arrêt
		}
		return;
	}

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

bool Ball::CheckCollisionWithTopWall()
{
    std::pair<float, float> position = spriteBall->GetPosition();
    float y = position.second;

    return (y <= 0); // Collision avec le haut
}

bool Ball::CheckCollisionWithBottomWall()
{
    std::pair<float, float> position = spriteBall->GetPosition();
    float y = position.second + spriteBall->GetSize().second;

    return (y >= WIN_HEIGHT); // Collision avec le bas
}

bool Ball::CheckCollisionWithPlayer(Player* player) {
	std::pair<float, float> ballPosition = spriteBall->GetPosition();
	float ballX = ballPosition.first;
	float ballY = ballPosition.second;
	float ballDiameter = radius * 2;

	std::pair<float, float> playerPosition(player->GetX(), player->GetY());
	float playerX = playerPosition.first;
	float playerY = playerPosition.second;
	float playerWidth = player->GetWidth();
	float playerHeight = player->GetHeight();

	bool collisionX = ballX + ballDiameter > playerX && ballX < playerX + playerWidth;
	bool collisionY = ballY + ballDiameter > playerY && ballY < playerY + playerHeight;

	if (collisionX && collisionY) {
		if (playerWidth > playerHeight) {
			if (ballY + ballDiameter / 2 < playerY + playerHeight / 2) {
				spriteBall->SetPosition(ballX, playerY - ballDiameter);
			}
			else {
				spriteBall->SetPosition(ballX, playerY + playerHeight);
			}
		}
		else {
			if (ballX + ballDiameter / 2 < playerX + playerWidth / 2) {
				spriteBall->SetPosition(playerX - ballDiameter, ballY);
			}
			else {
				spriteBall->SetPosition(playerX + playerWidth, ballY);
			}
		}
		return true;
	}

	return false;
}




void Ball::SetRandomDirection() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> angleDistr(0.0, 2.0 * M_PI);

    // Nombre maximum de tentatives
	const int maxAttempts = 100; 
	int attempts = 0;
	float angle;

	do {
		angle = angleDistr(gen);
		attempts++;
	} while ((std::fabs(std::cos(angle)) > 0.9 || std::fabs(std::sin(angle)) > 0.9) && attempts < maxAttempts); // Evite les angles de - de 10°

	if (attempts == maxAttempts) {
		angle = M_PI / 4.0;
	}

	dirX = std::cos(angle) * speed;
	dirY = std::sin(angle) * speed;
}

void Ball::InvertDirectionX() {
    dirX = -dirX;
}

void Ball::InvertDirectionY()
{
    dirY = -dirY;
}

void Ball::Reset()
{
	spriteBall->SetPosition(startPosX, startPosY);
	Stop();
	stopTimer = stopDuration;
    SetRandomDirection();
}

void Ball::Stop()
{
	dirY = 0;
	dirX = 0;
	spriteBall->SetPosition(startPosX, startPosY);
}

void Ball::Draw() const
{
    GameManager::Instance().getWindow()->drawSprite(*spriteBall);
}