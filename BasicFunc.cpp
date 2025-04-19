#include <iostream>

using namespace std;

const int K = 100;

void printArr(char* arr[], int m, int n) {
	for(int i = 0; i < m + 2; i++) {
		for(int j = 0; j < n + 2; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int convert(string s) {
    int sm = 0, sc;
    if(s[0] == '-') {
    	for(int i = 1; s[i] != '\0'; i++) {
        	sc = int(s[i]) - 48;
        	sm = sm * 10 + sc;
    	}
    	return -sm;
	}
    
    for(int i = 0; s[i] != '\0'; i++) {
        sc = int(s[i]) - 48;
        sm = sm * 10 + sc;
    }
    return sm;
}

int number_in_string(string s, int n) {
	string number;
	n--;
	int index = 0, count = 0, num;
	for(int i = 0;; i++) {
		if( count == n ) {
			break;
		}
		if( s[i] == ' ' ) {
			count++;
		}
		index++;
	}
	for(int i = index; s[i] != ' '; i++) {
		number += s[i];
	}
	num = convert(number);
	return num;
}

bool ToaDo ( int a, int b, int x, int y ) {
	int x1 = (a - 1) * K,
		y1 = (b - 1) * K,
		x2 = a * K - 1,
		y2 = b * K - 1;
		
	return ( x1 <= x && x <= x2 && y1 <= y && y <= y2 );
}
