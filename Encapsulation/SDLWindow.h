#pragma once

// Classe pour render avec SDL

#include "Window.h"
#include <SDL.h>

#include <string>

class SDLWindow : public Window {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool open;

public:
    SDLWindow();
    ~SDLWindow();

    bool initialize() override;
    bool createWindow(int width, int height, const char* title) override;
    bool isOpen() override;
    void clear() override;
    void drawCircle(float x, float y, float radius) override;
    void drawText(const std::string& fontPath, int fontSize) override;
    void display() override;
    void close() override;

	SDL_Renderer* getRenderer() const { return renderer; }
};