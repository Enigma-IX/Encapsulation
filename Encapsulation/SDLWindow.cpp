#include "SDLWindow.h"
#include "SDLSprite.h"
#include <iostream>

SDLWindow::SDLWindow() : window(nullptr), renderer(nullptr), open(false) {}

SDLWindow::~SDLWindow() {
    close();
}

bool SDLWindow::initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL Initialization Failed!" << std::endl;
        return false;
    }
    return true;
}

bool SDLWindow::createWindow(int width, int height, const char* title) {
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!window) return false;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) return false;

    open = true;
    return true;
}

bool SDLWindow::isOpen() {
    return open;
}

void SDLWindow::clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void SDLWindow::display() {
    SDL_RenderPresent(renderer);
}

void SDLWindow::close() {
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    SDL_Quit();
    open = false;
}

void SDLWindow::drawSprite(const Sprite& sprite) {
    // Récupération de la position du sprite
    std::pair<float, float> position = sprite.GetPosition();

    // Appel à la méthode Draw de l'implémentation spécifique (SDLSprite)
    sprite.Draw(position.first, position.second);
}

Sprite* SDLWindow::createSprite() {
    return new SDLSprite(renderer);
}
