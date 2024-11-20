#pragma once
#include "Sprite.h"
#include "raylib.h"
#include <string>

class RaylibSprite : public Sprite
{
public:
    RaylibSprite();
    ~RaylibSprite();

    bool LoadImage(const std::string& filepath) override;
    void* GetData() const override;
    void Draw(float x, float y) const override;
    void SetPosition(float x, float y) override;
    std::pair<float, float> GetPosition() const override;

    void SetSize(float width, float height) override;
    std::pair<float, float> GetSize() const override;

private:
    Texture2D* texture;
    float positionX, positionY;
    float width, height;
};

