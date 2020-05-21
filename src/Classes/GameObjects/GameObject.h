#pragma once

#include "../IObject.h"
#include "../Game.h"
#include "../ECS/ECS.h"
#include "../ECS/Components.h"

class GameObject : public IObject {

public:
//    static Manager components;
    GameObject() = default;
    GameObject(int x, int y);
    ~GameObject() = default;
    void init() {};
    void update() {};
    void draw() {};
    void destroy() {};
private:

//    int xPosition, yPosition;
//    SDL_Texture* objectTexture;
//    SDL_Rect srcRect, destRect;
};
