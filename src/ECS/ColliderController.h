#pragma once

#include <string>
#include "SDL.h"
#include "Components.h"
#include "../Classes/DataTypes/Vector2D.h"
#include "../Classes/Collision.h"

class ColliderController : public Component {
public:
    SDL_Rect collider;
    std::string tag;

    TransformComponent* transform;

    ColliderController(const char* name) {
        std::cout << name << std::endl;
        this->tag = name;
    }

    void init() override {
        if (!entity->hasComponent<TransformComponent>()) {
            entity->addComponent<TransformComponent>();
        }
        transform = &entity->getComponent<TransformComponent>();
    }

    void update() override {
        collider.x = transform->position.x;
        collider.y = transform->position.y;
        collider.w = transform->width * transform->scale;
        collider.h = transform->height * transform->scale;
    }
};