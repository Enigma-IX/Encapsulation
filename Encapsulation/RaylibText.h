#pragma once

#include "Text.h"

class RaylibText : public Text
{
public:
	RaylibText();
	~RaylibText();

	void SetText() override;
	void GetText() override;
	void DrawText() override;
	void SetPosition() override;
};

