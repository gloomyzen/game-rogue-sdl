#pragma once

#include "ECS.h"
#include "Components.h"
#include "../DataTypes/Vector2D.h"

//todo rotation, scale

class TransformComponent : public Component {

public:

    Vector2D position;
    Vector2D velocity;

    int defaultSpeed = 1;
    int speed = 1;

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
        velocity.x = 0;
        velocity.y = 0;
    }

    void update() override
    {
        position.x += velocity.x * (float)speed;
        position.y += velocity.y * (float)speed;
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