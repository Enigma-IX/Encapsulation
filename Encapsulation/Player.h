#pragma once
#include "Sprite.h"

class Player {
public:
    Player(int userId, float startX, float startY); // Position initiale minimale
    ~Player();

    void Init(float startX, float startY);
    void Update();
    void Draw() const;

    // Accesseurs pour obtenir les dimensions et la position
    float GetX() const;
    float GetY() const;
    float GetWidth() const;
    float GetHeight() const;

private:
    Sprite* spritePlayer;
    int userId;      
    float speed;  

    static constexpr float DEFAULT_WIDTH = 20.0f;
    static constexpr float DEFAULT_HEIGHT = 105.0f;
    static constexpr float DEFAULT_SPEED = 600.0f;
};