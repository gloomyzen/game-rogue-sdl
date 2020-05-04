#pragma once

#include <string>
#include "SDL.h"
#include "Components.h"
#include "../DataTypes/Vector2D.h"

class ColliderController : public Component {
public:
    SDL_Rect collider;
    std::string tag;

    TransformComponent* transform;

    void init() override {
        if (!entity->hasComponent<TransformComponent>()) {
            entity->addComponent<TransformComponent>();
        }
        transform = &entity->getComponent<TransformComponent>();
    }
};