#include "Player.h"
#include "GameManager.h"
#include "InputManager.h"
#include <iostream>

Player::Player(int userId, float startX, float startY)
    : userId(userId), speed(DEFAULT_SPEED) {
    spritePlayer = GameManager::Instance().getWindow()->createSprite();
    spritePlayer->SetPosition(startX, startY);
    spritePlayer->SetSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
    Init();
}

void Player::Init() {
    if (!spritePlayer->LoadImage("player.png")) {
        std::cerr << "Failed to load Player image!" << std::endl;
        delete spritePlayer;
        spritePlayer = nullptr;
    }
}

Player::~Player() {
    delete spritePlayer;
}

void Player::Update() {
    std::pair<float, float> position = spritePlayer->GetPosition();
    float x = position.first;
    float y = position.second;

    InputManager* inputManager = GameManager::Instance().getInputManager();

    // Déplacement basé sur les touches
    if (inputManager->IsKeyPressed(userId, 'u')) { // Haut
        y -= speed * TimeManager::Instance().GetDeltaTime();
    }
    if (inputManager->IsKeyPressed(userId, 'd')) { // Bas
        y += speed * TimeManager::Instance().GetDeltaTime();
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
