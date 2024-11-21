#pragma once
#include "InputManager.h"

class RaylibInputManager : public InputManager
{
public:
    RaylibInputManager();
    ~RaylibInputManager();

    void Update() override;
};

