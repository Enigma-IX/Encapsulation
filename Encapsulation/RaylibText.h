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
	RaylibText(const std::string& fontPath, int fontSize);
	~RaylibText();

	void loadText(const std::string& text) override;
	void render() const override;
};