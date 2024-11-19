#pragma once

#include "SDLWindow.h"
#include "RaylibWindow.h"

#ifdef USE_SDL
using CurrentWindow = SDLWindow;
#define TITLE "SDL"
#elif defined(USE_RAYLIB)
using CurrentWindow = RaylibWindow;
#define TITLE "Raylib"
#endif
