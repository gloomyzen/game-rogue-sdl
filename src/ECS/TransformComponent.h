#pragma once

#include "ECS.h"
#include "Components.h"


struct position {
    int x, y;
    //todo rotation, scale
};

class TransformComponent : public Component {

private:

    position componentTransform{};

public:

    TransformComponent()
    {
        componentTransform.x = 0;
        componentTransform.y = 0;
    }

    TransformComponent(int x, int y)
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
//        componentTransform.x++;
//        componentTransform.y++;
    }

    position getPosition()
    {
        return componentTransform;
    }

    void setPosition(int x, int y)
    {
        componentTransform.x = x;
        componentTransform.y = y;
    }
};