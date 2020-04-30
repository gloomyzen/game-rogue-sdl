#ifndef ROGUE_SDL_GAME_H
#define ROGUE_SDL_GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#ifdef __EMSCRIPTEN__
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
    void gameLoop();
    void quit();
    bool running() { return isRunning; }
    bool emscripten() { return isEmscripten; }

private:
    bool isEmscripten;
    bool isRunning = false;
    SDL_Window *window;
    SDL_Renderer *renderer;
    /*
     * Frame Limiting
     */
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;
};


#endif //ROGUE_SDL_GAME_H
