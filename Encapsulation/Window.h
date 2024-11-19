#pragma once

#include <string>
#include "Text.h"

// Classe mère abstraite

class Window {
public:
    virtual ~Window() = default;

    virtual bool initialize() = 0;
    virtual bool createWindow(int width, int height, const char* title) = 0;
    virtual bool isOpen() = 0;
    virtual void clear() = 0;
    virtual void drawCircle(float x, float y, float radius) = 0;
    virtual void display() = 0;
    virtual void close() = 0;

    virtual Text* createText() = 0;
    virtual void drawText(const Text& text) = 0;
};