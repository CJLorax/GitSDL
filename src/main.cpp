#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_net.h>

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>


#include "player.h"

#if defined (_WIN32) ||  (_WIN64)
#include <direct.h>
#define getcwd _getcwd
#endif

#if defined (__linux__)
#include <unistd.h>
#endif

using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

int main(int argc, char ** argv)
{

//File paths for Windows, Mac, and Linux
#if defined (_WIN32) ||  (_WIN64)
	
	cout << "This is Windows" << endl;

	string s_cwd(getcwd(NULL, 0));

	string s_cwd_images = s_cwd + "\\images\\";

#endif

#if defined (__APPLE__)

	cout << "This is Apple" << endl;

	string s_cwd(getcwd(NULL, 0));

	cout << s_cwd << endl;

#endif

#if defined (__linux__)

	cout << "This is Linux" << endl;

	string s_cwd(getcwd(NULL, 0));

	string s_cwd_images = s_cwd + "/images/";

#endif

	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The renderer we'll be using
	SDL_Renderer *renderer = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize all the SDL includes - SDL, images, mixer, ttf, net
	SDL_Init(SDL_INIT_EVERYTHING);

	//Create window
	window = SDL_CreateWindow("SDL Window",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN);

	//Create Renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	//Create Player 1
	Player player1 = Player(renderer, s_cwd_images + "player.png", 300.0f, 300.0f);

	while (1) {
		SDL_Event e;
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				break;
			}
		}

		SDL_RenderClear(renderer);
		
		//Draw player 1
		player1.Draw(renderer);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();


	return 0;
}