#include <iostream>
#include "framework.h"

#include "SDLWindow.h"
#include "RaylibWindow.h"

#include "SDLText.h"
#include "RaylibText.h"

#include "TimeManager.h"

#define USE_SDL false

#if USE_SDL
using CurrentWindow = SDLWindow;
using CurrentText = SDLText;
#define TITLE "SDL"
#else
using CurrentWindow = RaylibWindow;
using CurrentText = RaylibText;

#define TITLE "Raylib"
#endif



int main(int argc, char* argv[])
{
    CurrentWindow window;
    if (!window.initialize() || !window.createWindow(WIN_WIDTH, WIN_HEIGHT, TITLE)) 
    {
        std::cerr << "Failed to initialize window!" << std::endl;
        return -1;
    }

    float x = WIN_WIDTH/2, y = WIN_HEIGHT/2, dx = 500.0f, dy = 400.0f, radius = 20; // TO DO: Gerer ca avec dans les classes sprite


    // TO DO: Gerer ca ailleur
    CurrentText text("Montserrat-Regular.ttf", 24);
    text.setPosition(100, 100);
    text.loadText(std::string("Bienvenue sur :  ") + TITLE);

    SDL_Event event; // TO DO: Gerer ca ailleur
    while (window.isOpen())
    {
        // TO DO: Gerer ca ailleur
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT)
        {
            break;
        }

        TimeManager::Instance().Update();

        window.clear();

        // TO DO: Gerer ca avec dans les classes sprite  (Logique de rebonsissement)
        x += dx * TimeManager::Instance().GetDeltaTime();
        y += dy * TimeManager::Instance().GetDeltaTime();
        if (x - radius < 0 || x + radius > WIN_WIDTH) dx = -dx;
        if (y - radius < 0 || y + radius > WIN_HEIGHT) dy = -dy;

        window.drawCircle(x, y, radius);
        text.render(); // TO DO: faire ca avec window.drawText();
        window.display();
    }

    window.close();
    return 0;
}
