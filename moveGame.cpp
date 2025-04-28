#include <iostream>
#include <SDL.h>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilPressed();




char current[8][10], x[8][10];
int m, n;
SDL_Event e;
const int K = 100;
bool new_status = true;

SDL_Window* window;
SDL_Renderer* renderer;

int number_in_string(string s, int n);

void DrawPoint (SDL_Renderer* renderer, int x, int y, int i, int j);

bool Click ( int i, int j, int x, int y );

struct My_Character {
	int i, j;
	
	bool left_horn(int x, int y) {
		return ( y <= 3 * x - 50 && y >= x - 10 && y <= -x + 50 );
	}
	
	bool right_horn(int x, int y) {
		return ( y >= -x + 90 && y <= x - 50 && y <= -3 * x + 250 );
	}
	
	bool left_eye(int x, int y) {
		return ( 2 * y >= x + 45 && x >= 35 && 2 * y <= -x + 135 );
	}
	
	bool right_eye(int x, int y) {
		return ( 2 * y <= x + 35 && x <= 65 && 2 * y >= -x + 145 );
	}
	
	void Draw_Character() {
		SDL_SetRenderDrawColor(renderer, 127, 0, 255, 0);
	
		for(int y = 1; y <= 100; y++) {
			for(int x = 1; x <= 100; x++) {
				if( pow(double(x) - 50.5, 2) + pow(double(y) - 50.5, 2) <= 30 * 30 ) {
					DrawPoint(renderer, x, y, i, j);
				}
			}
		}
	
		for(int y = 10; y <= 25; y++) {
			for(int x = 20; x <= 30; x++) {
				if( left_horn(x, y) ) {
					DrawPoint(renderer, x, y, i, j);
				}
			}
		}
	
		for(int y = 10; y <= 25; y++) {
			for(int x = 70; x <= 80; x++) {
				if( right_horn(x, y) ) {
					DrawPoint(renderer, x, y, i, j);
				}
			}
		}
		
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		for(int y = 40; y <= 50; y++) {
			for(int x = 35; x <= 45; x++) {
				if( left_eye(x, y) ) {
					DrawPoint(renderer, x, y, i, j);
				}
			}
		}
		
		for(int y = 40; y <= 50; y++) {
			for(int x = 55; x <= 65; x++) {
				if( right_eye(x, y) ) {
					DrawPoint(renderer, x, y, i, j);
				}
			}
		}
		
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		DrawPoint(renderer, 38, 45, i, j);
		DrawPoint(renderer, 38 + 1, 45, i, j);
		DrawPoint(renderer, 38 - 1, 45, i, j);
		DrawPoint(renderer, 38, 45 + 1, i, j);
		DrawPoint(renderer, 38, 45 - 1, i, j);
		
		DrawPoint(renderer, 62, 45, i, j);
		DrawPoint(renderer, 62 + 1, 45, i, j);
		DrawPoint(renderer, 62 - 1, 45, i, j);
		DrawPoint(renderer, 62, 45 + 1, i, j);
		DrawPoint(renderer, 62, 45 - 1, i, j);
			
	}
};

My_Character M;



void Move() {
	if( e.key.keysym.sym == SDLK_UP ) {
		if( current[M.i - 1][M.j] == char(219) ) {
			new_status = false;
			return;
		}
		
		if( current[M.i - 1][M.j] == char(98) ) {
			if( current[M.i - 2][M.j] == char(219) || current[M.i - 2][M.j] == char(98) ) {
				new_status = false;
				return;
			}
			current[M.i][M.j] = ' ';
			current[M.i - 2][M.j] = 98;
			current[M.i - 1][M.j] = 15;
			
			M.i--;
			new_status = true;
			return;
		}
		
		current[M.i][M.j] = ' ';
		current[M.i - 1][M.j] = 15;
		M.i--;
		new_status = true;
		return;
	}
	if( e.key.keysym.sym == SDLK_LEFT ) {
		if( current[M.i][M.j - 1] == char(219) ) {
			new_status = false;
			return;
		}
		
		if( current[M.i][M.j - 1] == char(98) ) {
			if( current[M.i][M.j - 2] == char(219) || current[M.i][M.j - 2] == char(98) ) {
				new_status = false;
				return;
			}
			current[M.i][M.j] = ' ';
			current[M.i][M.j - 2] = 98;
			current[M.i][M.j - 1] = 15;
			
			M.j--;
			new_status = true;
			return;
		}
		
		current[M.i][M.j] = ' ';
		current[M.i][M.j - 1] = 15;
		M.j--;
		new_status = true;
		return;
	}
	if( e.key.keysym.sym == SDLK_DOWN ) {
		if( current[M.i + 1][M.j] == char(219) ) {
			new_status = false;
			return;
		}
		
		if( current[M.i + 1][M.j] == char(98) ) {
			if( current[M.i + 2][M.j] == char(219) || current[M.i + 2][M.j] == char(98) ) {
				new_status = false;
				return;
			}
			current[M.i][M.j] = ' ';
			current[M.i + 2][M.j] = 98;
			current[M.i + 1][M.j] = 15;
			
			M.i++;
			new_status = true;
			return;
		}
		
		current[M.i][M.j] = ' ';
		current[M.i + 1][M.j] = 15;
		M.i++;
		new_status = true;
		return;
	}
	if( e.key.keysym.sym == SDLK_RIGHT ) {
		if( current[M.i][M.j + 1] == char(219) ) {
			new_status = false;
			return;
		}
		
		if( current[M.i][M.j + 1] == char(98) ) {
			if( current[M.i][M.j + 2] == char(219)  || current[M.i][M.j + 2] == char(98)) {
				new_status = false;
				return;
			}
			current[M.i][M.j] = ' ';
			current[M.i][M.j + 2] = 98;
			current[M.i][M.j + 1] = 15;
			
			M.j++;
			new_status = true;
			return;
		}
		
		current[M.i][M.j] = ' ';
		current[M.i][M.j + 1] = 15;
		M.j++;
		new_status = true;
		return;
	}
}

