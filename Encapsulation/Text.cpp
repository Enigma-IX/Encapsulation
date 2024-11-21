#include "Text.h"

int Text::getCenterX(int screenWidth) const {
    return (screenWidth / 2) - (getSize().first / 2);
}

int Text::getCenterY(int screenHeight) const {
    return (screenHeight / 2) - (getSize().second / 2);
}