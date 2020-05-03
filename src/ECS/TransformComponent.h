#pragma once

#include "ECS.h"
#include "Components.h"
#include "../DataTypes/Vector2D.h"

//todo rotation, scale

class TransformComponent : public Component {

public:

    Vector2D position;

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

//    void init() override
//    {
//        position.x = 0;
//        position.y = 0;
//    }

    void update() override
    {
        position.x++;
        position.y++;
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