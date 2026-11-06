/*
Build:
cmake --build build --config Debug

Run:
./build/Debug/pixel_lab.exe
*/

#include "Player.h"
#include "Coin.h"

#include <SDL3/SDL.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

float window_height = 500.0f;
float window_width = 500.0f;

int main()
{
    // Initialize SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "SDL initialization failed: "
            << SDL_GetError() << '\n';
        return 1;
    }

    // Create window and renderer
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    if (!SDL_CreateWindowAndRenderer(
        "Pixel Lab",
        window_width,
        window_height,
        0,
        &window,
        &renderer)) {

        std::cerr << "Window creation failed: "
            << SDL_GetError() << '\n';

        SDL_Quit();
        return 1;
    }

    // Create game objects
    Player player;
    Coin coin;

    // Game loop setup
    bool running = true;
    SDL_Event event;

    int counter_for_collision = 0;

    Uint64 previousTicks = SDL_GetTicks();

    std::srand(
        static_cast<unsigned int>(std::time(nullptr))
    );

    // Main game loop
    while (running) {

        // Calculate delta time
        Uint64 currentTicks = SDL_GetTicks();

        float deltaTime =
            (currentTicks - previousTicks) / 1000.0f;

        previousTicks = currentTicks;

        // Handle events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        // Player movement
        player.move(deltaTime);

        player.checkBoundaries(
            window_width,
            window_height
        );

        // Stop after collecting 10 coins
        if (counter_for_collision >= 10) {
            break;
        }

        // Clear screen
        SDL_SetRenderDrawColor(
            renderer, 25, 25, 35, 255
        );

        SDL_RenderClear(renderer);

        // Render game objects
        player.render(renderer);
        coin.render(renderer);

        // Check collision
        if (coin.isTouching(
            player.getX(),
            player.getY(),
            player.getWidth(),
            player.getHeight()
        )) {

            counter_for_collision++;

            std::cout << "Coins: "
                << counter_for_collision
                << std::endl;

            // Move coin to a new random position
            coin.respawn(window_width, window_height);
        }

        // Display frame
        SDL_RenderPresent(renderer);
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}