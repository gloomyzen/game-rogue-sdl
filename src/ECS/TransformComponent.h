#pragma once

#include "ECS.h"
#include "Components.h"
#include "../DataTypes/Vector2D.h"

//todo rotation, scale

class TransformComponent : public Component {

private:

    Vector2D componentTransform;

public:

    TransformComponent()
    {
        componentTransform.x = 0.0f;
        componentTransform.y = 0.0f;
    }

    TransformComponent(float x, float y)
    {
        componentTransform.x = x;
        componentTransform.y = y;
    }

//    void init() override
//    {
//        componentTransform.x = 0;
//        componentTransform.y = 0;
//    }

    void update() override
    {
        componentTransform.x++;
        componentTransform.y++;
    }

    Vector2D getPosition()
    {
        return componentTransform;
    }

    void setPosition(float x, float y)
    {
        componentTransform.x = x;
        componentTransform.y = y;
    }
};