#pragma once

#include <SDL3/SDL.h>

class Coin
{
	const float size = 5.0f;
	float x = 350.0f;
	float y = 250.0f;
public:
	void render(SDL_Renderer* renderer);
	void respawn(float windowWidth, float windowHeight);
	bool isTouching(
		float playerX,
		float playerY,
		float playerWidth,
		float playerHeight
	);
};