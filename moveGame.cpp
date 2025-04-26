#include <iostream>
#include <SDL.h>
#include <cmath>
#include <vector>

using namespace std;

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilPressed();

bool ToaDo ( int a, int b, int x, int y );

char current[8][10], x[8][10];
int m, n;
SDL_Event e;
const int K = 100;
bool new_status = true;

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
		if( current[M.y - 1][M.x] == char(219) ) {
			new_status = false;
			return;
		}
		
		if( current[M.y - 1][M.x] == char(98) ) {
			if( current[M.y - 2][M.x] == char(219) || current[M.y - 2][M.x] == char(98) ) {
				new_status = false;
				return;
			}
			current[M.y][M.x] = ' ';
			current[M.y - 2][M.x] = 98;
			current[M.y - 1][M.x] = 15;
			
			M.y--;
			new_status = true;
			return;
		}
		
		current[M.y][M.x] = ' ';
		current[M.y - 1][M.x] = 15;
		M.y--;
		new_status = true;
		return;
	}
	if( e.key.keysym.sym == SDLK_LEFT ) {
		if( current[M.y][M.x - 1] == char(219) ) {
			new_status = false;
			return;
		}
		
		if( current[M.y][M.x - 1] == char(98) ) {
			if( current[M.y][M.x - 2] == char(219) || current[M.y][M.x - 2] == char(98) ) {
				new_status = false;
				return;
			}
			current[M.y][M.x] = ' ';
			current[M.y][M.x - 2] = 98;
			current[M.y][M.x - 1] = 15;
			
			M.x--;
			new_status = true;
			return;
		}
		
		current[M.y][M.x] = ' ';
		current[M.y][M.x - 1] = 15;
		M.x--;
		new_status = true;
		return;
	}
	if( e.key.keysym.sym == SDLK_DOWN ) {
		if( current[M.y + 1][M.x] == char(219) ) {
			new_status = false;
			return;
		}
		
		if( current[M.y + 1][M.x] == char(98) ) {
			if( current[M.y + 2][M.x] == char(219) || current[M.y + 2][M.x] == char(98) ) {
				new_status = false;
				return;
			}
			current[M.y][M.x] = ' ';
			current[M.y + 2][M.x] = 98;
			current[M.y + 1][M.x] = 15;
			
			M.y++;
			new_status = true;
			return;
		}
		
		current[M.y][M.x] = ' ';
		current[M.y + 1][M.x] = 15;
		M.y++;
		new_status = true;
		return;
	}
	if( e.key.keysym.sym == SDLK_RIGHT ) {
		if( current[M.y][M.x + 1] == char(219) ) {
			new_status = false;
			return;
		}
		
		if( current[M.y][M.x + 1] == char(98) ) {
			if( current[M.y][M.x + 2] == char(219)  || current[M.y][M.x + 2] == char(98)) {
				new_status = false;
				return;
			}
			current[M.y][M.x] = ' ';
			current[M.y][M.x + 2] = 98;
			current[M.y][M.x + 1] = 15;
			
			M.x++;
			new_status = true;
			return;
		}
		
		current[M.y][M.x] = ' ';
		current[M.y][M.x + 1] = 15;
		M.x++;
		new_status = true;
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
			if( current[i][j] == char(15) ) {
				SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
				ChuNhatDac(renderer, j, i);
			}
			if( current[i][j] == 'b' ) {
				Box(renderer, j, i);
			}
			if( current[i][j] == char(219) ) {
				Tuong(renderer, j, i);
			}
			if( x[i][j] == 'x' ) {
				ChuX(renderer, j, i);
			}
		}
	}
	SDL_RenderPresent(renderer);
}

void UpDate_New_Status(vector<int**>& status) {
	int** New_Status = new int*[8];
	for(int i = 0; i < 8; i++) {
		New_Status[i] = new int[10];
	}
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 10; j++) {
			New_Status[i][j] = current[i][j];
		}
	}
	status.push_back(New_Status);
}

void Delete_Dynamic_Array(int** ptr);

void Delete_Current_Status(vector<int**>& status) {
	int Current_Index = status.size() - 1;
	
	Delete_Dynamic_Array(status[Current_Index]);
	
	status.pop_back();
}

void Release(vector<int**>& status);

void Undo(vector<int**>& status) {
	int** Prev_Status = status[status.size() - 2];
	
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 10; j++) {
			current[i][j] = Prev_Status[i][j];
		}
	}
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 10; j++) {
			if( current[i][j] == char(15) ) {
				M.y = i;
				M.x = j;
				return;
			}
		}
	}
}

void Sokoban_Game ( int level ) {
	
	
	m = 600 / K;
	n = 800 / K;
	bool win = false;
	
	for(int i = 0; i < m + 2; i++) {
		for(int j = 0; j < n + 2; j++) {
			if(i == 0 || i == m + 1 || j == 0 || j == n + 1) {
				current[i][j] = 219;
				x[i][j] = 219;
			}
			else {
				current[i][j] = ' ';
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
		current[i][j] = c;
	}
	
	vector<int**> status;
	
	UpDate_New_Status(status);
	
	
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
				if( current[i][j] != ' ' && current[i][j] != char(219) ) {
					ChuNhatDac(renderer, j, i);
				}	
			}	
		}
		
		if( e.key.keysym.sym == SDLK_z ) {
			
			if( status.size() == 1 ) continue;
			
			Undo(status);
			
			Delete_Current_Status(status);
			
			for(int i = 1; i <= m; i++) {
				for(int j = 1; j <= n; j++) {
					if( current[i][j] == char(15) ) {
						SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
						ChuNhatDac(renderer, j, i);
					}
					if( current[i][j] == 'b' ) {
						Box(renderer, j, i);
					}
					if( x[i][j] == 'x' ) {
						ChuX(renderer, j, i);
					}
				}
			}
		 		
			SDL_RenderPresent(renderer);
			
			continue;
		}
			
		Move();
		
		if( !new_status ) continue;
		
		UpDate_New_Status(status);
		
		
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= n; j++) {
				if( current[i][j] == char(15) ) {
					SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
					ChuNhatDac(renderer, j, i);
				}
				if( current[i][j] == 'b' ) {
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
				if( ( current[i][j] == 'b' && x[i][j] != 'x' ) || ( current[i][j] != 'b' && x[i][j] == 'x' ) ) {
					win = false;
				}
				if( !win ) break;
			}
			if( !win ) break;
		}
		if( win ) break;
	}
	
	if( win ) cout << "You Win!" << endl;
	Release(status);
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







