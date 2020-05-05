#pragma once

#include "Game.h"
#include "ECS/ECS.h"
#include "ECS/Components.h"

class GameObject {

public:
    static Manager components;
    GameObject();
    GameObject(int x, int y);
//    GameObject(const char *textureSheet, int x, int y);
    ~GameObject();
    void Update();
    void Render();
private:

//    int xPosition, yPosition;
//    SDL_Texture* objectTexture;
//    SDL_Rect srcRect, destRect;
};
