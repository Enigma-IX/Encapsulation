#pragma once

#include "Text.h"

class SDLText : public Text
{
public:
	SDLText();
	~SDLText();

	void SetText() override;
	void GetText() override;
	void DrawText() override;
	void SetPosition() override;
};

