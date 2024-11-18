#pragma once

// Classe m�re abstraite

class Sprite {
public:
    virtual ~Sprite() = default;

    virtual void loadSprite() = 0;
    virtual void getLoadedSprite() = 0;

    float posX;
    float poxY;
};