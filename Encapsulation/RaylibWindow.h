#pragma once

// Classe pour render avec Raylib

#include "Window.h"
#include "raylib.h"
#include <string>
#include "InputManager.h"

class RaylibWindow : public Window {
private:
    bool open;

public:
    RaylibWindow();
    ~RaylibWindow();

    bool initialize() override;
    bool createWindow(int width, int height, const char* title) override;
    bool isOpen() override;
    void clear() override;
    void display() override;
    void close() override;

    void drawText(const Text& text) override;
    Text* createText() override;
  
    void drawSprite(const Sprite& sprite) override;
    Sprite* createSprite() override;

    InputManager* createInputManager() override;
};