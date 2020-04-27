#include "Game.hpp"

Game *game = nullptr;

void game_loop()
{
    std::cout << "Game loop inited!" << std::endl;
//    input();
//    move();
//    render();
}

int main()
{
//    auto emsTemp = EMSCRIPTEN_FLAG;
//    bool isEmscripten = emsTemp == 0;

    game = new Game();

    #ifdef EMSCRIPTEN_IS_USED
        std::cout << "Is emscripten" << std::endl;
        emscripten_set_main_loop(game_loop, 0, 0);
    #else
        std::cout << "Is not emscripten" << std::endl;
        game_loop();
    #endif //EMSCRIPTEN_IS_USED

    return 1;
} 