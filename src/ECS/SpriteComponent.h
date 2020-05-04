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
    ~SpriteComponent() {
        SDL_DestroyTexture(texture);
    }

    void init() override
    {
        if (!entity->hasComponent<TransformComponent>()) {
            entity->addComponent<TransformComponent>();
        }
        transform = &entity->getComponent<TransformComponent>();
        srcRect.x = 0;
        srcRect.y = 0;
        srcRect.w = transform->width;
        srcRect.h = transform->height;
        destRect.w = transform->width * transform->scale;
        destRect.h = transform->height * transform->scale;
    }

    void update() override
    {
        destRect.x = (int)transform->position.x;
        destRect.y = (int)transform->position.y;
        destRect.w = transform->width * transform->scale;
        destRect.h = transform->height * transform->scale;
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