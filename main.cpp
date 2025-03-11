#include <iostream>
#include <SDL.h>
using namespace std;

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilPressed();

void renderTexture(SDL_Texture *texture, int x, int y, SDL_Renderer* renderer);

SDL_Texture* loadTexture(const char* filename, SDL_Renderer* renderer);

void move();

int main(int argc, char* argv[]){
	char c; cin >> c;
	if(c != 'y') return 0;
	cout << "Hello World!";
	
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Renderer* renderer1;

	initSDL(window, renderer);
    
    bool quit = false;
    SDL_Event event;
	while (!quit) {
        //Handle events on queue
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) quit = true;
        }

        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

        if (currentKeyStates[SDL_SCANCODE_UP] ){
        	SDL_Texture* background = IMG_LoadTexture(renderer, "bikiniBottom.jpg");
    		SDL_RenderCopy( renderer, background, NULL, NULL);
	
    		SDL_RenderPresent ( renderer );
    		waitUntilPressed();
		}
        	
        if (currentKeyStates[SDL_SCANCODE_DOWN] ){
        	SDL_Texture* spongeBob = IMG_LoadTexture(renderer, "spongeBob.png");
    		renderTexture(spongeBob, 200, 200, renderer);

    		SDL_RenderPresent ( renderer );
    		waitUntilPressed();
		}
        if (currentKeyStates[SDL_SCANCODE_LEFT] ) break;
        if (currentKeyStates[SDL_SCANCODE_RIGHT] ) break;
    }
    

	
	quitSDL(window, renderer);
	return 0;
}







