#include "Coin.h"
#include <cstdlib>

void Coin::render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 200, 50, 255);

    SDL_FRect coin = {
        x,
        y,
        size,
        size
    };

    SDL_RenderFillRect(renderer, &coin);
}

void Coin::respawn(float windowWidth, float windowHeight)
{
    int maxX = static_cast<int>(windowWidth - size);
    int maxY = static_cast<int>(windowHeight - size);

    if (maxX > 0 && maxY > 0) {
        x = static_cast<float>(std::rand() % (maxX + 1));
        y = static_cast<float>(std::rand() % (maxY + 1));
    }
}

bool Coin::isTouching(
    float playerX,
    float playerY,
    float playerWidth,
    float playerHeight)
{
    return (
        playerX < x + size &&
        playerX + playerWidth > x &&
        playerY < y + size &&
        playerY + playerHeight > y
        );
}