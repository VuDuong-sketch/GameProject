#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

void quitSDL(SDL_Window* winow, SDL_Renderer* renderer);

void waitUntilPressed();

int main(int argc, char* argv[]){
	SDL_Window* window;
	SDL_Renderer* renderer;
	initSDL(window, renderer);
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	
	SDL_RenderDrawLine(renderer, 0, 0, 300, 300);

	SDL_RenderPresent(renderer);
	
	waitUntilPressed();
	quitSDL(window, renderer);
	return 0;
}





