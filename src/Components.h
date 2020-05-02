#pragma once

#include "ECS.h"

struct position {
    int x, y;
};

class PositionComponent : public Component {

private:

    position componentPosition;

public:

    void init() override {
        componentPosition.x = 0;
        componentPosition.y = 0;
    }

    void update() override {
        componentPosition.x ++;
        componentPosition.y ++;
    }

    position getPosition() {
        return componentPosition;
    }

    void setPosition(int x, int y) {
        componentPosition.x = x;
        componentPosition.y = y;
    }
};