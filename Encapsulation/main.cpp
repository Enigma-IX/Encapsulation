#include <iostream>
#include "framework.h"

#include "SDLWindow.h"
#include "RaylibWindow.h"


#define USE_SDL true

#if USE_SDL
using CurrentWindow = SDLWindow;
#else
using CurrentWindow = RaylibWindow;
#endif



int main(int argc, char* argv[])
{
    CurrentWindow window;
    if (!window.initialize() || !window.createWindow(WIN_WIDTH, WIN_HEIGHT, "Encapsulation")) 
    {
        std::cerr << "Failed to initialize window!" << std::endl;
        return -1;
    }

    float x = 400, y = 300, dx = 2.5f, dy = 2.0f, radius = 20; // TO DO: Gerer ca avec dans les classes sprite

    SDL_Event event; // TO DO: Gerer ca ailleur
    while (window.isOpen())
    {
        // TO DO: Gerer ca ailleur
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT)
        {
            break;
        }


        window.clear();

        // TO DO: Gerer ca avec dans les classes sprite  (Logique de rebonsissement)
        x += dx;
        y += dy;
        if (x - radius < 0 || x + radius > WIN_WIDTH) dx = -dx;
        if (y - radius < 0 || y + radius > WIN_HEIGHT) dy = -dy;

        window.drawCircle(x, y, radius);
        window.display();
    }

    window.close();
    return 0;
}
