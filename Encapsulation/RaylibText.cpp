#include "RaylibText.h"

#include <stdexcept>


RaylibText::RaylibText() : color(WHITE), font({0,0}) {}

RaylibText::~RaylibText() {
	UnloadFont(font);
}

bool RaylibText::loadFont(const std::string& fontPath, int fontSize)
{
	font = LoadFontEx(fontPath.c_str(), fontSize, nullptr, 0);
	if (!font.texture.id) {
		throw std::runtime_error("Erreur lors du chargement de la police : " + fontPath);
		return false;
	}
	return true;
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

std::pair<int, int> RaylibText::getSize() const {
	if (loadedText.empty()) {
		throw std::runtime_error("Aucun texte chargé pour obtenir la taille.");
	}
	Vector2 size = MeasureTextEx(font, loadedText.c_str(), font.baseSize, 2);
	return { static_cast<int>(size.x), static_cast<int>(size.y) };
}

