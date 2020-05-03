#pragma once

#include "Components.h"
#include "SDL.h"
#include "../TextureManager.h"

class SpriteComponent : public Component {
private:
    TransformComponent *transform{};
    SDL_Texture *texture{};
    SDL_Rect srcRect{}, destRect{};

    //todo дефолтный файл, ширина и высота
    // todo, тип спрайта
public:
    SpriteComponent() = default;
    explicit SpriteComponent(const char* path/*, int width, int height*/)
    {
        setTexture(path);
    }

    void init() override
    {
        transform = &entity->getComponent<TransformComponent>();
        srcRect.x = srcRect.y = 0;
        srcRect.w = srcRect.h = 32 * 2;
        destRect.w = destRect.h = 32 * 2;
    }

    void update() override
    {
        destRect.x = (int)transform->position.x;
        destRect.y = (int)transform->position.y;
    }

    void draw() override
    {
        TextureManager::Draw(texture, srcRect, destRect);
    }

    void setTexture(const char* path)
    {
        texture = TextureManager::LoadTexture(path);
    }
};