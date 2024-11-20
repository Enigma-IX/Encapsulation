#pragma once

#include "SDLWindow.h"
#include "RaylibWindow.h"

#ifdef USE_SDL
using CurrentWindow = SDLWindow;
#define TITLE "SDL"
#elif defined(USE_RAYLIB)
using CurrentWindow = RaylibWindow;
#define TITLE "Raylib"
#else
using CurrentWindow = RaylibWindow;
#define TITLE "DEFAULT is Raylib, please use Debug-Raylib or Debug-SDL"
#endif
