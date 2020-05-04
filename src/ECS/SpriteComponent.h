#pragma once

#include "Components.h"
#include "SDL.h"
#include "../TextureManager.h"

class SpriteComponent : public Component {
private:
    TransformComponent *transform{};
    SDL_Texture *texture{};
    SDL_Rect srcRect{}, destRect{};

    bool isAnimated = false;
    int frames = 0;
    int speed = 100;

    //todo дефолтный файл, ширина и высота
public:
    SpriteComponent() = default;
    explicit SpriteComponent(const char* path/*, int width, int height*/)
    {
        setTexture(path);
    }

    explicit SpriteComponent(const char* path, int nFrames, int nSpeed)
    {
        isAnimated = true;
        frames = nFrames;
        speed = nSpeed;
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
        if(isAnimated) {
            srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
        }
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