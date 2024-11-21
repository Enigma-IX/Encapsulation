#include "InputManager.h"

InputManager::InputManager() {
    for (int i = 0; i < 4; ++i) {
        user1Keys[i] = false;
        user2Keys[i] = false;
    }
}

bool InputManager::IsKeyPressed(int user, char key) const {
    if (user == 1) {
        switch (key) {
            case 'u': return user1Keys[0]; // Haut
            case 'd': return user1Keys[1]; // Bas
            case 'l': return user1Keys[2]; // Gauche
            case 'r': return user1Keys[3]; // Droite
        }
    }
    else if (user == 2) {
        switch (key) {
            case 'z': return user2Keys[0]; // Haut
            case 's': return user2Keys[1]; // Bas
            case 'q': return user2Keys[2]; // Gauche
            case 'd': return user2Keys[3]; // Droite
        }
    }
    return false;
}