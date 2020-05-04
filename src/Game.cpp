#include "Game.h"
#include "ECS/ECS.h"
#include "ECS/Components.h"
#include "Classes/Collision.h"

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

Manager manager;
auto& player(manager.addEntity());
auto& wall(manager.addEntity());
int cnt = 0;

enum groupLabels : std::size_t {
    groupWalls,
    groupPlayers,
};

Game::Game() {}

Game::~Game() {}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int fullscreen_flag = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;
    Uint32 render_flag = SDL_RENDERER_ACCELERATED;

    auto emsTemp = EMSCRIPTEN_FLAG;
    isEmscripten = emsTemp == 0;

    if((isEmscripten && SDL_Init( SDL_INIT_VIDEO ) == 0) || (!isEmscripten && SDL_Init(SDL_INIT_EVERYTHING) == 0))
    {
        std::cout << "Initialize." << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen_flag);
        if (window) {
            std::cout << "Window created!" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, render_flag);
        if (renderer)
        {
            Game::renderDrawColor();
            SDL_RenderClear(renderer);
            std::cout << "Renderer created!" << std::endl;
        }
        isRunning = true;
    } else {
        isRunning = false;
    }

    //TODO remove this after testing
    player.addComponent<TransformComponent>(0, 0, 48, 48, 3);
    player.addComponent<SpriteComponent>("resources/sprites/RoguePlayer_48x48.png", true);
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderController>("player");
    player.addGroup(groupPlayers);

    wall.addComponent<TransformComponent>(200.0f, 200.0f, 50, 50, 2);
    wall.addComponent<SpriteComponent>("resources/sprites/BirdOfAnger.png");
    wall.addComponent<ColliderController>("testWall");
    wall.addGroup(groupWalls);
}

void Game::handleEvents()
{
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;

        default:
//            std::cout << "Unhandled event: " << event.type << std::endl;
            break;
    }
}

void Game::update() {
    manager.refresh();
    manager.update();
    if (Collision::AABB(player.getComponent<ColliderController>().collider,
                        wall.getComponent<ColliderController>().collider)) {
        std::cout << "Wall!!!" << cnt++ << std::endl;
    }
}

auto &players(manager.getGroup(groupPlayers));
auto &walls(manager.getGroup(groupWalls));

void Game::render() {
    SDL_RenderClear(renderer);
//    manager.draw();
    for (auto &w : walls) {
        w->draw();
    }
    for (auto &p : players) {
        p->draw();
    }
    SDL_RenderPresent(renderer);
}

void Game::gameLoop()
{
    frameStart = SDL_GetTicks();

    handleEvents();
    update();
    render();

    frameTime = SDL_GetTicks() - frameStart;
    if (frameDelay > frameTime) {
        SDL_Delay(frameDelay - frameTime);
    }
}

void Game::quit()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game stopped." << std::endl;
}

void Game::renderDrawColor() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}
