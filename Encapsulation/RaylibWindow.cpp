#include "RaylibWindow.h"

RaylibWindow::RaylibWindow() : open(false) {}

RaylibWindow::~RaylibWindow() {
    close();
}

bool RaylibWindow::initialize() {
    return true;
}

bool RaylibWindow::createWindow(int width, int height, const char* title) {
    InitWindow(width, height, title);
    open = !WindowShouldClose();
    return open;
}

bool RaylibWindow::isOpen() {
    return !WindowShouldClose();
}

void RaylibWindow::clear() {
    BeginDrawing();
    ClearBackground(BLACK);
}

void RaylibWindow::drawCircle(float x, float y, float radius) {
    // TO DO: gerer ca dans Sprite
    DrawCircle(static_cast<int>(x), static_cast<int>(y), radius, WHITE);
}

void RaylibWindow::display() {
    EndDrawing();
}

void RaylibWindow::close() {    
    if (open) {
        CloseWindow();
        open = false;
    }
}
