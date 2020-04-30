#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* player;

SDL_Renderer* Game::renderer = nullptr;

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
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderClear(renderer);
            std::cout << "Renderer created!" << std::endl;
        }
        isRunning = true;
    } else {
        isRunning = false;
    }
    player = new GameObject("resources/sprites/BirdOfAnger.png", 0, 0);
}

void Game::handleEvents()
{
    SDL_Event event;
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
    player->Update();
}

void Game::render() {
    SDL_RenderClear(renderer);
    player->Render();
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
