#include "Game.hpp"

Game *game = nullptr;

//void game_loop()
//{
//    input();
//    move();
//    render();
//}

int main()
{
    auto isEmscripten = EMSCRIPTEN_FLAG;
    std::cout << "Test" << std::endl;
    std::cout << isEmscripten << std::endl;

//    game = new Game();

//    emscripten_set_main_loop(game_loop, 0, 0);

    return 0;
} 