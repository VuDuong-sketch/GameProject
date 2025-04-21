#include <iostream>
#include <SDL.h>
#include <cmath>
#include <vector>

using namespace std;

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilPressed();

bool ToaDo ( int a, int b, int x, int y );

char a[100][100], x[100][100];
int m, n;
SDL_Event e;
const int K = 100;

SDL_Window* window;
SDL_Renderer* renderer;

int number_in_string(string s, int n);

struct Point {
	int x, y;
	Point(int b, int a) {
		x = a;
		y = b;
	}
};

Point M(1,1);



void Move() {
	if( e.key.keysym.sym == SDLK_UP ) {
		if( a[M.y - 1][M.x] == char(219) ) {
			return;
		}
		
		if( a[M.y - 1][M.x] == char(98) ) {
			if( a[M.y - 2][M.x] == char(219) || a[M.y - 2][M.x] == char(98) ) {
				return;
			}
			a[M.y][M.x] = ' ';
			a[M.y - 2][M.x] = 98;
			a[M.y - 1][M.x] = 15;
			
			M.y--;
			return;
		}
		
		a[M.y][M.x] = ' ';
		a[M.y - 1][M.x] = 15;
		M.y--;
		return;
	}
	if( e.key.keysym.sym == SDLK_LEFT ) {
		if( a[M.y][M.x - 1] == char(219) ) {
			return;
		}
		
		if( a[M.y][M.x - 1] == char(98) ) {
			if( a[M.y][M.x - 2] == char(219) || a[M.y][M.x - 2] == char(98) ) {
				return;
			}
			a[M.y][M.x] = ' ';
			a[M.y][M.x - 2] = 98;
			a[M.y][M.x - 1] = 15;
			
			M.x--;
			return;
		}
		
		a[M.y][M.x] = ' ';
		a[M.y][M.x - 1] = 15;
		M.x--;
		return;
	}
	if( e.key.keysym.sym == SDLK_DOWN ) {
		if( a[M.y + 1][M.x] == char(219) ) {
			return;
		}
		
		if( a[M.y + 1][M.x] == char(98) ) {
			if( a[M.y + 2][M.x] == char(219) || a[M.y + 2][M.x] == char(98) ) {
				return;
			}
			a[M.y][M.x] = ' ';
			a[M.y + 2][M.x] = 98;
			a[M.y + 1][M.x] = 15;
			
			M.y++;
			return;
		}
		
		a[M.y][M.x] = ' ';
		a[M.y + 1][M.x] = 15;
		M.y++;
		return;
	}
	if( e.key.keysym.sym == SDLK_RIGHT ) {
		if( a[M.y][M.x + 1] == char(219) ) {
			return;
		}
		
		if( a[M.y][M.x + 1] == char(98) ) {
			if( a[M.y][M.x + 2] == char(219)  || a[M.y][M.x + 2] == char(98)) {
				return;
			}
			a[M.y][M.x] = ' ';
			a[M.y][M.x + 2] = 98;
			a[M.y][M.x + 1] = 15;
			
			M.x++;
			return;
		}
		
		a[M.y][M.x] = ' ';
		a[M.y][M.x + 1] = 15;
		M.x++;
		return;
	}
}

void ChuNhatDac(SDL_Renderer* renderer, int a, int b);

void Tuong(SDL_Renderer* renderer, int a, int b);

void ChuX (SDL_Renderer* renderer, int a, int b);

void Box (SDL_Renderer* renderer, int a, int b);

void refresh ( SDL_Renderer* renderer );

vector<string> Level ( int level );

void Draw_Arrow (SDL_Renderer* renderer, int i, int j);

void Draw_Pause(SDL_Renderer* renderer, int i, int j);

void Draw_Continue(SDL_Renderer* renderer, int i, int j);

void Build_Map () {
	refresh(renderer);
	
	Draw_Pause(renderer, 1, 8);
	
	
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if( a[i][j] == char(15) ) {
				SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
				ChuNhatDac(renderer, j, i);
			}
			if( a[i][j] == 'b' ) {
				Box(renderer, j, i);
			}
			if( a[i][j] == char(219) ) {
				Tuong(renderer, j, i);
			}
			if( x[i][j] == 'x' ) {
				ChuX(renderer, j, i);
			}
		}
	}
	SDL_RenderPresent(renderer);
}

