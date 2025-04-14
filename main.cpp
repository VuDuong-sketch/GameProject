#include <iostream>
#include <SDL.h>

using namespace std;



void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilPressed();

void Sokoban_Game( const string& path, SDL_Window* window, SDL_Renderer* renderer );

void run();

int main(int argc, char* argv[]) {
	
	run();
	
	return 0;
}

