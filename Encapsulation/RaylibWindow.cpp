#include "RaylibWindow.h"
#include "RaylibSprite.h"
#include "RaylibInputManager.h"
#include <iostream>

#include "RaylibText.h"

RaylibWindow::RaylibWindow() : open(false) {}

RaylibWindow::~RaylibWindow() {
    close();
}

bool RaylibWindow::initialize() {
    return true;
}

bool RaylibWindow::createWindow(int width, int height, const char* title) {
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
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


void RaylibWindow::drawText(const Text& text)
{
    text.render();
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


Text* RaylibWindow::createText()
{
    return new RaylibText();
}

void RaylibWindow::drawSprite(const Sprite& sprite) {
    // Récupération de la position du sprite
    std::pair<float, float> position = sprite.GetPosition();

    // Appel à la méthode Draw de l'implémentation spécifique (RaylibSprite)
    sprite.Draw(position.first, position.second);
}

Sprite* RaylibWindow::createSprite() {
    return new RaylibSprite();
}

InputManager* RaylibWindow::createInputManager()
{
    return new RaylibInputManager();
}