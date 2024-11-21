#pragma once

#include "Text.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class SDLText : public Text {
private:
	SDL_Renderer* renderer;
	TTF_Font* font;
	SDL_Texture* texture;
	SDL_Rect rect;
	std::string loadedText;

public:
	SDLText(SDL_Renderer* renderer);
	~SDLText();

	bool loadFont(const std::string& fontPath, int fontSize);
	void loadText(const std::string& text) override;
	void render() const override;
	std::pair<int, int> getSize() const;
};