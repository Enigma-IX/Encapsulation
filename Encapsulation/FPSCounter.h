#pragma once
#include "Text.h"

class FPSCounter
{
public:
	FPSCounter(Text* texte);
	~FPSCounter();
private:
	Text* fpsText;
};

