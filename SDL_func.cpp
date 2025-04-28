#include <iostream>
#include <SDL.h>

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char* WINDOW_TITLE = "Hello World!";
const int K = 100;

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer) {
	window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer) {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void waitUntilPressed() {
	SDL_Event e;
	while( true ) {
		if( SDL_WaitEvent(&e) != 0 && 
		( e.type == SDL_KEYDOWN || e.type == SDL_QUIT ) ) return;
	}
}

void ChuNhatDac(SDL_Renderer* renderer, int i, int j) {
	
	int x1 = (j - 1) * K,
		y1 = (i - 1) * K,
		x2 = j * K - 1,
		y2 = i * K - 1;
	
	
	for(int y = y1; y <= y2; y++) {
		for(int x = x1; x <= x2; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}
}

void Tuong(SDL_Renderer* renderer, int i, int j) {
	
	int x1 = (j - 1) * K,
		y1 = (i - 1) * K,
		x2 = j * K - 1,
		y2 = i * K - 1;
	
	
	for(int y = y1; y <= y1 + 20; y++) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		for(int x = x1; x <= x1 + 3; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int x = x1 + 4; x <= x1 + 49; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		for(int x = x1 + 50; x <= x1 + 53; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int x = x1 + 54; x <= x2; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	for(int y = y1 + 21; y <= y1 + 24; y++) {
		for(int x = x1; x <= x2; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}
	
	for(int y = y1 + 25; y <= y1 + 45; y++) {
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int x = x1; x <= x1 + 24; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		for(int x = x1 + 25; x <= x1 + 28; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int x = x1 + 29; x <= x1 + 74; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		for(int x = x1 + 75; x <= x1 + 78; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int x = x1 + 79; x <= x2; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	for(int y = y1 + 46; y <= y1 + 49; y++) {
		for(int x = x1; x <= x2; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}
	
	for(int y = y1 + 50; y <= y1 + 70; y++) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		for(int x = x1; x <= x1 + 3; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int x = x1 + 4; x <= x1 + 49; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		for(int x = x1 + 50; x <= x1 + 53; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int x = x1 + 54; x <= x2; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	for(int y = y1 + 71; y <= y1 + 74; y++) {
		for(int x = x1; x <= x2; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}
	
	for(int y = y1 + 75; y <= y1 + 95; y++) {
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int x = x1; x <= x1 + 24; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		for(int x = x1 + 25; x <= x1 + 28; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int x = x1 + 29; x <= x1 + 74; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		for(int x = x1 + 75; x <= x1 + 78; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int x = x1 + 79; x <= x2; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	for(int y = y1 + 96; y <= y1 + 99; y++) {
		for(int x = x1; x <= x2; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}
}

void ChuX (SDL_Renderer* renderer, int i, int j) {
	int x1 = (j - 1) * K,
		y1 = (i - 1) * K,
		x2 = j * K - 1,
		y2 = i * K - 1;
	
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
	for(int k = -10; k <= 10; k++) {
		if(k < 0) {
			for(int y = y1, x = x1 - k; x <= x2; y++, x++) {
				SDL_RenderDrawPoint(renderer, x, y);
			}
		}
		else {
			for(int y = y1 + k, x = x1;  y <= y2; y++, x++) {
				SDL_RenderDrawPoint(renderer, x, y);
			}
		}
	}
	
	for(int k = -10; k <= 10; k++) {
		if(k < 0) {
			for(int y = y1 - k, x = x2; y <= y2; y++, x--) {
				SDL_RenderDrawPoint(renderer, x, y);
			}
		}
		else {
			for(int y = y1, x = x2 - k; x >= x1; y++, x--) {
				SDL_RenderDrawPoint(renderer, x, y);
			}
		}
	}
}

void Box (SDL_Renderer* renderer, int i, int j) {
	int x1 = (j - 1) * K,
		y1 = (i - 1) * K,
		x2 = j * K - 1,
		y2 = i * K - 1;
		
	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
	ChuNhatDac(renderer, i, j);
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	for(int k = -10; k <= 10; k++) {
		if(k < 0) {
			for(int y = y1, x = x1 - k; x <= x2; y++, x++) {
				SDL_RenderDrawPoint(renderer, x, y);
			}
		}
		else {
			for(int y = y1 + k, x = x1;  y <= y2; y++, x++) {
				SDL_RenderDrawPoint(renderer, x, y);
			}
		}
	}
	
	for(int k = -10; k <= 10; k++) {
		if(k < 0) {
			for(int y = y1 - k, x = x2; y <= y2; y++, x--) {
				SDL_RenderDrawPoint(renderer, x, y);
			}
		}
		else {
			for(int y = y1, x = x2 - k; x >= x1; y++, x--) {
				SDL_RenderDrawPoint(renderer, x, y);
			}
		}
	}
}

void refresh ( SDL_Renderer* renderer ) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	for(int y = 0; y < 600; y++) {
		for(int x = 0; x < 800; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}
}

int coor_convert_x ( int x ,int j ) {
	
	return K * (j - 1) + x - 1;
	
}

int coor_convert_y ( int y ,int i ) {
	
	return K * (i - 1) + y - 1;
	
}

void DrawPoint (SDL_Renderer* renderer, int x, int y, int i, int j) {
	SDL_RenderDrawPoint(renderer, coor_convert_x(x, j), coor_convert_y(y, i));
}

void Draw_Arrow (SDL_Renderer* renderer, int i, int j) {
	
	SDL_SetRenderDrawColor(renderer, 127, 127, 0, 0);
	for(int y = 1; y <= 100; y++) {
		for(int x = 1; x <= 100; x++) {
			DrawPoint(renderer, x, y, i, j);
		}
	}
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
	
	for(int y = 1; y <= 50; y++) {
		for(int x = 1; x <= 50; x++) {
			if( x + y >= 76 ) {
				DrawPoint(renderer, x, y, i, j);
			}
		}
	}
	for(int y = 51; y <= 100; y++) {
		for(int x = 1; x <= 50; x++) {
			if( y - x <= 25 ) {
				DrawPoint(renderer, x, y, i, j);
			}
		}
	}
	for(int y = 38; y <= 63; y++) {
		for(int x = 51; x <= 75; x++) {
			DrawPoint(renderer, x, y, i, j);
		}
	}
	
}

void Draw_Pause(SDL_Renderer* renderer, int i, int j) {
	SDL_SetRenderDrawColor(renderer, 127, 127, 0, 0);
	for(int y = 1; y <= 100; y++) {
		for(int x = 1; x <= 100; x++) {
			DrawPoint(renderer, x, y, i, j);
		}
	}
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
	
	for(int y = 26; y <= 75; y++) {
		DrawPoint(renderer, 38, y, i, j);
		DrawPoint(renderer, 63, y, i, j);
	}
}

void Draw_Continue(SDL_Renderer* renderer, int i, int j) {
	SDL_SetRenderDrawColor(renderer, 127, 127, 0, 0);
	for(int y = 1; y <= 100; y++) {
		for(int x = 1; x <= 100; x++) {
			DrawPoint(renderer, x, y, i, j);
		}
	}
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
	
	for(int y = 26; y <= 75; y++) {
		for(int x = 38; x <= 62; x++) {
			if( x - y <= 12 && x + y <= 113 ) {
				DrawPoint(renderer, x, y, i, j);
			}
		}
	}
	
}








