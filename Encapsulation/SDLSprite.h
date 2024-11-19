#pragma once
#include "Sprite.h"
#include <SDL.h>
#include <string>

class SDLSprite : public Sprite
{

public:
	SDLSprite(SDL_Renderer* renderer);
	~SDLSprite();

	bool LoadImage(const std::string& filepath) override;
	void* GetData() const override;
	void Draw(float x, float y) const override;
	void SetPosition(float x, float y) override;
	std::pair<float, float> GetPosition() const override;

private:
	SDL_Texture* texture;
	SDL_Renderer* renderer;
	float positionX, positionY;
};

