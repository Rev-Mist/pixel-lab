#pragma once

#include <SDL3/SDL.h>

class Player
{
	float x = 100.0f;
	float y = 100.0f;

	const float width = 20.0f;
	const float height = 20.0f;

	const float speed = 250.0f;
public:

	float getX() const;
	float getY() const;
	float getWidth() const;
	float getHeight() const;

	void move(float deltaTime);

	void checkBoundaries(float windowWidth, float windowHeight);

	void render(SDL_Renderer* renderer);

};