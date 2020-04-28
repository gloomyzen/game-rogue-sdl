#include "Game.hpp"

Game *game = nullptr;

void game_loop()
{
    while (game->running()) {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();
}

void wasm_game_loop()
{
    std::cout << game->running() << std::endl;
    if (game->running()) {
        game->handleEvents();
        game->update();
        game->render();
    } else {
        game->clean();
    }
}

int main()
{

    game = new Game();
    game->init("Rogue Like SDL Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    #ifdef EMSCRIPTEN_IS_USED
        std::cout << "Is emscripten" << std::endl;
        emscripten_set_main_loop(wasm_game_loop, 0, 0);
    #else
        std::cout << "Is not emscripten" << std::endl;
        game_loop();
    #endif //EMSCRIPTEN_IS_USED

    return 0;
} 