#include <iostream>
#include "framework.h"

#include "SDLWindow.h"
#include "RaylibWindow.h"

#include "SDLText.h"
#include "RaylibText.h"

#include "TimeManager.h"

#define USE_SDL true // Basculer entre SDL et Raylib

#if USE_SDL
using CurrentWindow = SDLWindow;
#define TITLE "SDL"
#else
using CurrentWindow = RaylibWindow;
#define TITLE "Raylib"
#endif

int main() {
    CurrentWindow window;
    if (!window.initialize() || !window.createWindow(WIN_WIDTH, WIN_HEIGHT, TITLE)) {
        std::cerr << "Failed to initialize window!" << std::endl;
        return -1;
    }


    float x = WIN_WIDTH/2, y = WIN_HEIGHT/2, dx = 500.0f, dy = 400.0f, radius = 20.0f; // Radius a changer
  
    Text* text = window.createText();
    if (!text->loadFont("Montserrat-Regular.ttf", 24))
    {
        delete text;
        return -1;
    }
    text->setPosition(100, 100);
	text->loadText("Bienvenue");
  
    Sprite* sprite = window.createSprite();
    if (!sprite->LoadImage("ball.png")) {
        std::cerr << "Failed to load sprite image!" << std::endl;
        delete sprite;
        return -1;
    }
    sprite->SetPosition(x, y);

   

    SDL_Event event;
    while (window.isOpen()) {

        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT)
        {
            break;
        }

        TimeManager::Instance().Update();
        float deltaTime = TimeManager::Instance().GetDeltaTime();
        
        // TO DO: Gerer ca avec dans les classes sprite  (Logique de rebonsissement)
        x += dx * TimeManager::Instance().GetDeltaTime();
        y += dy * TimeManager::Instance().GetDeltaTime();
      
        /*
        if (x < 0 || x > WIN_WIDTH - 50) dx = -dx;
        if (y < 0 || y > WIN_HEIGHT - 50) dy = -dy;*/
        if (x - radius < 0 || x + radius > WIN_WIDTH) dx = -dx; // Radius a changer
        if (y - radius < 0 || y + radius > WIN_HEIGHT) dy = -dy; // Radius a changer
      
        sprite->SetPosition(x, y);
      
        window.clear();
      
        window.drawText(*text);
        window.drawSprite(*sprite); 
      
        window.display();
    }

    delete sprite;
    window.close();
    return 0;
}
