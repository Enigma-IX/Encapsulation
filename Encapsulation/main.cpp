#define SDL_MAIN_HANDLED
#include <iostream>
#include "framework.h"
#include "SDLWindow.h"
#include "RaylibWindow.h"
#include "TimeManager.h"

#define USE_SDL true // Basculer entre SDL et Raylib à la compilation

#if USE_SDL
using CurrentWindow = SDLWindow;
#else
using CurrentWindow = RaylibWindow;
#endif

int main() {
    // Initialisation de la fenêtre
    CurrentWindow window;
    if (!window.initialize() || !window.createWindow(WIN_WIDTH, WIN_HEIGHT, "Encapsulation Project")) {
        std::cerr << "Failed to initialize window!" << std::endl;
        return -1;
    }

    // Création du sprite via la méthode polymorphe
    Sprite* sprite = window.createSprite();
    if (!sprite->LoadImage("D:/Cours4/Projet3/Encapsulation/bob_leponge")) {
        std::cerr << "Failed to load sprite image!" << std::endl;
        delete sprite;
        return -1;
    }

    // Position initiale et vitesse
    float x = WIN_WIDTH / 2, y = WIN_HEIGHT / 2;
    float dx = 200.0f, dy = 150.0f;
    sprite->SetPosition(x, y);

    while (window.isOpen()) {
        TimeManager::Instance().Update();
        float deltaTime = TimeManager::Instance().GetDeltaTime();

        // Mise à jour des positions et rebonds
        x += dx * deltaTime;
        y += dy * deltaTime;
        if (x < 0 || x > WIN_WIDTH - 50) dx = -dx;
        if (y < 0 || y > WIN_HEIGHT - 50) dy = -dy;

        sprite->SetPosition(x, y);

        // Rendu
        window.clear();
        window.drawSprite(*sprite); // Dessin du sprite via la fenêtre
        window.display();
    }

    delete sprite;
    window.close();
    return 0;
}
