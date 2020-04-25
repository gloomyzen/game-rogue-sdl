#ifndef ROGUE_SDL_GAME_HPP
#define ROGUE_SDL_GAME_HPP

#include <SDL2/SDL.h>
#include <iostream>

class Game {

public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void update();
    void render();
private:
};


#endif //ROGUE_SDL_GAME_H
