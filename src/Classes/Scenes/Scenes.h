#ifndef ROGUE_SDL_SCENES_H
#define ROGUE_SDL_SCENES_H

#include "../IObject.h"
#include <string>

class Scene : public IObject {
public:
    std::string sceneName;
    Scene() = default;
    ~Scene() = default;
    void init() {};
    void update() {};
    void draw() {};
    void destroy() {};
};

#endif //ROGUE_SDL_SCENES_H
