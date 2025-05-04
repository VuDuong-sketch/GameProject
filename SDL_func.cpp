#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <fstream>

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
	while( SDL_WaitEvent(&e) ) {
		if( e.type == SDL_KEYDOWN || e.type == SDL_QUIT || e.type == SDL_MOUSEBUTTONDOWN ) return;
	}
}

void Draw_Filled_Square (SDL_Renderer* renderer, int i, int j) {
	
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

void Draw_Wall (SDL_Renderer* renderer, int i, int j) {
	
	int x1 = (j - 1) * K,
		y1 = (i - 1) * K,
		x2 = j * K - 1,
		y2 = i * K - 1;
	
	
	for(int y = y1; y <= y1 + 20; y++) {
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int x = x1; x <= x1 + 3; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
		for(int x = x1 + 4; x <= x1 + 49; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int x = x1 + 50; x <= x1 + 53; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
		for(int x = x1 + 54; x <= x2; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	for(int y = y1 + 21; y <= y1 + 24; y++) {
		for(int x = x1; x <= x2; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}
	
	for(int y = y1 + 25; y <= y1 + 45; y++) {
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
		for(int x = x1; x <= x1 + 24; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int x = x1 + 25; x <= x1 + 28; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
		for(int x = x1 + 29; x <= x1 + 74; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int x = x1 + 75; x <= x1 + 78; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
		for(int x = x1 + 79; x <= x2; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	for(int y = y1 + 46; y <= y1 + 49; y++) {
		for(int x = x1; x <= x2; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}
	
	for(int y = y1 + 50; y <= y1 + 70; y++) {
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int x = x1; x <= x1 + 3; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
		for(int x = x1 + 4; x <= x1 + 49; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int x = x1 + 50; x <= x1 + 53; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
		for(int x = x1 + 54; x <= x2; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	for(int y = y1 + 71; y <= y1 + 74; y++) {
		for(int x = x1; x <= x2; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}
	
	for(int y = y1 + 75; y <= y1 + 95; y++) {
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
		for(int x = x1; x <= x1 + 24; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int x = x1 + 25; x <= x1 + 28; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
		for(int x = x1 + 29; x <= x1 + 74; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int x = x1 + 75; x <= x1 + 78; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
		for(int x = x1 + 79; x <= x2; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	for(int y = y1 + 96; y <= y1 + 99; y++) {
		for(int x = x1; x <= x2; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}
}

void Draw_X_Mark (SDL_Renderer* renderer, int i, int j) {
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

void Draw_Box (SDL_Renderer* renderer, int i, int j) {
	int x1 = (j - 1) * K,
		y1 = (i - 1) * K,
		x2 = j * K - 1,
		y2 = i * K - 1;
		
	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
	Draw_Filled_Square(renderer, i, j);
	
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

char* string_to_CharPointer (const string& s);

void get_text_and_rect (SDL_Renderer* renderer, int x, int y, string str_text, TTF_Font* font, SDL_Texture** texture, SDL_Rect* rect, int red, int green, int blue) {
	
	char* text = string_to_CharPointer(str_text);
	
	
    int text_width;
    int text_height;
    SDL_Surface* surface;
    SDL_Color textColor = {red, green, blue, 0};

    surface = TTF_RenderText_Solid(font, text, textColor);
    *texture = SDL_CreateTextureFromSurface(renderer, surface);
    text_width = surface->w;
    text_height = surface->h;
    SDL_FreeSurface(surface);
    rect->x = x;
    rect->y = y;
    rect->w = text_width;
    rect->h = text_height;
    
    delete[] text;
}

void Get_Text_And_Rect (SDL_Renderer* renderer, int i, int j, string str_text, TTF_Font* font, SDL_Texture** texture, SDL_Rect* rect, int red, int green, int blue) {
	
	char* text = string_to_CharPointer(str_text);
	
	
	int x = (j - 1) * K + 17,
		y = (i - 1) * K;
	
    int text_width;
    int text_height;
    SDL_Surface* surface;
    SDL_Color textColor = {red, green, blue, 0};

    surface = TTF_RenderText_Solid(font, text, textColor);
    *texture = SDL_CreateTextureFromSurface(renderer, surface);
    text_width = surface->w;
    text_height = surface->h;
    SDL_FreeSurface(surface);
    rect->x = x;
    rect->y = y;
    rect->w = text_width;
    rect->h = text_height;
    
    delete[] text;
}

string int_to_string(int n);

int string_to_int(string s);

void Draw_Number (SDL_Renderer* renderer, int i, int j, int n) {
	SDL_Texture* texture;
    SDL_Rect rect;
    
    TTF_Init();
    
    int x, y;
    
    
    TTF_Font* font = TTF_OpenFont("walgreensscriptfreeversion.ttf", 60);
    
    if( n < 10 ) {
    	x = (j - 1) * K + 34,
		y = (i - 1) * K + 24;
	}
	else {
		x = (j - 1) * K + 17,
		y = (i - 1) * K + 24;
	}
    
    get_text_and_rect(renderer, x, y, int_to_string(n), font, &texture, &rect, 255, 255, 255);
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    Draw_Filled_Square(renderer, i, j);
    
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void Draw_Number_1 (SDL_Renderer* renderer, int i, int j) {
	
	SDL_Texture* texture;
    SDL_Rect rect;
    
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("walgreensscriptfreeversion.ttf", 120);
    
    Get_Text_And_Rect(renderer, i, j, "1", font, &texture, &rect, 0, 0, 0);
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
    Draw_Filled_Square(renderer, i, j);
    
    SDL_RenderCopy(renderer, texture, NULL, &rect);
	
}

void Draw_Number_2 (SDL_Renderer* renderer, int i, int j) {
	
	SDL_Texture* texture;
    SDL_Rect rect;
    
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("walgreensscriptfreeversion.ttf", 120);
    
    Get_Text_And_Rect(renderer, i, j, "2", font, &texture, &rect, 0, 0, 0);
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
    Draw_Filled_Square(renderer, i, j);
    
    SDL_RenderCopy(renderer, texture, NULL, &rect);
	
}

void Draw_Number_3 (SDL_Renderer* renderer, int i, int j) {
	
	SDL_Texture* texture;
    SDL_Rect rect;
    
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("walgreensscriptfreeversion.ttf", 120);
    
    Get_Text_And_Rect(renderer, i, j, "3", font, &texture, &rect, 0, 0, 0);
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
    Draw_Filled_Square(renderer, i, j);
    
    SDL_RenderCopy(renderer, texture, NULL, &rect);
	
}

void Draw_Number_4 (SDL_Renderer* renderer, int i, int j) {
	
	SDL_Texture* texture;
    SDL_Rect rect;
    
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("walgreensscriptfreeversion.ttf", 120);
    
    Get_Text_And_Rect(renderer, i, j, "4", font, &texture, &rect, 0, 0, 0);
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
    Draw_Filled_Square(renderer, i, j);
    
    SDL_RenderCopy(renderer, texture, NULL, &rect);
	
}



SDL_Texture* loadTexture (const char *filename, SDL_Renderer* renderer) {

	SDL_Texture* texture = IMG_LoadTexture(renderer, filename);

	return texture;
}



void You_Win (SDL_Renderer* renderer, int steps, int level) {
	
	SDL_Texture* texture = loadTexture("youwin.jpg", renderer);
	
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    
    SDL_Rect rect;
    
    TTF_Init();
    
    TTF_Font* font;
    
    
    
    
    
    font = TTF_OpenFont("walgreensscriptfreeversion.ttf", 40);
	
    Get_Text_And_Rect(renderer, 5, 3, "The number of steps: " + int_to_string(steps), font, &texture, &rect, 255, 255, 255);
    
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    
    
    
    
    
    char* path = string_to_CharPointer("E:/GameProject/map/record" + int_to_string(level) + ".txt");
	ifstream infile(path);
    int best_score;
    infile >> best_score;
    
    font = TTF_OpenFont("walgreensscriptfreeversion.ttf", 40);
    
    if( steps < best_score ) {
    	best_score = steps;
    	ofstream outfile(path);
    	outfile << best_score;
    	
    	
    	get_text_and_rect(renderer, 17, 34, "Congratulations! You've just broken the record!", font, &texture, &rect, 0, 255, 0);
    	
    	SDL_RenderCopy(renderer, texture, NULL, &rect);
    	
    	get_text_and_rect(renderer, 267, 117, "New Record: " + int_to_string(best_score), font, &texture, &rect, 0, 255, 0);
    
    	SDL_RenderCopy(renderer, texture, NULL, &rect);
	}
	
    
    else {
    	Get_Text_And_Rect(renderer, 2, 3, "Your Best Score: " + int_to_string(best_score), font, &texture, &rect, 255, 255, 255);
    
    	SDL_RenderCopy(renderer, texture, NULL, &rect);
	}
    
    delete[] path;
    
    
    
    
    
    font = TTF_OpenFont("walgreensscriptfreeversion.ttf", 30);
    
    Get_Text_And_Rect(renderer, 6, 3, "Click on anywhere to continue!", font, &texture, &rect, 255, 255, 255);
    
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    
    
    
    
    
	SDL_RenderPresent( renderer );
    waitUntilPressed();
	
}


