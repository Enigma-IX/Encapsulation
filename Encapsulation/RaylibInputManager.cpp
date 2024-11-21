#include "RaylibInputManager.h"
#include <raylib.h>

RaylibInputManager::RaylibInputManager()
{
}

RaylibInputManager::~RaylibInputManager()
{
}

void RaylibInputManager::Update() {

    // User 1
    user1Keys[0] = IsKeyDown(KEY_UP);    // Haut
    user1Keys[1] = IsKeyDown(KEY_DOWN);  // Bas
    user1Keys[2] = IsKeyDown(KEY_LEFT);  // Gauche
    user1Keys[3] = IsKeyDown(KEY_RIGHT); // Droite

    // User 2
    user2Keys[0] = IsKeyDown(KEY_Z);     // Haut
    user2Keys[1] = IsKeyDown(KEY_S);     // Bas
    user2Keys[2] = IsKeyDown(KEY_Q);     // Gauche
    user2Keys[3] = IsKeyDown(KEY_D);     // Droite
}
