/*
COMPILE-
cmake --build build --config Debug
RUN-
./build/Debug/pixel_lab.exe
*/

#include <SDL3/SDL.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

float window_height = 500.0f;
float window_width = 500.0f;

int counter_for_collision = 0;

// 1. Rectangle properties
float rectX = 100.0f;
float rectY = 100.0f;
const float rectWidth = 20.0f;
const float rectHeight = 20.0f;
const float speed = 250.0f; // Pixels per second
    
    //starting location of the coin
float coinX = 350.0f;
float coinY = 250.0f;
    //coin properties
const float coinSize = 5.0f;
bool coinCollected = false;


int main()
{
    // 2. Initialize SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "SDL initialization failed: "
            << SDL_GetError() << '\n';
        return 1;
    }

    // 3. Create the window and renderer
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    if (!SDL_CreateWindowAndRenderer(
        "Pixel Lab", window_width, window_height, 0,
        &window, &renderer)) {
        std::cerr << "Window creation failed: "
            << SDL_GetError() << '\n';

        SDL_Quit();
        return 1;
    }

    // 4. Game loop setup
    bool running = true;
    SDL_Event event;
    bool coinCollected = false;

    Uint64 previousTicks = SDL_GetTicks();

	std::srand(static_cast<unsigned int>(std::time(nullptr)));      //changing the coin position every time the game is run

    // 5. Main game loop
    while (running) {

        // Calculate time between frames
        Uint64 currentTicks = SDL_GetTicks();

        float deltaTime =
            (currentTicks - previousTicks) / 1000.0f;

        previousTicks = currentTicks;

        // Handle window events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        // Read keyboard input
        const bool* keys = SDL_GetKeyboardState(nullptr);

        if (keys[SDL_SCANCODE_LEFT]) {
            rectX -= speed * deltaTime;
        }

        if (keys[SDL_SCANCODE_RIGHT]) {
            rectX += speed * deltaTime;
        }

        if (keys[SDL_SCANCODE_UP]) {
            rectY -= speed * deltaTime;
        }

        if (keys[SDL_SCANCODE_DOWN]) {
            rectY += speed * deltaTime;
        }


        // Keep the rectangle inside the window

        if (rectX < 0.0f) {
            rectX = 0.0f;
        }

        if (rectY < 0.0f) {
            rectY = 0.0f;
        }

        if (rectX > window_width - rectWidth) {
            rectX = window_width - rectWidth;
        }

        if (rectY > window_height - rectHeight) {
            rectY = window_height - rectHeight;
        }


        // Clear the screen with a dark background
        SDL_SetRenderDrawColor(
            renderer, 25, 25, 35, 255);
        SDL_RenderClear(renderer);

        // Set the rectangle's color to teal
        SDL_SetRenderDrawColor(
            renderer, 50, 200, 170, 255);

        // Define the rectangle's current position
        SDL_FRect rect = {
            rectX,
            rectY,
            rectWidth,
            rectHeight
        };

        //coin's current position
        SDL_FRect coin = {
            coinX,
            coinY,
            coinSize,
            coinSize
                };

        // Draw the rectangle
        SDL_RenderFillRect(renderer, &rect);

        if (!coinCollected) {
            SDL_SetRenderDrawColor(renderer, 255, 200, 50, 255);
            SDL_RenderFillRect(renderer, &coin);
        }

        // Check whether the player overlaps the collectible
        bool touching =
            rect.x < coin.x + coin.w &&
            rect.x + rect.w > coin.x &&
            rect.y < coin.y + coin.h &&
            rect.y + rect.h > coin.y;
        
        //if (touching) {
        //    std::cout << "Collectible touched!\n";
        //}
        
        if (touching && !coinCollected) {
            counter_for_collision++;
            std::cout << "Coins: " << counter_for_collision << std::endl;


            // Calculate the maximum valid coin position
            int maxX = window_width - static_cast<int>(coinSize);
            int maxY = window_height - static_cast<int>(coinSize);

            // Choose a new random position
            if (maxX > 0 && maxY > 0) {
                coinX = static_cast<float>(std::rand() % (maxX + 1));
                coinY = static_cast<float>(std::rand() % (maxY + 1));
            }

            // Make the coin available again
            coinCollected = false;
        }

        // Display the completed frame
        SDL_RenderPresent(renderer);
    }

    // 6. Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
