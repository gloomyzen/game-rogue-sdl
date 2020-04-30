#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* renderer)
{
    objectRenderer = renderer;
    objectTexture = TextureManager::LoadTexture(textureSheet, objectRenderer);

};

GameObject::~GameObject()
{
    //
}

void GameObject::Update()
{
    //Movement
}

void GameObject::Render()
{
    SDL_RenderCopy(objectRenderer, objectTexture, &srcRect, &destRect);
}