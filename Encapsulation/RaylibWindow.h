#pragma once

// Classe pour render avec Raylib

#include "Window.h"
#include "raylib.h"
#include <string>

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
    void drawCircle(float x, float y, float radius) override;
    void drawText(const std::string& fontPath, int fontSize) override;
    void display() override;
    void close() override;
};