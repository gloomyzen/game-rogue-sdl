#pragma once

#include "ECS.h"
#include "Components.h"
#include "../DataTypes/Vector2D.h"

//todo rotation, scale

class TransformComponent : public Component {

public:

    Vector2D position;
    Vector2D velocity;
    Vector2D movement;
//
    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    double deltaTime = 0;

    const float deltaSpeed = 1.0f;
    const int maxSpeed = 3;

    TransformComponent()
    {
        position.x = 0.0f;
        position.y = 0.0f;
    }

    TransformComponent(float x, float y)
    {
        position.x = x;
        position.y = y;
    }

    void init() override
    {
//        velocity.x = 0;
//        velocity.y = 0;
    }

    void update() override
    {
        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();

        deltaTime = (double)((NOW - LAST)*1000 / (double)SDL_GetPerformanceFrequency() );

        if (std::abs(velocity.x) > 0 && velocity.x > 0 && movement.x >= 0 || velocity.x < 0 && movement.x <= 0) {
            movement.x = std::abs(movement.x + (deltaSpeed / deltaTime)) <= maxSpeed ? movement.x + (deltaSpeed / deltaTime) * velocity.x : maxSpeed * velocity.x;
        } else {
            if (movement.x > 0) {
                std::cout << "one" << std::endl;
                movement.x = movement.x - (deltaSpeed / deltaTime * 2);
                movement.x = std::abs(movement.x) > 0.1f ? movement.x : 0;
            } else if (movement.x < 0) {
                std::cout << "two" << std::endl;
                movement.x = movement.x + (deltaSpeed / deltaTime * 2);
                movement.x = std::abs(movement.x) > 0.1f ? movement.x : 0;
            } else {
                movement.x = 0;
            }
        }
        std::cout << movement.x << std::endl;
//        if (std::abs(movement.x + (deltaSpeed / deltaTime)) <= maxSpeed) {
//            movement.x = movement.x + (deltaSpeed / deltaTime) * velocity.x;
//        } else {
//            movement.x = maxSpeed * velocity.x;
//        }
//        movement.x = std::abs(movement.x + (deltaSpeed / deltaTime)) <= maxSpeed ? movement.x + (deltaSpeed / deltaTime) * velocity.x : maxSpeed * velocity.x;


        if (std::abs(velocity.x) > 0) {
//            movement.x = std::abs(movement.x + (deltaSpeed / deltaTime)) <= maxSpeed ? (movement.x + (deltaSpeed / deltaTime)) * velocity.x : maxSpeed * velocity.x;
        } else {
//            movement.x = std::abs(movement.x - (deltaSpeed / deltaTime * 2)) < deltaSpeed ? movement.x - (deltaSpeed / deltaTime * 2) : 0;
        }
//        std::cout << movement.x << std::endl;

//        if (velocity.y != 0) {
//            movement.y = std::abs(movement.y + (deltaSpeed / deltaTime)) <= maxSpeed ? movement.y + (deltaSpeed / deltaTime) * velocity.y : maxSpeed * velocity.y;
//        } else {
//            if (movement.y > 0) {
//                movement.y = movement.y > 0 ? movement.y - (deltaSpeed / deltaTime * 2) : 0;
//            } else if (movement.y < 0) {
//                movement.y = movement.y < 0 ? movement.y + (deltaSpeed / deltaTime * 2) : 0;
//            }
//        }

        position.x += movement.x;
        position.y += movement.y;
    }

    Vector2D getPosition()
    {
        return position;
    }

    void setPosition(float x, float y)
    {
        position.x = x;
        position.y = y;
    }
};