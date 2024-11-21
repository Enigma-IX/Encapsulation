#include "SDLInputManager.h"
#include "GameManager.h"

SDLInputManager::SDLInputManager()
{
}

SDLInputManager::~SDLInputManager()
{
}

void SDLInputManager::Update() {
    // Réinitialisation des tableaux
    for (int i = 0; i < 4; ++i) {
        user1Keys[i] = false;
        user2Keys[i] = false;
    }

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            GameManager::Instance().WipeGame();
            return;
        }

        if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
            bool isPressed = (event.type == SDL_KEYDOWN);

            switch (event.key.keysym.sym) {
                // User 1
            case SDLK_UP: user1Keys[0] = isPressed; break;    // Haut
            case SDLK_DOWN: user1Keys[1] = isPressed; break;  // Bas
            case SDLK_LEFT: user1Keys[2] = isPressed; break;  // Gauche
            case SDLK_RIGHT: user1Keys[3] = isPressed; break; // Droite

                // User 2
            case SDLK_z: user2Keys[0] = isPressed; break;     // Haut
            case SDLK_s: user2Keys[1] = isPressed; break;     // Bas
            case SDLK_q: user2Keys[2] = isPressed; break;     // Gauche
            case SDLK_d: user2Keys[3] = isPressed; break;     // Droite
            }
        }
    }
}
