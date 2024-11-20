#pragma once
#include "Text.h"

class FPSCounter
{
public:
	FPSCounter(Text* texte);
	~FPSCounter();

	void Update(double deltaTime);
	void Renderer();

private:
	Text* fpsText;
	double FPS;
	double elapsedTime;
	int frameCount;
};

