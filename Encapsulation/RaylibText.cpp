#include "RaylibText.h"

#include <stdexcept>


RaylibText::RaylibText(const std::string& fontPath, int fontSize) : color(WHITE) {
	font = LoadFontEx(fontPath.c_str(), fontSize, nullptr, 0);
	if (!font.texture.id) {
		throw std::runtime_error("Erreur lors du chargement de la police : " + fontPath);
	}
}

RaylibText::~RaylibText() {
	UnloadFont(font);
}

void RaylibText::loadText(const std::string& text) {
	loadedText = text;
}

void RaylibText::render() const {
	if (loadedText.empty()) {
		throw std::runtime_error("Aucun texte chargé pour le rendu.");
	}
	DrawTextEx(font, loadedText.c_str(), { static_cast<float>(x), static_cast<float>(y) },
		font.baseSize, 2, color);
}