void Sokoban_Game ( int level ) {
	
	
	m = 600 / K;
	n = 800 / K;
	bool win = false;
	
	for(int i = 0; i < m + 2; i++) {
		for(int j = 0; j < n + 2; j++) {
			if(i == 0 || i == m + 1 || j == 0 || j == n + 1) {
				a[i][j] = 219;
				x[i][j] = 219;
			}
			else {
				a[i][j] = ' ';
				x[i][j] = ' ';
			}
		}
	}
	
	
	vector<string> v = Level(level);
	int size = v.size();
	
	for(int iter = 0; iter < size; iter++) {
		int i, j, c;
		string line = v[iter];
		
		i = number_in_string(line, 1);
		j = number_in_string(line, 2);
		c = number_in_string(line, 3);
		
		if( c == 120 ) {
			x[i][j] = c;
			continue;
		}
		if( c == 15 ) {
			M.y = i;
			M.x = j;
		}
		a[i][j] = c;
	}
	
	Build_Map();
	
	
	while( SDL_WaitEvent(&e) ) {
		
		
		
		if( e.type == SDL_KEYDOWN );
		
		else if( e.type == SDL_QUIT ) {
			cout << "Game Over !" << endl;
			break;
		}
		
		else if( e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT ) {
			bool end = false;
			if( ToaDo(1, 8, e.button.x, e.button.y) ) {
				
				refresh(renderer);
				Draw_Arrow(renderer, 4, 4);
				Draw_Continue(renderer, 2, 4);
				SDL_RenderPresent(renderer);
				
				while( SDL_WaitEvent(&e) ) {
					if( e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT ) {
						if( ToaDo(4, 4, e.button.x, e.button.y) ) {
							end = true;
							break;
						}
						else if( ToaDo(2, 4, e.button.x, e.button.y) ){
							Build_Map();
							break;
						}
					}
					
				}
				
			}
			if( end ) {
				cout << "Game Over !" << endl;
				break;
			}
			else continue;
		}
		
		else continue;
		
		
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= n; j++) {
				if( a[i][j] != ' ' && a[i][j] != char(219) ) {
					ChuNhatDac(renderer, j, i);
				}	
			}	
		}
			
		Move();
		
		
		
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= n; j++) {
				if( a[i][j] == char(15) ) {
					SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
					ChuNhatDac(renderer, j, i);
				}
				if( a[i][j] == 'b' ) {
					Box(renderer, j, i);
				}
				if( x[i][j] == 'x' ) {
					ChuX(renderer, j, i);
				}
			}
		}
		 		
		SDL_RenderPresent(renderer);
		
		win = true;
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= n; j++) {
				if( ( a[i][j] == 'b' && x[i][j] != 'x' ) || ( a[i][j] != 'b' && x[i][j] == 'x' ) ) {
					win = false;
				}
				if( !win ) break;
			}
			if( !win ) break;
		}
		if( win ) break;
	}
	
	if( win ) cout << "You Win!" << endl;
}

void Draw_Menu () {
	refresh(renderer);
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	Draw_Continue(renderer, 2, 4);
	
	Draw_Arrow(renderer, 4, 4);
	
}

void Draw_Level_Choose () {
	refresh(renderer);
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	ChuNhatDac(renderer, 2, 2);
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	ChuNhatDac(renderer, 2, 4);
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	ChuNhatDac(renderer, 4, 2);
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	ChuNhatDac(renderer, 4, 4);
	
	Draw_Arrow (renderer, 1, 1);
}

void run () {
	
	initSDL(window, renderer);
	
	do {
		Draw_Menu();
		SDL_RenderPresent(renderer);
		
		while ( SDL_WaitEvent(&e) ) {
			//menu
			
			if( e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT ) {
				if( ToaDo(2, 4, e.button.x, e.button.y) ) {
					
					Draw_Level_Choose();
					SDL_RenderPresent(renderer);
					
					while ( SDL_WaitEvent(&e) ) {
						//chon man
						
						if( e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT ) {
							if( ToaDo(2, 2, e.button.x, e.button.y) ) {
								Sokoban_Game(1);
								
							}
							else if( ToaDo(2, 4, e.button.x, e.button.y) ) {
								Sokoban_Game(2);
								
							}
							else if( ToaDo(4, 2, e.button.x, e.button.y) ) {
								Sokoban_Game(3);
								
							}
							else if( ToaDo(4, 4, e.button.x, e.button.y) ) {
								Sokoban_Game(4);
								
							}
							
							else if( ToaDo(1, 1, e.button.x, e.button.y) ) {
								break;
							}
							
						}
						Draw_Level_Choose();
						SDL_RenderPresent(renderer);
					}
				}
				
				else if( ToaDo(4, 4, e.button.x, e.button.y) ) {
					quitSDL(window, renderer);
					return;
				}
				
				break;
				
				
			}
		}
		
	} while( true );
	
}







