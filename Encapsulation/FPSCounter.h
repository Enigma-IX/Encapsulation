#pragma once
#include "Text.h"
#include "Window.h"

class FPSCounter
{
public:
	FPSCounter(Text* texte);
	~FPSCounter();

	void Update(double deltaTime);
	void Draw(Window& window);

private:
	Text* fpsText;
	double FPS;
	double elapsedTime;
	int frameCount;
};

