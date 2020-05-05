#pragma once

#include "../Game.h"
#include "ECS.h"
#include "Components.h"
#include <iostream>
#include "SDL.h"

class CameraComponent : public Component {
    TransformComponent *position;
    TransformComponent *target;

    CameraComponent();

    void init() override {
        //Setup variables
    }

    void update() override {
        //change coordinates, like this
    }
};
