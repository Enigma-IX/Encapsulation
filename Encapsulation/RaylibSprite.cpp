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
        Rectangle sourceRect = { 0, 0, static_cast<float>(texture->width), static_cast<float>(texture->height) };
        Rectangle destRect = { x, y, width, height };
        DrawTexturePro(*texture, sourceRect, destRect, Vector2{ 0, 0 }, 0.0f, WHITE);
    }
}

void RaylibSprite::SetPosition(float x, float y) {
    positionX = x;
    positionY = y;
}

std::pair<float, float> RaylibSprite::GetPosition() const
{
        return { positionX, positionY };
}

void RaylibSprite::SetSize(float width, float height) {
    this->width = width;
    this->height = height;
}

std::pair<float, float> RaylibSprite::GetSize() const {
    return { width, height };
}
