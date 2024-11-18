#include "SDLSprite.h"
#include <SDL_image.h>

SDLSprite::SDLSprite(SDL_Renderer* renderer) : texture(nullptr), renderer(renderer), positionX(0), positionY(0) {};

SDLSprite::~SDLSprite() 
{
	if (texture) 
	{
		SDL_DestroyTexture(texture);
	}
}

bool SDLSprite::LoadImage(const std::string& filepath)
{
	SDL_Surface* surface = IMG_Load(filepath.c_str());
	if (surface == false) {
		return false;
	}

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	return texture != nullptr;
}

void* SDLSprite::GetData() const 
{
	return texture;
}

void SDLSprite::Draw(float x, float y)
{
	if (texture == false) {
		return;
	}

	
}