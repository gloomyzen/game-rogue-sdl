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
#endif //__EMSCRIPTEN__

#ifdef __DEBUG__
const bool debugMode = true;
#else
const bool debugMode = false;
#endif

class Game {

public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void windowResize(int width, int height); // Only for emscripten

    void handleEvents();
    void update();
    void render();
    void gameLoop();
    void quit();
    bool running() { return isRunning; }
    constexpr bool emscripten() { return isEmscripten; }
    static bool isDebug() { return debug; }


    static SDL_Renderer *renderer;
    static SDL_Event event;
    static void renderDrawColor();
    static SDL_Rect camera;

private:
    bool isEmscripten;
    bool isRunning = false;
    SDL_Window *window;
    /*
     * Frame Limiting
     */
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;
    static const auto debug = debugMode;
};


#endif //ROGUE_SDL_GAME_H
