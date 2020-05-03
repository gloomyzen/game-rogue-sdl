#pragma once

#include "../Game.h"
#include "ECS.h"
#include "Components.h"

class KeyboardController : public Component {
public:
    TransformComponent *transform;

    void init() override {
        transform = &entity->getComponent<TransformComponent>();
    }

    void update() override {
//        if (Game::event.type == SDL_KEYDOWN)
    }
};