void ChuNhatDac(SDL_Renderer* renderer, int i, int j);

void Tuong(SDL_Renderer* renderer, int i, int j);

void ChuX (SDL_Renderer* renderer, int i, int j);

void Box (SDL_Renderer* renderer, int i, int j);

void refresh ( SDL_Renderer* renderer );

void Draw_Arrow (SDL_Renderer* renderer, int i, int j);

void Draw_Pause(SDL_Renderer* renderer, int i, int j);

void Draw_Continue(SDL_Renderer* renderer, int i, int j);

void Build_Map () {
	refresh(renderer);
	
	Draw_Pause(renderer, 1, 8);
	
	
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if( current[i][j] == char(15) ) {
				M.Draw_Character();
			}
			if( current[i][j] == 'b' ) {
				Box(renderer, i, j);
			}
			if( current[i][j] == char(219) ) {
				Tuong(renderer, i, j);
			}
			if( x[i][j] == 'x' ) {
				ChuX(renderer, i, j);
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
				M.i = i;
				M.j = j;
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
	
	
	
	
	string path = "E:/GameProject/map/level";
	path += char(level + 48);
	path += ".txt";
	ifstream file(path);
		
	while(true) {
		int i, j, c;
		string line;
		getline(file, line);
		
		i = number_in_string(line, 1);
		j = number_in_string(line, 2);
		c = number_in_string(line, 3);
		
		if( c == -1 ) break;
		if( c == 120 ) {
			x[i][j] = c;
			continue;
		}
		if( c == 15 ) {
			M.i = i;
			M.j = j;
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
			if( Click(1, 8, e.button.x, e.button.y) ) {
				
				refresh(renderer);
				Draw_Arrow(renderer, 4, 4);
				Draw_Continue(renderer, 2, 4);
				SDL_RenderPresent(renderer);
				
				while( SDL_WaitEvent(&e) ) {
					if( e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT ) {
						if( Click(4, 4, e.button.x, e.button.y) ) {
							end = true;
							break;
						}
						else if( Click(2, 4, e.button.x, e.button.y) ){
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
					ChuNhatDac(renderer, i, j);
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
						M.Draw_Character();
					}
					if( current[i][j] == 'b' ) {
						Box(renderer, i, j);
					}
					if( x[i][j] == 'x' ) {
						ChuX(renderer, i, j);
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
					M.Draw_Character();
				}
				if( current[i][j] == 'b' ) {
					Box(renderer, i, j);
				}
				if( x[i][j] == 'x' ) {
					ChuX(renderer, i, j);
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
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
	ChuNhatDac(renderer, 3, 3);
	
	ChuNhatDac(renderer, 3, 5);
	
	ChuNhatDac(renderer, 5, 3);
	
	ChuNhatDac(renderer, 5, 5);
	
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
				if( Click(2, 4, e.button.x, e.button.y) ) {
					
					Draw_Level_Choose();
					SDL_RenderPresent(renderer);
					
					while ( SDL_WaitEvent(&e) ) {
						//chon man
						
						if( e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT ) {
							if( Click(3, 3, e.button.x, e.button.y) ) {
								Sokoban_Game(1);
								
							}
							else if( Click(3, 5, e.button.x, e.button.y) ) {
								Sokoban_Game(2);
								
							}
							else if( Click(5, 3, e.button.x, e.button.y) ) {
								Sokoban_Game(3);
								
							}
							else if( Click(5, 5, e.button.x, e.button.y) ) {
								Sokoban_Game(4);
								
							}
							
							else if( Click(1, 1, e.button.x, e.button.y) ) {
								break;
							}
							
						}
						Draw_Level_Choose();
						SDL_RenderPresent(renderer);
					}
				}
				
				else if( Click(4, 4, e.button.x, e.button.y) ) {
					quitSDL(window, renderer);
					return;
				}
				
				break;
				
				
			}
		}
		
	} while( true );
	
}







