#pragma once

#include <string>

#include "Text.h"
#include "Sprite.h"

class Window {
public:
    virtual ~Window() = default;

    virtual bool initialize() = 0;
    virtual bool createWindow(int width, int height, const char* title) = 0;
    virtual bool isOpen() = 0;
    virtual void clear() = 0;
    virtual void display() = 0;
    virtual void close() = 0;

    virtual Text* createText() = 0;
    virtual void drawText(const Text& text) = 0;

    virtual void drawSprite(const Sprite& sprite) = 0;
    virtual Sprite* createSprite() = 0; 

    virtual InputManager* createInputManager() = 0;
};