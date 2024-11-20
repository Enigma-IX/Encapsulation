#pragma once
#include "InputManager.h"

class RaylibInputManager : InputManager
{
public:
    RaylibInputManager();
    ~RaylibInputManager();

    void Update() override;
};

