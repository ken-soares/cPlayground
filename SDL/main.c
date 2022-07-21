/*
      ____        ___  __                 _  __
     /  _/______ / _ \/ /  ___  ___  ___ | |/_/
    _/ // __/ -_) ___/ _ \/ _ \/ _ \/ -_)>  <
   /___/\__/\__/_/  /_//_/\___/_//_/\__/_/|_|
   Author: Kenneth Soares
   Website: ken-soares.github.io
   File: SDL/main.c
*/


#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

void SDL_ExitWithError(const char *message);

int main(int argc, char **argv){

	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	SDL_version nb;
	SDL_VERSION(&nb);
	printf("SDL ver %d.%d.%d", nb.major,nb.minor,nb.patch);
	if(SDL_Init(SDL_INIT_VIDEO) != 0){
		SDL_ExitWithError("Couldn't initialize video");
	}

	window = SDL_CreateWindow("First window in SDL",SDL_WINDOWPOS_CENTERED,
													SDL_WINDOWPOS_CENTERED,
													500,500,0);

	if(window ==NULL){
		SDL_ExitWithError("Couldn't create window");
	}


	renderer = SDL_CreateRenderer(window,-1, SDL_RENDERER_SOFTWARE);

	if(renderer == NULL){
		SDL_ExitWithError("Couldn't create renderer");
	}


	if(SDL_SetRenderDrawColor(renderer,255,0,0, SDL_ALPHA_OPAQUE) != 0)
		SDL_ExitWithError("couldn't change render color");

	if(SDL_RenderDrawPoint(renderer,250,250)!= 0)
		SDL_ExitWithError("impossible de dessiner un point");

	if(SDL_SetRenderDrawColor(renderer,0,255,0, SDL_ALPHA_OPAQUE) != 0)
		SDL_ExitWithError("couldn't change render color");

	if(SDL_RenderDrawLine(renderer,0,0,200,200)!= 0)
		SDL_ExitWithError("impossible de dessiner une ligne");


	SDL_Rect rectangle;
	rectangle.x = 300;
	rectangle.y = 300;
	rectangle.w = 100;
	rectangle.h = 100;

	if(SDL_SetRenderDrawColor(renderer,0,0,255, SDL_ALPHA_OPAQUE) != 0)
		SDL_ExitWithError("couldn't change render color");

	if(SDL_RenderFillRect(renderer,&rectangle)!= 0)
		SDL_ExitWithError("impossible de dessiner un rectangle");

	SDL_RenderPresent(renderer);
	SDL_Delay(5000);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}

void SDL_ExitWithError(const char *message){
	SDL_Log("Error:%s > %s\n", message, SDL_GetError());
	SDL_Quit();
	exit(EXIT_FAILURE);
}
