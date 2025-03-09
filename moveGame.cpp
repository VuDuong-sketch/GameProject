#include <iostream>
#include <conio.h>
using namespace std;

struct coordinates{
	int x, y;
	coordinates(int b, int a){
		x = a;
		y = b;
	}
};

void printArr(char** arr){
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void Move(char& move, char**& a, coordinates& M){
	if(move == 'w'){
		if(a[M.y - 1][M.x] == char(219)){
			move = '0';
			return;
		}
		a[M.y][M.x] = ' ';
		a[M.y - 1][M.x] = 15;
		M.y--;
		return;
	}
	if(move == 'a'){
		if(a[M.y][M.x - 1] == char(219)){
			move = '0';
			return;
		}
		a[M.y][M.x] = ' ';
		a[M.y][M.x - 1] = 15;
		M.x--;
		return;
	}
	if(move == 's'){
		if(a[M.y + 1][M.x] == char(219)){
			move = '0';
			return;
		}
		a[M.y][M.x] = ' ';
		a[M.y + 1][M.x] = 15;
		M.y++;
		return;
	}
	if(move == 'd'){
		if(a[M.y][M.x + 1] == char(219)){
			move = '0';
			return;
		}
		a[M.y][M.x] = ' ';
		a[M.y][M.x + 1] = 15;
		M.x++;
		return;
	}
}

void moveGame(){
	char** arr = new char*[5];
	for(int i = 0; i < 5; i++){
		arr[i] = new char[5];
	}
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(i == 0 || i == 4 || j == 0 || j == 4) arr[i][j] = 219;
			else arr[i][j] = ' ';
		}
	}
	arr[1][1] = 15;
	coordinates M(1,1);
	printArr(arr);
	char move;
	for(;;){
		move = _getch();
		Move(move, arr, M);
		if(move == '0'){
			cout << "Game Over !" << endl;
			return;
		}
		printArr(arr);
	}
	return;
}
