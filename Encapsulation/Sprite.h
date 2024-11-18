#pragma once
#include <string>

// Classe mère abstraite

class Sprite {
public:
    virtual ~Sprite() = default;

    virtual bool LoadImage(const std::string& filepath) = 0;
    virtual void* GetData() const = 0;
    virtual void Draw(float x, float y) = 0;
    virtual void SetPosition(float x, float y) = 0;
    virtual std::pair<float, float> GetPosition() const = 0;
};