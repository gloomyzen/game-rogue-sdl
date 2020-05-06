#pragma once

#include "../Game.h"
#include "ECS.h"
#include "Components.h"
#include <iostream>
#include "SDL.h"

class TouchController : public Component {
public:
    TransformComponent *transform;
    SpriteComponent *sprite;

    float touchX;
    float touchY;
    float motionX;
    float motionY;
    bool isActive;

    TouchController() = default;

    void init() override {
        //TODO remove this
        if (!entity->hasComponent<TransformComponent>()) {
            entity->addComponent<TransformComponent>();
        }
        transform = &entity->getComponent<TransformComponent>();

        if (!entity->hasComponent<SpriteComponent>()) {
            entity->addComponent<SpriteComponent>();
        }
        sprite = &entity->getComponent<SpriteComponent>();
    }

    void update() override {
        //TODO try to use and create TouchController
//        Game::event.tfinger
        if (Game::event.type == SDL_FINGERDOWN) {
            isActive = true;
            touchX = Game::event.tfinger.x;
            touchY = Game::event.tfinger.y;
        }
        if (Game::event.type == SDL_FINGERMOTION) {
            motionX = Game::event.tfinger.x;
            motionY = Game::event.tfinger.y;
            if (isActive) {
                if (std::abs(touchX - motionX) > 0.01f && touchX < motionX) {
                    transform->velocity.x = 1;
                    motionY = Game::event.tfinger.y;
                    sprite->play("Walk");
                sprite->spriteFlip = SDL_FLIP_NONE;
                } else if (std::abs(touchX - motionX) > 0.01f && touchX > motionX) {
                    transform->velocity.x = -1;
                    motionY = Game::event.tfinger.y;
                    sprite->play("Walk");
                    sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
                }
                if (std::abs(touchY - motionY) > 0.01f && touchY < motionY) {
                    transform->velocity.y = 1;
                    motionX = Game::event.tfinger.x;
                    sprite->play("Walk");
                } else if (std::abs(touchY - motionY) > 0.01f && touchY > motionY) {
                    transform->velocity.y = -1;
                    motionX = Game::event.tfinger.x;
                    sprite->play("Walk");
                }
            }
        }
        if (Game::event.type == SDL_FINGERUP) {
            isActive = false;
            transform->velocity.x = 0;
            transform->velocity.y = 0;
            sprite->play("Idle");
        }
        if (!isActive) {
//            transform->velocity.x = 0;
//            transform->velocity.y = 0;
//            sprite->play("Idle");
        }
    }
};