#pragma once
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
    virtual void drawSprite(const Sprite& sprite) = 0;
    virtual Sprite* createSprite() = 0; 
};
