#pragma once

#include "Text.h"
#include <raylib.h>
#include <string>

class RaylibText : public Text {
private:
	Font font;
	std::string loadedText;
	Color color;

public:
	RaylibText();
	~RaylibText();

	bool loadFont(const std::string& fontPath, int fontSize);
	void loadText(const std::string& text) override;
	void render() const override;
};