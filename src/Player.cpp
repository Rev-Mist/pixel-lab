#include "Player.h"
#include <SDL3/SDL.h>

// Player movement
void Player::move(float deltaTime)
{
    const bool* keys = SDL_GetKeyboardState(nullptr);

    if (keys[SDL_SCANCODE_LEFT]) {
        x -= speed * deltaTime;
    }

    if (keys[SDL_SCANCODE_RIGHT]) {
        x += speed * deltaTime;
    }

    if (keys[SDL_SCANCODE_UP]) {
        y -= speed * deltaTime;
    }

    if (keys[SDL_SCANCODE_DOWN]) {
        y += speed * deltaTime;
    }
}

// Getter functions
float Player::getX() const {
    return x;
}

float Player::getY() const {
    return y;
}

float Player::getWidth() const {
    return width;
}

float Player::getHeight() const {
    return height;
}

void Player::checkBoundaries(float windowWidth, float windowHeight)
{
    if (x < 0.0f) {
        x = 0.0f;
    }

    if (y < 0.0f) {
        y = 0.0f;
    }

    if (x > windowWidth - width) {
        x = windowWidth - width;
    }

    if (y > windowHeight - height) {
        y = windowHeight - height;
    }
}

void Player::render(SDL_Renderer* renderer)
{
    // Set the player's color to teal
    SDL_SetRenderDrawColor(renderer, 50, 200, 170, 255);

    // Define the player's rectangle
    SDL_FRect rect = {
        x,
        y,
        width,
        height
    };

    // Draw the player
    SDL_RenderFillRect(renderer, &rect);
}