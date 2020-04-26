#ifndef ROGUE_SDL_GAME_HPP
#define ROGUE_SDL_GAME_HPP

#include <SDL2/SDL.h>
#include <iostream>

#ifdef EMSCRIPTEN_IS_USED
#include <emscripten.h>
#define EMSCRIPTEN_FLAG 0;
#else
#define EMSCRIPTEN_FLAG 1;
#endif //EMSCRIPTEN_IS_USED

class Game {

public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();
    bool running() { return isRunning; }

private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
};


#endif //ROGUE_SDL_GAME_H
