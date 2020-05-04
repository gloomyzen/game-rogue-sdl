#pragma once

#include "ECS.h"
#include "Components.h"
#include "../Classes/DataTypes/Vector2D.h"

//todo rotation

class TransformComponent : public Component {

public:

    Vector2D position;
    Vector2D velocity;
    Vector2D movement;

    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    double deltaTime = 0;

    const float deltaSpeed = 1.5f;
    const float maxSpeed = 3.0f;

    int width = 32;
    int height = 32;
    int scale = 1;

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
        //
    }

    void update() override
    {
        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();

        deltaTime = (double)((NOW - LAST)*1000 / (double)SDL_GetPerformanceFrequency() );

        position.x += movement.x = getMovement(&velocity.x, &movement.x, &deltaTime);
        position.y += movement.y = getMovement(&velocity.y, &movement.y, &deltaTime);
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

private:
    float getMovement(const float *pVelocity, float *pMovement, const double *pDeltaTime) {
        if (std::abs(*pVelocity) > 0 && ((*pVelocity > 0 && *pMovement >= 0) || (*pVelocity < 0 && *pMovement <= 0))) {
            if (std::abs(*pMovement + (deltaSpeed / *pDeltaTime)) <= maxSpeed) {
                *pMovement = *pMovement + (deltaSpeed / *pDeltaTime) * *pVelocity;
            } else {
                *pMovement = maxSpeed * *pVelocity;
            }
        } else {
            if (*pMovement > 0) {
                *pMovement = *pMovement - (deltaSpeed / *pDeltaTime * 2);
                *pMovement = std::abs(*pMovement) > 0.1f ? *pMovement : 0;
            } else if (*pMovement < 0) {
                *pMovement = *pMovement + (deltaSpeed / *pDeltaTime * 2);
                *pMovement = std::abs(*pMovement) > 0.1f ? *pMovement : 0;
            } else {
                *pMovement = 0;
            }
        }
        return *pMovement;
    }
};