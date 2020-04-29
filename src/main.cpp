#include "Game.hpp"

Game *game = nullptr;

void game_loop()
{
    while (game->running()) {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->quit();
}

void wasm_game_loop()
{
    if (game->running()) {
        game->handleEvents();
        game->update();
        game->render();
    } else {
        game->quit();
        #ifdef __EMSCRIPTEN__
            emscripten_cancel_main_loop();
        #endif
    }
}

int main()
{

    game = new Game();
    game->init("Rogue Like SDL Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    #ifdef __EMSCRIPTEN__
        std::cout << "Is emscripten" << std::endl;
        emscripten_set_main_loop(wasm_game_loop, 0, 1);
    #else
        std::cout << "Is not emscripten" << std::endl;
        game_loop();
    #endif //EMSCRIPTEN_IS_USED

    return 0;
}