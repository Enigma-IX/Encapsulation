#include "SDLWindow.h"

#include "SDLText.h"

SDLWindow::SDLWindow() : window(nullptr), renderer(nullptr), open(false) {}

SDLWindow::~SDLWindow() {
    close();
}

bool SDLWindow::initialize() 
{
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

void SDLWindow::drawCircle(float x, float y, float radius) {
    // TO DO: gerer ca dans Sprite
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);

    for (float w = 0; w < radius * 2; w++) {
        for (float h = 0; h < radius * 2; h++) {
            float dx = radius - w; 
            float dy = radius - h;
            if ((dx * dx + dy * dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
            }
        }
    }
}

void SDLWindow::drawText(const std::string& fontPath, int fontSize)
{
    SDLText text(renderer, fontPath, fontSize);
	text.setPosition(100, 100);
	text.loadText("Bienvenue ! ");
    text.render();
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
