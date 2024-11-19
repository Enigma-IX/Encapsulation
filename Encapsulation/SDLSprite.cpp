#include "SDLSprite.h"
#include <SDL_image.h>
#include <iostream>

SDLSprite::SDLSprite(SDL_Renderer* renderer) : texture(nullptr), renderer(renderer), positionX(0), positionY(0) {}

SDLSprite::~SDLSprite() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

bool SDLSprite::LoadImage(const std::string& filepath) {
    SDL_Surface* surface = IMG_Load(filepath.c_str());
    if (!surface) {
        std::cerr << "Failed to load image: " << filepath << std::endl;
        return false;
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture) {
        std::cerr << "Failed to create texture from surface!" << std::endl;
        return false;
    }

    return true;
}

void* SDLSprite::GetData() const {
    return texture;
}

void SDLSprite::Draw(float x, float y) const {
    if (!texture) {
        return;
    }

    SDL_Rect rect = { static_cast<int>(x), static_cast<int>(y), 50, 50 };
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
}

void SDLSprite::SetPosition(float x, float y) {
    positionX = x;
    positionY = y;
}

std::pair<float, float> SDLSprite::GetPosition() const {
    return { positionX, positionY };
}
