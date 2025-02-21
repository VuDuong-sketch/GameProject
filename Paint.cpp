#include <SDL2/SDL.h>
#include <iostream>


using namespace std;

const int SCREEN_WIDTH = 800;

const int SCREEN_HEIGHT = 600;

const string WINDOW_TITLE = "Paint";

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer){
	
	window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void waitUntilKeyPressed(){
	SDL_Event e;
	for(;;){
		if ( SDL_WaitEvent(&e) != 0 && (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) ) return;
		SDL_Delay(100);
	}
}

int main( int argc, char* argv[] ){	
	SDL_Window* window;
	SDL_Renderer* renderer;
	initSDL(window, renderer);
	// Your drawing code here
	SDL_SetRenderDrawColor(renderer, 255, 127, 0, 0);
	for(int i = 0; i <= 600; i++){
		for(int j = 0; j <= 600; j++){
			if((i-100)*(i-100) + (j-100)*(j-100) <= 10000) SDL_RenderDrawPoint(renderer, i, j);
		}
	}
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	for(int j = 0; j <= 600; j++){
		SDL_RenderDrawPoint(renderer, 601, j);
	}
	SDL_SetRenderDrawColor(renderer, 255, 127, 0, 0);
	for(int i = 602; i <= 800; i++){
		for(int j = 0; j <= 600; j++){
			SDL_RenderDrawPoint(renderer, i, j);
		}
	}
	SDL_RenderPresent(renderer);
	// use SDL_RenderPresent(renderer) to show it
	waitUntilKeyPressed();
	quitSDL(window, renderer);
	return 0;
}
