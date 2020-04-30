#pragma once

#include "Game.h"

class GameObject {

public:
    GameObject(const char *textureSheet, SDL_Renderer *renderer, int x, int y);
    ~GameObject();
    void Update();
    void Render();
private:

    int xPosition, yPosition;
    SDL_Texture* objectTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* objectRenderer;
};
