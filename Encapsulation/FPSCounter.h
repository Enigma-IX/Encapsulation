#pragma once
#include "Text.h"
#include "Window.h"

class FPSCounter
{
public:
	FPSCounter();
	void Init();
	~FPSCounter();

	void Update();
	void Draw();

private:
	Text* fpsText;
	double FPS;
	double elapsedTime;
	int frameCount;
};

