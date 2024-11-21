#include "SDLInputManager.h"
#include "GameManager.h"

SDLInputManager::SDLInputManager()
{
}

SDLInputManager::~SDLInputManager()
{
}

void SDLInputManager::Update() {

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            GameManager::Instance().WipeGame();
            return;
        }

        const Uint8* state = SDL_GetKeyboardState(nullptr);

        // Joueur 1 (flèches directionnelles)
        user1Keys[0] = state[SDL_SCANCODE_UP];    // Haut
        user1Keys[1] = state[SDL_SCANCODE_DOWN];  // Bas
        user1Keys[2] = state[SDL_SCANCODE_LEFT];  // Gauche
        user1Keys[3] = state[SDL_SCANCODE_RIGHT]; // Droite

        // Joueur 2 (z, s, q, d)
        user2Keys[0] = state[SDL_SCANCODE_W];     // Haut
        user2Keys[1] = state[SDL_SCANCODE_S];     // Bas
        user2Keys[2] = state[SDL_SCANCODE_Q];     // Gauche
        user2Keys[3] = state[SDL_SCANCODE_D];     // Droite

        spacePressed = state[SDL_SCANCODE_SPACE];
    }
}

