#include "Brick.h"
#include "GameManager.h"
#include <iostream>

Brick::Brick(float x, float y, float width, float height) : destroyed(false) {
    spriteBrick = GameManager::Instance().getWindow()->createSprite();
    Init(x, y, width, height);
}

void Brick::Init(float x, float y, float width, float height) {
    if (!spriteBrick->LoadImage("brick.png")) {
        std::cerr << "Failed to load Brick image!" << std::endl;
        delete spriteBrick;
        spriteBrick = nullptr;
    }
    spriteBrick->SetPosition(x, y);
    spriteBrick->SetSize(width, height);
}

Brick::~Brick() {
    delete spriteBrick;
}

void Brick::Draw() const {
    if (!destroyed) {
        GameManager::Instance().getWindow()->drawSprite(*spriteBrick);
    }
}

bool Brick::CheckCollisionWithBall(Sprite* ball) {
    if (destroyed) return false;

    auto [brickX, brickY] = spriteBrick->GetPosition();
    auto [brickWidth, brickHeight] = spriteBrick->GetSize();

    auto [ballX, ballY] = ball->GetPosition();
    float ballRadius = ball->GetSize().first / 2;

    // Collision logic
    bool collisionX = ballX + ballRadius > brickX && ballX - ballRadius < brickX + brickWidth;
    bool collisionY = ballY + ballRadius > brickY && ballY - ballRadius < brickY + brickHeight;

    return collisionX && collisionY;
}

void Brick::Destroy() {
    destroyed = true;
}

bool Brick::IsDestroyed() const {
    return destroyed;
}
