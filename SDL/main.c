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

int main(int argc, char **argv){

	SDL_Window *window = NULL;

	SDL_version nb;
	SDL_VERSION(&nb);
	printf("SDL ver %d.%d.%d", nb.major,nb.minor,nb.patch);
	if(SDL_Init(SDL_INIT_VIDEO) != 0){
		SDL_Log("Error in SDL init: %s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}

	window = SDL_CreateWindow("First window in SDL",SDL_WINDOWPOS_CENTERED,
													SDL_WINDOWPOS_CENTERED,
													500,500,0);

	if(window ==NULL){
		SDL_Log("Failed window creation: %s\n",SDL_GetError());
	}

	SDL_Delay(10000);

	SDL_Quit();
	return EXIT_SUCCESS;
}
