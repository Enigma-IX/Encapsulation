#include "Player.h"
#include "GameManager.h"
#include "InputManager.h"
#include <iostream>

Player::Player(int userId, float startX, float startY, bool isVertical)
    : userId(userId), speed(DEFAULT_SPEED) {
    spritePlayer = GameManager::Instance().getWindow()->createSprite();
    this->isVertical = isVertical;
    
    Init(startX, startY);
}

void Player::Init(float startX, float startY) {
    if (isVertical)
    {
        if (!spritePlayer->LoadImage("player.png")) {
            std::cerr << "Failed to load Player image!" << std::endl;
            delete spritePlayer;
            spritePlayer = nullptr;
        }
    }
    else if (!isVertical)
    {
        if (!spritePlayer->LoadImage("player_hor.png")) {
            std::cerr << "Failed to load Player image!" << std::endl;
            delete spritePlayer;
            spritePlayer = nullptr;
        }
    }
    if (!spritePlayer->LoadImage("player.png")) {
        std::cerr << "Failed to load Player image!" << std::endl;
        delete spritePlayer;
        spritePlayer = nullptr;
    }
    spritePlayer->SetSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
    spritePlayer->SetPosition(startX, startY);
}

Player::~Player() {
    delete spritePlayer;
}

void Player::Update() {
    std::pair<float, float> position = spritePlayer->GetPosition();
    float x = position.first;
    float y = position.second;

    InputManager* inputManager = GameManager::Instance().getInputManager();
    float deltaTime = TimeManager::Instance().GetDeltaTime();

    if (isVertical)
    {
        // Déplacement en fonction des touches
        if (inputManager->IsKeyPressed(userId, 'u')) {
            y -= speed * deltaTime;
        }
        if (inputManager->IsKeyPressed(userId, 'd')) {
            y += speed * deltaTime;
        }
        if (inputManager->IsKeyPressed(userId, 'z')) {
            y -= speed * deltaTime;
        }
        if (inputManager->IsKeyPressed(userId, 's')) {
            y += speed * deltaTime;
        }
    }
    else if (!isVertical)
    {
        if (inputManager->IsKeyPressed(userId, 'l')) {
            y -= speed * deltaTime;
        }
        if (inputManager->IsKeyPressed(userId, 'r')) {
            y += speed * deltaTime;
        }
    }
    

    // Limitation des déplacements dans la fenêtre
    if (y < 0) y = 0;
    if (y + spritePlayer->GetSize().second > WIN_HEIGHT) {
        y = WIN_HEIGHT - spritePlayer->GetSize().second;
    }

    spritePlayer->SetPosition(x, y);
}

void Player::Draw() const {
    GameManager::Instance().getWindow()->drawSprite(*spritePlayer);
}

// Accesseurs
float Player::GetX() const {
    return spritePlayer->GetPosition().first;
}

float Player::GetY() const {
    return spritePlayer->GetPosition().second;
}

float Player::GetWidth() const {
    return spritePlayer->GetSize().first;
}

float Player::GetHeight() const {
    return spritePlayer->GetSize().second;
}
