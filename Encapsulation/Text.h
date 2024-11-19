#pragma once

#include <string>

// Classe mère abstraite

class Text {
protected:
	int x, y;

public:
	Text() : x(0), y(0) {}
	virtual ~Text() {}

	void setPosition(int x, int y) 
	{
		this->x = x;
		this->y = y;
	}

	std::pair<int, int> getPosition() const { return { x, y }; }

	virtual bool loadFont(const std::string& fontPath, int fontSize) = 0;
	virtual void loadText(const std::string& text) = 0;
	virtual void render() const = 0;
};