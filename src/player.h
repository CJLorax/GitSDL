#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include <string>


class Player {

public:

	SDL_Texture *texture;
	SDL_Rect posRect;

	Player(SDL_Renderer *renderer, std::string filePath, float x, float y);

	void Update(float delta);

	void Draw(SDL_Renderer *renderer);

	~Player();

private:


};