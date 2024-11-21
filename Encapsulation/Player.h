#pragma once
#include "Sprite.h"

class Player {
public:
    Player(int userId, float startX, float startY); // Position initiale minimale
    ~Player();

    void Init();
    void Update();
    void Draw() const;

    // Accesseurs pour obtenir les dimensions et la position
    float GetX() const;
    float GetY() const;
    float GetWidth() const;
    float GetHeight() const;

private:
    Sprite* spritePlayer;
    int userId;               // Identifiant du joueur
    float speed;              // Vitesse de déplacement

    static constexpr float DEFAULT_WIDTH = 20.0f;  // Largeur par défaut
    static constexpr float DEFAULT_HEIGHT = 100.0f; // Hauteur par défaut
    static constexpr float DEFAULT_SPEED = 300.0f;  // Vitesse par défaut
};