#include "RaylibWindow.h"
#include "RaylibSprite.h"
#include <iostream>

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

void RaylibWindow::display() {
    EndDrawing();
}

void RaylibWindow::close() {
    if (open) {
        CloseWindow();
        open = false;
    }
}

void RaylibWindow::drawSprite(const Sprite& sprite) {
    // R�cup�ration de la position du sprite
    std::pair<float, float> position = sprite.GetPosition();

    // Appel � la m�thode Draw de l'impl�mentation sp�cifique (RaylibSprite)
    sprite.Draw(position.first, position.second);
}

Sprite* RaylibWindow::createSprite() {
    return new RaylibSprite();
}
