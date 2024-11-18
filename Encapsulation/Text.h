#pragma once

// Classe mère abstraite

class Text {
public:
	virtual ~Text() = default;

	virtual void SetText() = 0;
	virtual void GetText() = 0;
	virtual void DrawText() = 0;
	virtual void SetPosition() = 0;

	float posX;
	float poxY;
};
