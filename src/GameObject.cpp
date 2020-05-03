#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char *textureSheet, int x, int y)
{
    objectTexture = TextureManager::LoadTexture(textureSheet);

    xPosition = x;
    yPosition = y;
};

GameObject::~GameObject()
{
    //
}

void GameObject::Update()
{
//    srcRect.w = 32;
//    srcRect.h = 32;
//    srcRect.x = 0;
//    srcRect.y = 0;
//
//    destRect.x = xPosition;
//    destRect.y = yPosition;
//    destRect.w = srcRect.w * 2;
//    destRect.h = srcRect.h * 2;
}

void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer, objectTexture, &srcRect, &destRect);
}