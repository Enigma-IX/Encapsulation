#include "SDLText.h"

#include <stdexcept>
#include <iostream>

SDLText::SDLText(SDL_Renderer* renderer)
	: renderer(renderer), texture(nullptr), font(nullptr), rect({0,0,0,0}) { }

SDLText::~SDLText() {
	if (texture) {
		SDL_DestroyTexture(texture);
	}
	if (font) {
		TTF_CloseFont(font);
	}
	TTF_Quit();
}

bool SDLText::loadFont(const std::string& fontPath, int fontSize)
{
	if (TTF_Init() == -1) {
		throw std::runtime_error("Erreur d'initialisation de TTF : " + std::string(TTF_GetError()));
		return false;
	}
	font = TTF_OpenFont(fontPath.c_str(), fontSize);
	if (!font) {
		throw std::runtime_error("Erreur lors du chargement de la police : " + std::string(TTF_GetError()));
		return false;
	}
	return true;
}

void SDLText::loadText(const std::string& text) {
	loadedText = text;

	if (texture) {
		SDL_DestroyTexture(texture);
	}

	SDL_Color color = { 255, 255, 255, 255 };
	SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), color);
	if (!surface) {
		std::cerr << "Erreur TTF_OpenFont : " << TTF_GetError() << std::endl;
		throw std::runtime_error("Erreur de rendu du texte : " + std::string(TTF_GetError()));
	}

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (!texture) {
		SDL_FreeSurface(surface);
		std::cerr << "Erreur TTF_OpenFont : " << std::string(SDL_GetError()) << std::endl;
		throw std::runtime_error("Erreur de création de texture : " + std::string(SDL_GetError()));
	}

	rect = { x, y, surface->w, surface->h };
	SDL_FreeSurface(surface);
}

void SDLText::render() const {
	if (!texture) {
		throw std::runtime_error("Aucun texte chargé pour le rendu.");
	}
	SDL_RenderCopy(renderer, texture, nullptr, &rect);
}

std::pair<int, int> SDLText::getSize() const {
	if (!texture) {
		throw std::runtime_error("Aucun texte chargé pour obtenir la taille.");
	}
	return { rect.w, rect.h };
}
