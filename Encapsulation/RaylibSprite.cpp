#include "RaylibSprite.h"
#include <iostream>

RaylibSprite::RaylibSprite() : positionX(0), positionY(0), texture(nullptr) {}

RaylibSprite::~RaylibSprite() {
    if (texture) {
        UnloadTexture(*texture);
        delete texture;
    }
}

bool RaylibSprite::LoadImage(const std::string& filepath) {
    texture = new Texture2D(LoadTexture(filepath.c_str()));
    if (texture->id == 0) {
        delete texture;
        texture = nullptr;
        std::cerr << "Failed to load texture: " << filepath << std::endl;
        return false;
    }
    return true;
}

void* RaylibSprite::GetData() const {
    return texture;
}

void RaylibSprite::Draw(float x, float y) const {
    if (texture) {
        DrawTexture(*texture, static_cast<int>(x), static_cast<int>(y), WHITE);
    }
}

void RaylibSprite::SetPosition(float x, float y) {
    positionX = x;
    positionY = y;
}

std::pair<float, float> RaylibSprite::GetPosition() const {
    return { positionX, positionY };
}
