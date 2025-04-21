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

void ChuNhatDac(SDL_Renderer* renderer, int a, int b) {
	
	int x1 = (a - 1) * K,
		y1 = (b - 1) * K,
		x2 = a * K - 1,
		y2 = b * K - 1;
	
	
	for(int i = y1; i <= y2; i++) {
		for(int j = x1; j <= x2; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
	}
}

void Tuong(SDL_Renderer* renderer, int a, int b) {
	
	int x1 = (a - 1) * K,
		y1 = (b - 1) * K,
		x2 = a * K - 1,
		y2 = b * K - 1;
	
	
	for(int i = y1; i <= y1 + 20; i++) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		for(int j = x1; j <= x1 + 3; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int j = x1 + 4; j <= x1 + 49; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		for(int j = x1 + 50; j <= x1 + 53; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int j = x1 + 54; j <= x2; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
	}
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	for(int i = y1 + 21; i <= y1 + 24; i++) {
		for(int j = x1; j <= x2; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
	}
	
	for(int i = y1 + 25; i <= y1 + 45; i++) {
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int j = x1; j <= x1 + 24; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		for(int j = x1 + 25; j <= x1 + 28; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int j = x1 + 29; j <= x1 + 74; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		for(int j = x1 + 75; j <= x1 + 78; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int j = x1 + 79; j <= x2; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
	}
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	for(int i = y1 + 46; i <= y1 + 49; i++) {
		for(int j = x1; j <= x2; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
	}
	
	for(int i = y1 + 50; i <= y1 + 70; i++) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		for(int j = x1; j <= x1 + 3; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int j = x1 + 4; j <= x1 + 49; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		for(int j = x1 + 50; j <= x1 + 53; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int j = x1 + 54; j <= x2; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
	}
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	for(int i = y1 + 71; i <= y1 + 74; i++) {
		for(int j = x1; j <= x2; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
	}
	
	for(int i = y1 + 75; i <= y1 + 95; i++) {
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int j = x1; j <= x1 + 24; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		for(int j = x1 + 25; j <= x1 + 28; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int j = x1 + 29; j <= x1 + 74; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		for(int j = x1 + 75; j <= x1 + 78; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int j = x1 + 79; j <= x2; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
	}
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	for(int i = y1 + 96; i <= y1 + 99; i++) {
		for(int j = x1; j <= x2; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
	}
}

void ChuX (SDL_Renderer* renderer, int a, int b) {
	int x1 = (a - 1) * K,
		y1 = (b - 1) * K,
		x2 = a * K - 1,
		y2 = b * K - 1;
	
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
	for(int k = -10; k <= 10; k++) {
		if(k < 0) {
			for(int i = y1, j = x1 - k; j <= x2; i++, j++) {
				SDL_RenderDrawPoint(renderer, j, i);
			}
		}
		else {
			for(int i = y1 + k, j = x1;  i <= y2; i++, j++) {
				SDL_RenderDrawPoint(renderer, j, i);
			}
		}
	}
	
	for(int k = -10; k <= 10; k++) {
		if(k < 0) {
			for(int i = y1 - k, j = x2; i <= y2; i++, j--) {
				SDL_RenderDrawPoint(renderer, j, i);
			}
		}
		else {
			for(int i = y1, j = x2 - k; j >= x1; i++, j--) {
				SDL_RenderDrawPoint(renderer, j, i);
			}
		}
	}
}

void Box (SDL_Renderer* renderer, int a, int b) {
	int x1 = (a - 1) * K,
		y1 = (b - 1) * K,
		x2 = a * K - 1,
		y2 = b * K - 1;
		
	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
	ChuNhatDac(renderer, a, b);
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	for(int k = -10; k <= 10; k++) {
		if(k < 0) {
			for(int i = y1, j = x1 - k; j <= x2; i++, j++) {
				SDL_RenderDrawPoint(renderer, j, i);
			}
		}
		else {
			for(int i = y1 + k, j = x1;  i <= y2; i++, j++) {
				SDL_RenderDrawPoint(renderer, j, i);
			}
		}
	}
	
	for(int k = -10; k <= 10; k++) {
		if(k < 0) {
			for(int i = y1 - k, j = x2; i <= y2; i++, j--) {
				SDL_RenderDrawPoint(renderer, j, i);
			}
		}
		else {
			for(int i = y1, j = x2 - k; j >= x1; i++, j--) {
				SDL_RenderDrawPoint(renderer, j, i);
			}
		}
	}
}

void refresh ( SDL_Renderer* renderer ) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	for(int i = 0; i < 600; i++) {
		for(int j = 0; j < 800; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
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








